#!/usr/bin/env python3.6
# vim: sta:et:sw=4:ts=4:sts=4:ai
"""

"""

from dataclasses import dataclass, field
from textwrap import dedent
from typing import List

from jinja2 import Template


@dataclass
class Port:
    srcname: str
    tgtname: str
    default_size: int = field(default=1024)  # size of int array

    def genname(self, suffix) -> str:
        return f'{self.srcname}_out_{self.tgtname}_in_{suffix}'

    g = genname


@dataclass
class Task:
    name: str
    ports: List[Port]
    default_time: int = field(default=1000 * 1000)  # microseconds

    @property
    def inports(self) -> List[Port]:
        inports = []
        for port in self.ports:
            if port.tgtname == self.name:
                inports.append(port)
        return inports

    @property
    def outports(self) -> List[Port]:
        outports = []
        for port in self.ports:
            if port.srcname == self.name:
                outports.append(port)
        return outports

    def genname(self, suffix) -> str:
        return f'{self.name}_{suffix}'

    g = genname


@dataclass
class Context:
    tasks: List[Task]


template = Template(dedent(r"""
    #include <cstdio>
    #include <memory>
    #include <array>
    #include <unistd.h>
    #include <sys/wait.h>

    #include <dhmem/dhmem.h>

    struct data {
        data(dhmem::allocator<void> &alloc)
            : vec(alloc)
            {}
        dhmem::vector<int> vec;
    };

    {% for task in tasks %}
    void {{ task.g('function') }}(dhmem::Dhmem &dhmem) {
        {% if task.outports %}
        char *s;
        {% endif %}

        {% if task.outports %}
        useconds_t exp_time =
            (s = getenv("{{ task.g('time')|upper }}"))
                ? (useconds_t)atol(s)
                : {{ task.default_time }};
        {% endif %}

        {% for port in task.outports %}
        size_t {{ port.g('size') }} = 
            (s = getenv("{{ port.g('size')|upper }}"))
                ? (size_t)atol(s)
                : {{ port.default_size }};
        {% endfor %}

        {% for port in task.ports %}
        auto &{{ port.g('mutex') }} = dhmem.simple<dhmem::mutex>("{{ port.g('mutex') }}");
        auto &{{ port.g('cond') }} = dhmem.simple<dhmem::cond>("{{ port.g('cond') }}");
        auto &{{ port.g('ready_mutex') }} = dhmem.simple<dhmem::mutex>("{{ port.g('ready_mutex') }}");
        auto &{{ port.g('ready_cond') }} = dhmem.simple<dhmem::cond>("{{ port.g('ready_cond') }}");
        {% endfor %}

        {% for port in task.ports %}
        auto &{{ port.g('data') }} = dhmem.container<data>("{{ port.g('data') }}");
        {% endfor %}

        {% for port in task.inports %}
        dhmem::scoped_lock {{ port.g('lock') }}({{ port.g('mutex') }});
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

            {
                {% for port in task.inports %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('cond') }}: wait\n");
                {{ port.g('cond') }}.wait({{ port.g('lock') }});
                {% endfor %}

                {% for port in task.inports %}
                int {{ port.g('sum') }} = 0;
                for (int j=0; j<{{ port.g('data') }}.vec.size(); ++j) {
                    {{ port.g('sum') }} += {{ port.g('data') }}.vec[j];
                }
                std::fprintf(stderr, "{{ task.name }}: {{ task.name }}: first = %d, {{ port.g('sum') }} = %d\n", {{ port.g('data') }}.vec[0], {{ port.g('sum') }});
                {% endfor %}

                {% for port in task.inports %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_mutex') }}: lock\n");
                dhmem::scoped_lock {{ port.g('ready_lock') }}({{ port.g('ready_mutex') }});
                {% endfor %}

                {% for port in task.inports %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_cond') }}: notify\n");
                {{ port.g('ready_cond') }}.notify_one();
                {% endfor %}
            }

            {
                {% for port in task.outports %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_mutex') }}: lock\n");
                dhmem::scoped_lock {{ port.g('ready_lock') }}({{ port.g('ready_mutex') }});
                {% endfor %}

                {% for port in task.outports %}
                for (int j=0; j<{{ port.g('data') }}.vec.size(); ++j) {
                    {{ port.g('data') }}.vec[j]
                        = 100 * 100 * 100 * ("{{ port.srcname }}"[0] - 'a' + 1)
                        + 100 * 100 *       ("{{ port.tgtname }}"[0] - 'a' + 1)
                        + 100 * i
                        + j;
                }
                {% endfor %}

                {% for port in task.outports %}
                {
                    //std::fprintf(stderr, "{{ task.name }}: {{ port.g('mutex') }}: lock\n");
                    dhmem::scoped_lock lock({{ port.g('mutex') }});
                    //std::fprintf(stderr, "{{ task.name }}: {{ port.g('cond') }}: notify\n");
                    {{ port.g('cond') }}.notify_one();
                }
                {% endfor %}

                {% for port in task.outports %}
                //std::fprintf(stderr, "{{ task.name }}: {{ port.g('ready_cond') }}: wait\n");
                {{ port.g('ready_cond') }}.wait({{ port.g('ready_lock') }});
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
        std::fprintf(stderr, "workflow: start\n");

        dhmem::Dhmem dhmem("foobar");
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

    int main(int argc, char **argv) {
        (void)argc;
        (void)argv;

        workflow();

        return 0;
    }
"""))


def main(ports):
    task_names = []
    for port in ports:
        if port.srcname not in task_names:
            task_names.append(port.srcname)

        if port.tgtname not in task_names:
            task_names.append(port.tgtname)

    task_names.sort()

    tasks = []
    for task_name in task_names:
        task = Task(
            name=task_name,
            ports=[port for port in ports if port.srcname == task_name or port.tgtname == task_name],
        )
        tasks.append(task)

    context = Context(
        tasks=tasks,
    )

    print(template.render(context.__dict__))


def cli():
    def port(s):
        srcname, tgtname, default_size = s.split('/')
        default_size = int(default_size)
        return Port(srcname, tgtname, default_size)

    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('ports', type=port, nargs='+')
    args = vars(parser.parse_args())

    main(**args)


if __name__ == '__main__':
    cli()


