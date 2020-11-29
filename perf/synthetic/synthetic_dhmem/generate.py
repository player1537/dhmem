#!/usr/bin/env python3.6
# vim: sta:et:sw=4:ts=4:sts=4:ai
"""

"""

from dataclasses import dataclass, field
from itertools import product
from textwrap import dedent
from typing import List

from jinja2 import Environment, StrictUndefined


@dataclass
class Port:
    producer: 'Task'
    consumer: 'Task'
    communication: str
    default_size: int  # size of int array

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
    default_period: int  # microseconds

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
    default_maxiter: int
    default_name: str

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
        
    @property
    def all_mpi(self) -> bool:
        return all(port.mpi for task in self.tasks for port in task.ports)
        
    @property
    def all_dhmem(self) -> bool:
        return all(port.dhmem for task in self.tasks for port in task.ports)

    def genname(self, s: str) -> str:
        return f'dhmem_{s}'

    g = genname


template_source = dedent(r"""
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
        char *s;

        {# task period #}
        {% if task.outports %}
        useconds_t exp_time =
            (s = getenv("{{ task.g('time')|upper }}"))
                ? (useconds_t)atol(s)
                : {{ task.default_period }};
        {% endif %}

        {# task iterations #}
        size_t maxiter =
            (s = getenv("{{ context.g('maxiter')|upper }}"))
                ? (size_t)atol(s)
                : {{ context.default_maxiter }};

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
        std::fprintf(stderr, "{{ task.name }}: dhmem {{ port.g('data') }}\n");
        auto &{{ port.g('data') }} = dhmem.container<dhmem_data>("{{ port.g('data') }}");
        {% endif %}
        {% endfor %}

        {# mpi data structures #}
        {% for port in task.ports %}
        {% if port.mpi %}
        std::fprintf(stderr, "{{ task.name }}: mpi {{ port.g('data') }}\n");
        auto {{ port.g('data') }} = mpi_data();
        {% endif %}
        {% endfor %}

        {# dhmem locks #}
        {% for port in task.inports %}
        {% if port.dhmem %}
        std::fprintf(stderr, "{{ task.name }}: {{ port.g('lock') }}\n");
        dhmem::scoped_lock {{ port.g('lock') }}({{ port.g('mutex') }});
        {% endif %}
        {% endfor %}

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
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
                std::fprintf(stderr, "{{ task.name }}: i = %d, first = %d, {{ port.g('sum') }} = %d\n", i, {{ port.g('data') }}.vec[0], {{ port.g('sum') }});
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

    {% if context.all_mpi %}
    void workflow(std::string &name) {
        int rank;

        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (0) {
        {% for task in tasks %}
        } else if (rank == {{ task.number }}) {
            {% if task.number == 0 %}
            dhmem::Dhmem dhmem(dhmem::force_create_only, name, 65536);
            MPI_Barrier(MPI_COMM_WORLD);
            {% else %}
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            {% endif %}

            std::fprintf(stderr, "{{ task.name }}: starting\n");
            {{ task.g('function') }}(dhmem);
        {% endfor %}
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..?\n");
        }
    }
    {% endif %}

    {% if context.all_dhmem %}
    void workflow(std::string &name) {
        std::fprintf(stderr, "workflow: start\n");

        dhmem::Dhmem dhmem(dhmem::force_create_only, name);
        std::fprintf(stderr, "workflow: created dhmem object\n");

        auto &barrier_mutex = dhmem.simple<dhmem::mutex>("barrier_mutex");
        auto &barrier_cond = dhmem.simple<dhmem::cond>("barrier_cond");
        auto &barrier_count = dhmem.simple<int>("barrier_count");
        std::fprintf(stderr, "workflow: created sync primitives\n");

        dhmem::scoped_lock barrier_lock(barrier_mutex);
        barrier_count = 0;
        std::fprintf(stderr, "workflow: created lock\n");

        {% for task in tasks %}
        if (fork() == 0) {
            {
                std::fprintf(stderr, "{{ task.name }}: forked\n");
                dhmem::scoped_lock barrier_lock(barrier_mutex);
                std::fprintf(stderr, "{{ task.name }}: acquired lock\n");
                ++barrier_count;
                barrier_cond.notify_all();

                for (;;) {
                    barrier_cond.wait(barrier_lock);
                    std::fprintf(stderr, "{{ task.name }}: waited on condition\n");
                    if (barrier_count == {{ loop.length }}) break;
                }
            }
            std::fprintf(stderr, "{{ task.name }}: start\n");
            {{ task.g('function') }}(dhmem);
            std::fprintf(stderr, "{{ task.name }}: finished\n");
            std::exit(0);
        }
        {% endfor %}

        std::fprintf(stderr, "workflow: forked children\n");
        barrier_cond.notify_all();
        std::fprintf(stderr, "workflow: notified all\n");

        for (;;) {
            std::fprintf(stderr, "workflow: waiting on cond\n");
            barrier_cond.wait(barrier_lock);
            std::fprintf(stderr, "workflow: checking count: %d/%d\n", barrier_count, {{ tasks|length }});
            if (barrier_count == {{ tasks|length }}) break;
        }

        barrier_cond.notify_all();
        barrier_lock.unlock();

        {% for task in tasks %}
        std::fprintf(stderr, "workflow: waiting on {{ loop.index }}/{{ loop.length }}\n");
        wait(NULL);
        {% endfor %}

        std::fprintf(stderr, "workflow: finished\n");
	}
    {% endif %}

    int main(int argc, char **argv) {
        char *s;
        std::string name;
        MPI_Init(&argc, &argv);

        (void)argc;
        (void)argv;

        name =
            (s = getenv("{{ context.g('name') }}"))
                ? s
                : "{{ context.default_name }}";

        workflow(name);

        return 0;
    }
""")


def main(definitions):
    context_definitions = []
    task_definitions = []
    port_definitions = []
    for definition in definitions:
        if len(definition) == 1:
            context_definitions.append(definition)
        elif len(definition) == 2:
            task_definitions.append(definition)
        elif len(definition) == 3:
            port_definitions.append(definition)
        else:
            print('oh no')

    assert len(context_definitions) <= 1, 'Expected 1 or fewer context definition, got %s' % (len(context_definitions),)
    context_definition = context_definitions[0] if len(context_definitions) == 1 else None

    tasks = []
    for task_names, options in task_definitions:
        default_period = int(options.get('period', 1000 * 1000))  # microseconds

        for task_name in task_names:
            assert task_name not in (x.name for x in tasks), f'Task {task_name} already seen'

            task = Task(
                number=len(tasks),
                name=task_name,
                ports=[],
                default_period=default_period,
            )
            tasks.append(task)

    task_lookup = { v.name: v for v in tasks }

    for prodnames, consnames, options in port_definitions:
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
    
    options = context_definition[0]
    default_maxiter = int(options.get('maxiter', 0))
    default_name = options.get('name', 'dhmem')

    context = Context(
        tasks=tasks,
        default_maxiter=default_maxiter,
        default_name=default_name,
    )

    env = Environment(
        undefined=StrictUndefined,
    )

    template = env.from_string(template_source)

    output = template.render(
        tasks=context.tasks,
        context=context,
    )
    print(output)


def cli():
    def definition(s):
        try:
            producers, consumers, options = s.split('/')
        except ValueError:
            pass
        else:
            producers = producers.split(',')
            consumers = consumers.split(',')
            options = [ x.split('=', 1) for x in options.split(',') ]
            options = { k: v for option in options for k, v in [option] }
            return producers, consumers, options

        try:
            tasks, options = s.split('/')
        except ValueError:
            pass
        else:
            tasks = tasks.split(',')
            options = [ x.split('=', 1) for x in options.split(',') ]
            options = { k: v for option in options for k, v in [option] }
            return tasks, options

        try:
            options, = s.split('/')
        except ValueError:
            pass
        else:
            options = [ x.split('=', 1) for x in options.split(',') ]
            options = { k: v for option in options for k, v in [option] }
            return (options,)

        raise argparse.ArgumentError('bad definition: %r' % (s,)) 

    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('definitions', type=definition, nargs='+')
    args = vars(parser.parse_args())

    main(**args)


if __name__ == '__main__':
    cli()


