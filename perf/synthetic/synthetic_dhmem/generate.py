#!/usr/bin/env python3.6
# vim: sta:et:sw=4:ts=4:sts=4:ai
"""

"""

from dataclasses import dataclass, field
from itertools import product
from textwrap import dedent
from typing import List

from jinja2 import Environment, StrictUndefined


@dataclass(frozen=True)
class Port:
    producer: 'Task'
    consumer: 'Task'
    communication: str

    @property
    def dhmem(self) -> bool:
        return self.communication == 'dhmem'

    @property
    def mpi(self) -> bool:
        return self.communication == 'mpi'

    @property
    def hybrid(self) -> bool:
        return self.communication == 'hybrid'

    @property
    def copyinto(self) -> bool:
        return self.communication == 'copy' or self.copyintoonly

    @property
    def copyfrom(self) -> bool:
        return self.communication == 'copy' or self.copyfromonly

    @property
    def copyintoonly(self) -> bool:
        return self.communication == 'copyinto'

    @property
    def copyfromonly(self) -> bool:
        return self.communication == 'copyfrom'

    @property
    def prodname(self) -> str:
        return self.producer.name

    @property
    def consname(self) -> str:
        return self.consumer.name

    def genname(self, suffix) -> str:
        return f'{self.prodname}_out_{self.consname}_in_{suffix}'

    g = genname


@dataclass(frozen=True)
class Task:
    number: int
    name: str
    ports: List[Port] = field(compare=False)
    default_period: int  # microseconds
    default_size: int  # size of int array

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


@dataclass(frozen=True)
class Context:
    tasks: List[Task] = field(compare=False)
    default_maxiter: int
    default_name: str
    default_print: int
    default_segment: int

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


template_source = dedent(
r"""    #include <array>
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

        {# print or not #}
        int do_print =
            (s = getenv("{{ context.g('print')|upper }}"))
                ? atoi(s)
                : {{ context.default_print }};

        {# debugging stuff #}
        {% if False %}
        {
            if (do_print) std::fprintf(stderr, "{{ task.name }}: pid=%d\n", getpid());
            int rank;
            MPI_Comm_rank(MPI_COMM_WORLD, &rank);
            if (rank == 0) {
                std::getchar();
            }
            MPI_Barrier(MPI_COMM_WORLD);
        }
        {% endif %}

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
        {% with seen = set() %}
        {% for port in task.outports %}
        {% if port.producer not in seen %}
        size_t {{ port.producer.g('size') }} = 
            (s = getenv("{{ port.producer.g('size')|upper }}"))
                ? (size_t)atol(s)
                : {{ port.producer.default_size }}UL;
        {% do seen.add(port.producer) %}
        {% endif %}
        {% endfor %}
        {% endwith %}

        {# dhmem synchronization primitives #}
        {% for port in task.ports %}
        {% if port.dhmem %}
        auto &{{ port.g('mutex') }} = dhmem.simple<dhmem::mutex>("{{ port.g('mutex') }}");
        auto &{{ port.g('cond') }} = dhmem.simple<dhmem::cond>("{{ port.g('cond') }}");
        //auto &{{ port.g('ready_mutex') }} = dhmem.simple<dhmem::mutex>("{{ port.g('ready_mutex') }}");
        //auto &{{ port.g('ready_cond') }} = dhmem.simple<dhmem::cond>("{{ port.g('ready_cond') }}");
        {% endif %}
        {% endfor %}

        {# copy data structures #}
        {% with seen = set() %}
        {% for port in task.ports %}
        {% if (task == port.producer and port.copyinto) or (task == port.consumer and port.copyfrom) %}
        {% if port.producer not in seen %}
        auto {{ port.producer.g('copy') }} = std::ref(dhmem.container<dhmem_data>("{{ port.producer.g('copy') }}"));
        {% do seen.add(port.producer) %}
        {% endif %}
        if (do_print) std::fprintf(stderr, "{{ task.name }}: copy {{ port.g('copy') }}\n");
        auto &{{ port.g('copy') }} = {{ port.producer.g('copy') }};
        {% endif %}
        {% endfor %}
        {% endwith %}

        {# dhmem data structures #}
        {% with seen = set() %}
        {% for port in task.ports %}
        {% if port.dhmem or port.hybrid or (task == port.producer and port.copyfromonly) or (task == port.consumer and port.copyintoonly) %}
        {% if port.producer not in seen %}
        auto &{{ port.producer.g('data') }} = dhmem.container<dhmem_data>("{{ port.producer.g('data') }}");
        {% do seen.add(port.producer) %}
        {% endif %}
        if (do_print) std::fprintf(stderr, "{{ task.name }}: dhmem {{ port.g('data') }}\n");
        auto &{{ port.g('data') }} = {{ port.producer.g('data') }};
        {% endif %}
        {% endfor %}
        {% endwith %}

        {# mpi data structures #}
        {% for port in task.ports %}
        {% if port.mpi or (task == port.producer and port.copyinto) or (task == port.consumer and port.copyfrom) %}
        if (do_print) std::fprintf(stderr, "{{ task.name }}: mpi {{ port.g('data') }}\n");
        auto {{ port.g('data') }} = mpi_data();
        {% endif %}
        {% endfor %}

        {# dhmem locks #}
        {% for port in task.inports %}
        {% if port.dhmem %}
        if (do_print) std::fprintf(stderr, "{{ task.name }}: {{ port.g('lock') }}\n");
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
                {{ port.g('data') }}.vec.resize({{ port.producer.g('size') }});
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
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    {{ port.g('data') }}.vec.resize(vecsize);
                    MPI_Recv({{ port.g('data') }}.vec.data(), vecsize, MPI_INT, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                {% endif %}
                {% endfor %}

                {# copy receive data #}
                {% with seen = set() %}
                {% for port in task.inports %}
                {% if port.copyfrom %}
                {% if port.producer not in seen %}
                {
                    dhmem::handle h;
                    MPI_Recv(&h, 1, MPI_LONG, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    {{ port.g('copy') }} = std::ref(dhmem.load<dhmem_data>(h));
                    {{ port.g('data') }}.vec.resize({{ port.g('copy') }}.get().vec.size());
                    std::copy({{ port.g('copy') }}.get().vec.data() + 0,
                              {{ port.g('copy') }}.get().vec.data() + {{ port.g('copy') }}.get().vec.size(),
                              {{ port.g('data') }}.vec.data());
                }
                {% do seen.add(port.producer) %}
                {% else %}
                {
                    dhmem::handle h;
                    MPI_Recv(&h, 1, MPI_LONG, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    (void)h;
                }
                {% endif %}
                {% endif %}
                {% endfor %}
                {% endwith %}

                {# hybrid receive data #}
                {% for port in task.inports %}
                {% if port.hybrid or (port.copyinto and not port.copyfrom) %}
                {
                    dhmem::handle h;
                    MPI_Recv(&h, 1, MPI_LONG, {{ port.producer.number }}, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    {{ port.g('data') }} = dhmem.load<dhmem_data>(h);
                }
                {% endif %}
                {% endfor %}

                {% for port in task.inports %}
                {
                    int *data = {{ port.g('data') }}.vec.data();
                    int {{ port.g('sum') }} = 0;
                    for (int j=0; j<{{ port.g('data') }}.vec.size(); ++j) {
                        {{ port.g('sum') }} += data[j];  // {{ port.g('data') }}.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "{{ task.name }}: i = %d, first = %d, {{ port.g('sum') }} = %d\n", i, {{ port.g('data') }}.vec[0], {{ port.g('sum') }});
                }
                {% endfor %}

                {% for port in task.inports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_mutex') }}: lock\n");
                //dhmem::scoped_lock {{ port.g('ready_lock') }}({{ port.g('ready_mutex') }});
                {% endif %}
                {% endfor %}

                {% for port in task.inports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_cond') }}: notify\n");
                //{{ port.g('ready_cond') }}.notify_one();
                {% endif %}
                {% endfor %}
            }

            // send
            {
                {% for port in task.outports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_mutex') }}: lock\n");
                //dhmem::scoped_lock {{ port.g('ready_lock') }}({{ port.g('ready_mutex') }});
                {% endif %}
                {% endfor %}

                {% with seen = set() %}
                {% for port in task.outports %}
                {% if port.producer not in seen %}
                {
                    int *data = {{ port.g('data') }}.vec.data();
                    for (int j=0; j<{{ port.g('data') }}.vec.size(); ++j) {
                        {# {{ port.g('data') }}.vec[j] #}
                        data[j]
                            = 100 * 100 * 100 * ("{{ port.prodname }}"[0] - 'a' + 1)
                            + 100 * 100 *       ("{{ port.consname }}"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                {% do seen.add(port.producer) %}
                {% endif %}
                {% endfor %}
                {% endwith %}

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
                    size_t vecsize;
                    vecsize = {{ port.g('data') }}.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                    MPI_Send({{ port.g('data') }}.vec.data(), vecsize, MPI_INT, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                }
                {% endif %}
                {% endfor %}

                {# copy send data #}
                {% with seen = set() %}
                {% for port in task.outports %}
                {% if port.copyinto %}
                {% if port.producer not in seen %}
                {
                    {{ port.g('copy') }}.get().vec.resize({{ port.g('data') }}.vec.size());
                    std::copy({{ port.g('data') }}.vec.data() + 0,
                              {{ port.g('data') }}.vec.data() + {{ port.g('data') }}.vec.size(),
                              {{ port.g('copy') }}.get().vec.data());
                    dhmem::handle h = dhmem.save({{ port.g('copy') }}.get());
                    MPI_Send(&h, 1, MPI_LONG, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                }
                {% do seen.add(port.producer) %}
                {% else %}
                {
                    dhmem::handle h = dhmem.save({{ port.g('copy') }}.get());
                    MPI_Send(&h, 1, MPI_LONG, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                }
                {% endif %}
                {% endif %}
                {% endfor %}
                {% endwith %}

                {# hybrid send data #}
                {% for port in task.outports %}
                {% if port.hybrid or (port.copyfrom and not port.copyinto) %}
                {
                    if (do_print) std::fprintf(stderr, "{{ task.name }}: send {{ port.g('data') }}\n");
                    dhmem::handle h = dhmem.save({{ port.g('data') }});
                    MPI_Send(&h, 1, MPI_LONG, {{ port.consumer.number }}, 1, MPI_COMM_WORLD);
                }
                {% endif %}
                {% endfor %}

                {% for port in task.outports %}
                {% if port.dhmem %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_cond') }}: wait\n");
                //{{ port.g('ready_cond') }}.wait({{ port.g('ready_lock') }});
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
                if (do_print) std::fprintf(stderr, "{{ task.name }}: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            {% endif %}
        }
    }
    {% endfor %}

    {# {% if context.all_mpi %} #}
    void workflow(std::string &name, size_t segment) {
        int rank;

        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (0) {
        {% for task in tasks %}
        } else if (rank == {{ task.number }}) {
            {% if task.number == 0 %}
            dhmem::Dhmem dhmem(dhmem::force_create_only, name, segment);
            MPI_Barrier(MPI_COMM_WORLD);
            {% else %}
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            {% endif %}

            //std::fprintf(stderr, "{{ task.name }}: starting\n");
            {{ task.g('function') }}(dhmem);
        {% endfor %}
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..? rank=%d expmax=%d\n", rank, {{ tasks|length }});
        }

        MPI_Barrier(MPI_COMM_WORLD);
    }
    {# {% endif %} #}

    {% if False %}
    void workflow(std::string &name, int segment) {
        //std::fprintf(stderr, "workflow: start\n");

        dhmem::Dhmem dhmem(dhmem::force_create_only, name, segment);
        //std::fprintf(stderr, "workflow: created dhmem object\n");

        auto &barrier_mutex = dhmem.simple<dhmem::mutex>("barrier_mutex");
        auto &barrier_cond = dhmem.simple<dhmem::cond>("barrier_cond");
        auto &barrier_count = dhmem.simple<int>("barrier_count");
        //std::fprintf(stderr, "workflow: created sync primitives\n");

        dhmem::scoped_lock barrier_lock(barrier_mutex);
        barrier_count = 0;
        //std::fprintf(stderr, "workflow: created lock\n");

        {% for task in tasks %}
        if (fork() == 0) {
            {
                //std::fprintf(stderr, "{{ task.name }}: forked\n");
                dhmem::scoped_lock barrier_lock(barrier_mutex);
                //std::fprintf(stderr, "{{ task.name }}: acquired lock\n");
                ++barrier_count;
                barrier_cond.notify_all();

                for (;;) {
                    barrier_cond.wait(barrier_lock);
                    //std::fprintf(stderr, "{{ task.name }}: waited on condition\n");
                    if (barrier_count == {{ loop.length }}) break;
                }
            }
            //std::fprintf(stderr, "{{ task.name }}: start\n");
            {{ task.g('function') }}(dhmem);
            //std::fprintf(stderr, "{{ task.name }}: finished\n");
            std::exit(0);
        }
        {% endfor %}

        //std::fprintf(stderr, "workflow: forked children\n");
        barrier_cond.notify_all();
        //std::fprintf(stderr, "workflow: notified all\n");

        for (;;) {
            //std::fprintf(stderr, "workflow: waiting on cond\n");
            barrier_cond.wait(barrier_lock);
            //std::fprintf(stderr, "workflow: checking count: %d/%d\n", barrier_count, {{ tasks|length }});
            if (barrier_count == {{ tasks|length }}) break;
        }

        barrier_cond.notify_all();
        barrier_lock.unlock();

        {% for task in tasks %}
        //std::fprintf(stderr, "workflow: waiting on {{ loop.index }}/{{ loop.length }}\n");
        wait(NULL);
        {% endfor %}

        //std::fprintf(stderr, "workflow: finished\n");
	}
    {% endif %}

    int main(int argc, char **argv) {
        char *s;
        std::string name;
        size_t segment;

        MPI_Init(&argc, &argv);

        (void)argc;
        (void)argv;

        name =
            (s = getenv("{{ context.g('name')|upper }}"))
                ? s
                : "{{ context.default_name }}";

        segment =
            (s = getenv("{{ context.g('segment')|upper }}"))
                ? atoi(s)
                : {{ context.default_segment }}UL;

        workflow(name, segment);

        return 0;
    }""")


# Thanks https://stackoverflow.com/a/60708339
def parse_size(size):
    import re

    units = {"B": 1, "KB": 2**10, "MB": 2**20, "GB": 2**30, "TB": 2**40}

    size = size.upper()
    if ' ' not in size:
        size = re.sub(r'([KMGT]?B)', r' \1', size)

    number, unit = [string.strip() for string in size.split()]
    return int(float(number) * units[unit])


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
    context_definition = context_definitions[0] if len(context_definitions) == 1 else ({},)

    tasks = []
    for task_names, options in task_definitions:
        default_period = int(options.get('period', 1000 * 1000))  # microseconds
        default_size = parse_size(options.get('size', '10kb')) // 4  # number of ints

        for task_name in task_names:
            assert task_name not in (x.name for x in tasks), f'Task {task_name} already seen'

            task = Task(
                number=len(tasks),
                name=task_name,
                ports=[],
                default_period=default_period,
                default_size=default_size,
            )
            tasks.append(task)

    task_lookup = { v.name: v for v in tasks }

    for prodnames, consnames, options in port_definitions:
        communication = options.get('comm', 'dhmem')  # dhmem or mpi

        for prodname, consname in product(prodnames, consnames):
            producer = task_lookup[prodname]
            consumer = task_lookup[consname]

            port = Port(
                producer=producer,
                consumer=consumer,
                communication=communication,
            )

            producer.ports.append(port)
            consumer.ports.append(port)
    
    options = context_definition[0]
    default_maxiter = int(options.get('maxiter', 0))
    default_name = options.get('name', 'dhmem')
    default_print = int(options.get('print', 1))
    default_segment = parse_size(options.get('segment', 65536))

    context = Context(
        tasks=tasks,
        default_maxiter=default_maxiter,
        default_name=default_name,
        default_print=default_print,
        default_segment=default_segment,
    )

    env = Environment(
        undefined=StrictUndefined,
        extensions=['jinja2.ext.do'],
    )
    env.globals['set'] = set

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


