// vim: sta:ai:et:sw=4:ts=4:sts=4

/**
 *
 */

#include <cstdio>
#include <memory>
#include <array>
#include <unistd.h>
#include <sys/wait.h>

#include <dhmem/dhmem.h>


size_t _size;


struct p_out_data {
    p_out_data(dhmem::allocator<void> &alloc)
        : vec(alloc)
        {}
    dhmem::vector<int> vec;
};


void producer(dhmem::Dhmem &dhmem) {
    auto &p_out_c_in_mutex = dhmem.simple<dhmem::mutex>("p_out_c_in_mutex");
    auto &p_out_c_in_cond = dhmem.simple<dhmem::cond>("p_out_c_in_cond");

    auto &p_out = dhmem.container<p_out_data>("p_out");

    for (int i=0;; ++i) {
        if (i == 0) {
            //std::printf("initial\n");
            p_out.vec.resize(_size);
        }

        for (int j=0; j<_size; ++j) {
            p_out.vec[j] = i + j;
        }

        {
            //std::printf("notifying cond\n");
            dhmem::scoped_lock lock(p_out_c_in_mutex);
            p_out_c_in_cond.notify_one();
        }
    }
}

void consumer(dhmem::Dhmem &dhmem) {
    auto &p_out_c_in_mutex = dhmem.simple<dhmem::mutex>("p_out_c_in_mutex");
    auto &p_out_c_in_cond = dhmem.simple<dhmem::cond>("p_out_c_in_cond");

    auto &p_out = dhmem.container<p_out_data>("p_out");

    dhmem::scoped_lock lock(p_out_c_in_mutex);
    for (int i=0;; ++i) {
        {
            //std::printf("waiting\n");
            p_out_c_in_cond.wait(lock);
        }

        int sum = 0;
        for (int j=0; j<_size; ++j) {
            sum += p_out.vec[j];
        }

        std::printf("%d,%d,%d\n", (int)_size, p_out.vec[0], sum);
    }
}


void workflow(void) {
    std::fprintf(stderr, "Start\n");
    dhmem::Dhmem dhmem(dhmem::open_or_create, "foobar", 65536);

    auto &start_mutex = dhmem.simple<dhmem::mutex>("start_mutex");
    auto &start_cond = dhmem.simple<dhmem::cond>("start_cond");

    if (fork() == 0) {
        std::fprintf(stderr, "Start producer\n");
        {
            dhmem::scoped_lock lock(start_mutex);
            start_cond.wait(lock);
        }
        std::fprintf(stderr, "Producer wait finished\n");
        producer(dhmem);
        std::exit(0);
    }

    if (fork() == 0) {
        std::fprintf(stderr, "Start consumer\n");
        {
            dhmem::scoped_lock lock(start_mutex);
            start_cond.wait(lock);
        }
        std::fprintf(stderr, "Consumer wait finished\n");
        consumer(dhmem);
        std::exit(0);
    }

    sleep(1);

    {
        std::fprintf(stderr, "Lock workflow\n");
        dhmem::scoped_lock lock(start_mutex);
        std::fprintf(stderr, "Workflow notifly\n");
        start_cond.notify_all();
    }

    std::fprintf(stderr, "Waiting... 0\n");
    wait(NULL);
    std::fprintf(stderr, "Waiting... 1\n");
    wait(NULL);
    std::fprintf(stderr, "Done\n");
}


int main(int argc, char **argv) {
    char *s;

    (void)argc;
    (void)argv;

    _size = (s = getenv("size")) ? atol(s) : 1024;

    workflow();

    return 0;
}
