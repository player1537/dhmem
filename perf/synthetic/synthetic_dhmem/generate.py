#!/usr/bin/env python3.6
# vim: sta:et:sw=4:ts=4:sts=4:ai
"""

"""

from dataclasses import dataclass, field
from itertools import product
from textwrap import dedent
from typing import List

from jinja2 import Template


@dataclass
class Port:
    producer: 'Task'
    consumer: 'Task'
    communication: str
    default_size: int = field(default=None)  # size of int array

    @property
    def dhmem(self) -> bool:
        return self.communication == 'dhmem'

    @property
    def mpi(self) -> bool:
        return self.communication == 'mpi'

    @property
    def prodname(self) -> str:
        return self.producer.name

    @property
    def consname(self) -> str:
        return self.consumer.name

    def genname(self, suffix) -> str:
        return f'{self.prodname}_out_{self.consname}_in_{suffix}'

    g = genname


@dataclass
class Task:
    number: int
    name: str
    ports: List[Port]
    default_period: int = field(default=None)  # microseconds

    @property
    def inports(self) -> List[Port]:
        inports = []
        for port in self.ports:
            if port.consname == self.name:
                inports.append(port)
        return inports

    @property
    def outports(self) -> List[Port]:
        outports = []
        for port in self.ports:
            if port.prodname == self.name:
                outports.append(port)
        return outports

    def genname(self, suffix) -> str:
        return f'{self.name}_{suffix}'

    g = genname


@dataclass
class Context:
    tasks: List[Task]

    @property
    def uses_mpi(self) -> bool:
        for task in self.tasks:
            for port in task.ports:
                if port.mpi:
                    return True
        return False

    @property
    def uses_dhmem(self) -> bool:
        for task in self.tasks:
            for port in task.ports:
                if port.dhmem:
                    return True
        return False
        


template = Template(dedent(r"""
    #include <array>
    #include <cstdio>
    #include <memory>
    #include <vector>

    #include <unistd.h>
    #include <sys/wait.h>

    #include <mpi.h>

    #include <dhmem/dhmem.h>

    struct dhmem_data {
        dhmem_data(dhmem::allocator<void> &alloc)
            : vec(alloc)
            {}
        dhmem::vector<int> vec;
    };

    struct mpi_data {
        mpi_data()
            : vec()
            {}
        std::vector<int> vec;
    };

    {% for task in tasks %}
    void {{ task.g('function') }}(dhmem::Dhmem &dhmem) {
        {# helper variable for environment variables #}
        {% if task.outports %}
        char *s;
        {% endif %}

        {# task period #}
        {% if task.outports %}
        useconds_t exp_time =
            (s = getenv("{{ task.g('time')|upper }}"))
                ? (useconds_t)atol(s)
                : {{ task.default_period }};
        {% endif %}

        {# task data size #}
        {% for port in task.outports %}
        size_t {{ port.g('size') }} = 
            (s = getenv("{{ port.g('size')|upper }}"))
                ? (size_t)atol(s)
                : {{ port.default_size }};
        {% endfor %}

        {# dhmem synchronization primitives #}
        {% for port in task.ports %}
        {% if port.dhmem %}
        auto &{{ port.g('mutex') }} = dhmem.simple<dhmem::mutex>("{{ port.g('mutex') }}");
        auto &{{ port.g('cond') }} = dhmem.simple<dhmem::cond>("{{ port.g('cond') }}");
        auto &{{ port.g('ready_mutex') }} = dhmem.simple<dhmem::mutex>("{{ port.g('ready_mutex') }}");
        auto &{{ port.g('ready_cond') }} = dhmem.simple<dhmem::cond>("{{ port.g('ready_cond') }}");
        {% endif %}
        {% endfor %}

        {# dhmem data structures #}
        {% for port in task.ports %}
        {% if port.dhmem %}
        auto &{{ port.g('data') }} = dhmem.container<dhmem_data>("{{ port.g('data') }}");
        {% endif %}
        {% endfor %}

        {# mpi data structures #}
        {% for port in task.ports %}
        {% if port.mpi %}
        auto {{ port.g('data') }} = mpi_data();
        {% endif %}
        {% endfor %}

        {# dhmem locks #}
        {% for port in task.inports %}
        {% if port.dhmem %}
        dhmem::scoped_lock {{ port.g('lock') }}({{ port.g('mutex') }});
        {% endif %}
        {% endfor %}

        for (int i=0;; ++i) {
            {% if task.outports %}
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            {% endif %}

            {% if task.outports %}
            if (i == 0) {
                {% for port in task.outports %}
                {{ port.g('data') }}.vec.resize({{ port.g('size') }});
                {% endfor %}
            }
            {% endif %}

            // receive
            {
                {% for port in task.inports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('cond') }}: wait\n");
                {{ port.g('cond') }}.wait({{ port.g('lock') }});
                {% endif %}
                {% endfor %}

                {# mpi recieve data #}
                {% for port in task.inports %}
                {% if port.mpi %}
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    {{ port.g('data') }}.vec.resize(vecsize);
                    MPI_Recv({{ port.g('data') }}.vec.data(), vecsize, MPI_INT, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                {% endif %}
                {% endfor %}

                {% for port in task.inports %}
                int {{ port.g('sum') }} = 0;
                for (int j=0; j<{{ port.g('data') }}.vec.size(); ++j) {
                    {{ port.g('sum') }} += {{ port.g('data') }}.vec[j];
                }
                std::fprintf(stderr, "{{ task.name }}: first = %d, {{ port.g('sum') }} = %d\n", {{ port.g('data') }}.vec[0], {{ port.g('sum') }});
                {% endfor %}

                {% for port in task.inports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_mutex') }}: lock\n");
                dhmem::scoped_lock {{ port.g('ready_lock') }}({{ port.g('ready_mutex') }});
                {% endif %}
                {% endfor %}

                {% for port in task.inports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_cond') }}: notify\n");
                {{ port.g('ready_cond') }}.notify_one();
                {% endif %}
                {% endfor %}
            }

            // send
            {
                {% for port in task.outports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_mutex') }}: lock\n");
                dhmem::scoped_lock {{ port.g('ready_lock') }}({{ port.g('ready_mutex') }});
                {% endif %}
                {% endfor %}

                {% for port in task.outports %}
                for (int j=0; j<{{ port.g('data') }}.vec.size(); ++j) {
                    {{ port.g('data') }}.vec[j]
                        = 100 * 100 * 100 * ("{{ port.prodname }}"[0] - 'a' + 1)
                        + 100 * 100 *       ("{{ port.consname }}"[0] - 'a' + 1)
                        + 100 * i
                        + j;
                }
                {% endfor %}

                {# dhmem notify that data is ready #}
                {% for port in task.outports %}
                {% if port.dhmem %}
                {
                    //std::fprintf(stderr, "{{ task.name }}: {{ port.g('mutex') }}: lock\n");
                    dhmem::scoped_lock lock({{ port.g('mutex') }});
                    //std::fprintf(stderr, "{{ task.name }}: {{ port.g('cond') }}: notify\n");
                    {{ port.g('cond') }}.notify_one();
                }
                {% endif %}
                {% endfor %}

                {# mpi send data #}
                {% for port in task.outports %}
                {% if port.mpi %}
                {
                    int vecsize;
                    vecsize = {{ port.g('data') }}.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                    MPI_Send({{ port.g('data') }}.vec.data(), vecsize, MPI_INT, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                }
                {% endif %}
                {% endfor %}

                {% for port in task.outports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_cond') }}: wait\n");
                {{ port.g('ready_cond') }}.wait({{ port.g('ready_lock') }});
                {% endif %}
                {% endfor %}
            }

            {% if task.outports %}
            struct timespec end;
            clock_gettime(CLOCK_MONOTONIC, &end);

            useconds_t got_time
                = (1000 * 1000 * end.tv_sec + end.tv_nsec / 1000)
                - (1000 * 1000 * start.tv_sec + start.tv_nsec / 1000);

            if (exp_time == 0) {
                // no op
            } else if (got_time > exp_time) {
                std::fprintf(stderr, "{{ task.name }}: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            {% endif %}
        }
    }
    {% endfor %}

    void workflow(void) {
        dhmem::Dhmem dhmem("foobar");

        int rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (0) {
        {% for task in tasks %}
        } else if (rank == {{ task.number }}) {
            {{ task.g('function') }}(dhmem);
        {% endfor %}
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..?\n");
        }
    }

    int main(int argc, char **argv) {
        {% if context.uses_mpi %}
        MPI_Init(&argc, &argv);
        {% endif %}

        (void)argc;
        (void)argv;

        workflow();

        return 0;
    }
"""))


def main(definitions):
    task_names = []
    for prodnames, consnames, options in definitions:
        for task_name in prodnames + consnames:
            if task_name not in task_names:
                task_names.append(task_name)

    task_names.sort()

    tasks = []
    for i, task_name in enumerate(task_names):
        task = Task(
            number=i,
            name=task_name,
            ports=[],
        )
        tasks.append(task)

    task_lookup = { v.name: v for v in tasks }
    
    ports = []
    for prodnames, consnames, options in definitions:
        default_period = int(options.get('period', 1000 * 1000))  # microseconds
        default_size = int(options.get('size', 10 * 1024))  # number of ints
        communication = options.get('comm', 'dhmem')  # dhmem or mpi
        

        for prodname, consname in product(prodnames, consnames):
            producer = task_lookup[prodname]
            consumer = task_lookup[consname]

            port = Port(
                producer=producer,
                consumer=consumer,
                default_size=default_size,
                communication=communication,
            )

            producer.ports.append(port)
            consumer.ports.append(port)

            if producer.default_period is None:
                producer.default_period = default_period
            elif producer.default_period != default_period:
                raise ValueError(f'Producer {producer.name} already has a period')

            if consumer.default_period is None:
                consumer.default_period = default_period
            elif consumer.default_period != default_period:
                raise ValueError(f'Consumer {consumer.name} already has a period')

    context = Context(
        tasks=tasks,
    )

    #print(context.tasks[0].ports[0].mpi, file=__import__('sys').stderr)
    print(template.render(tasks=context.tasks, context=context))


def cli():
    def definition(s):
        producers, consumers, options = s.split('/', 3)
        producers = producers.split(',')
        consumers = consumers.split(',')
        options = [ x.split('=', 1) for x in options.split(',') ]
        options = { k: v for option in options for k, v in [option] }
        return producers, consumers, options


    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('definitions', type=definition, nargs='+')
    args = vars(parser.parse_args())

    print(args['definitions'], file=__import__('sys').stderr)

    main(**args)


if __name__ == '__main__':
    cli()


