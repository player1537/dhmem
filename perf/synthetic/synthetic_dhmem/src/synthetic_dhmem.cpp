
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


void a_function(dhmem::Dhmem &dhmem) {
    
    char *s;
    

    
    useconds_t exp_time =
        (s = getenv("A_TIME"))
            ? (useconds_t)atol(s)
            : 1000000;
    

    
    size_t a_out_b_in_size = 
        (s = getenv("A_OUT_B_IN_SIZE"))
            ? (size_t)atol(s)
            : 1024;
    
    size_t a_out_c_in_size = 
        (s = getenv("A_OUT_C_IN_SIZE"))
            ? (size_t)atol(s)
            : 1024;
    

    
    auto &a_out_b_in_mutex = dhmem.simple<dhmem::mutex>("a_out_b_in_mutex");
    auto &a_out_b_in_cond = dhmem.simple<dhmem::cond>("a_out_b_in_cond");
    auto &a_out_b_in_ready_mutex = dhmem.simple<dhmem::mutex>("a_out_b_in_ready_mutex");
    auto &a_out_b_in_ready_cond = dhmem.simple<dhmem::cond>("a_out_b_in_ready_cond");
    
    auto &a_out_c_in_mutex = dhmem.simple<dhmem::mutex>("a_out_c_in_mutex");
    auto &a_out_c_in_cond = dhmem.simple<dhmem::cond>("a_out_c_in_cond");
    auto &a_out_c_in_ready_mutex = dhmem.simple<dhmem::mutex>("a_out_c_in_ready_mutex");
    auto &a_out_c_in_ready_cond = dhmem.simple<dhmem::cond>("a_out_c_in_ready_cond");
    

    
    auto &a_out_b_in_data = dhmem.container<data>("a_out_b_in_data");
    
    auto &a_out_c_in_data = dhmem.container<data>("a_out_c_in_data");
    

    

    for (int i=0;; ++i) {
        
        struct timespec start;
        clock_gettime(CLOCK_MONOTONIC, &start);
        

        
        if (i == 0) {
            
            a_out_b_in_data.vec.resize(a_out_b_in_size);
            
            a_out_c_in_data.vec.resize(a_out_c_in_size);
            
        }
        

        {
            

            

            

            
        }

        {
            
            //std::fprintf(stderr, "a: a_out_b_in_ready_mutex: lock\n");
            dhmem::scoped_lock a_out_b_in_ready_lock(a_out_b_in_ready_mutex);
            
            //std::fprintf(stderr, "a: a_out_c_in_ready_mutex: lock\n");
            dhmem::scoped_lock a_out_c_in_ready_lock(a_out_c_in_ready_mutex);
            

            
            for (int j=0; j<a_out_b_in_data.vec.size(); ++j) {
                a_out_b_in_data.vec[j]
                    = 100 * 100 * 100 * ("a"[0] - 'a' + 1)
                    + 100 * 100 *       ("b"[0] - 'a' + 1)
                    + 100 * i
                    + j;
            }
            
            for (int j=0; j<a_out_c_in_data.vec.size(); ++j) {
                a_out_c_in_data.vec[j]
                    = 100 * 100 * 100 * ("a"[0] - 'a' + 1)
                    + 100 * 100 *       ("c"[0] - 'a' + 1)
                    + 100 * i
                    + j;
            }
            

            
            {
                //std::fprintf(stderr, "a: a_out_b_in_mutex: lock\n");
                dhmem::scoped_lock lock(a_out_b_in_mutex);
                //std::fprintf(stderr, "a: a_out_b_in_cond: notify\n");
                a_out_b_in_cond.notify_one();
            }
            
            {
                //std::fprintf(stderr, "a: a_out_c_in_mutex: lock\n");
                dhmem::scoped_lock lock(a_out_c_in_mutex);
                //std::fprintf(stderr, "a: a_out_c_in_cond: notify\n");
                a_out_c_in_cond.notify_one();
            }
            

            
            //std::fprintf(stderr, "a: a_out_b_in_ready_cond: wait\n");
            a_out_b_in_ready_cond.wait(a_out_b_in_ready_lock);
            
            //std::fprintf(stderr, "a: a_out_c_in_ready_cond: wait\n");
            a_out_c_in_ready_cond.wait(a_out_c_in_ready_lock);
            
        }

        
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);

        useconds_t got_time
            = (1000 * 1000 * end.tv_sec + end.tv_nsec / 1000)
            - (1000 * 1000 * start.tv_sec + start.tv_nsec / 1000);

        if (exp_time == 0) {
            // no op
        } else if (got_time > exp_time) {
            std::fprintf(stderr, "a: loop took too %dus long\n", got_time - exp_time);
        } else {
            usleep(exp_time - got_time);
        }
        
    }
}

void b_function(dhmem::Dhmem &dhmem) {
    
    char *s;
    

    
    useconds_t exp_time =
        (s = getenv("B_TIME"))
            ? (useconds_t)atol(s)
            : 1000000;
    

    
    size_t b_out_c_in_size = 
        (s = getenv("B_OUT_C_IN_SIZE"))
            ? (size_t)atol(s)
            : 1024;
    

    
    auto &a_out_b_in_mutex = dhmem.simple<dhmem::mutex>("a_out_b_in_mutex");
    auto &a_out_b_in_cond = dhmem.simple<dhmem::cond>("a_out_b_in_cond");
    auto &a_out_b_in_ready_mutex = dhmem.simple<dhmem::mutex>("a_out_b_in_ready_mutex");
    auto &a_out_b_in_ready_cond = dhmem.simple<dhmem::cond>("a_out_b_in_ready_cond");
    
    auto &b_out_c_in_mutex = dhmem.simple<dhmem::mutex>("b_out_c_in_mutex");
    auto &b_out_c_in_cond = dhmem.simple<dhmem::cond>("b_out_c_in_cond");
    auto &b_out_c_in_ready_mutex = dhmem.simple<dhmem::mutex>("b_out_c_in_ready_mutex");
    auto &b_out_c_in_ready_cond = dhmem.simple<dhmem::cond>("b_out_c_in_ready_cond");
    

    
    auto &a_out_b_in_data = dhmem.container<data>("a_out_b_in_data");
    
    auto &b_out_c_in_data = dhmem.container<data>("b_out_c_in_data");
    

    
    dhmem::scoped_lock a_out_b_in_lock(a_out_b_in_mutex);
    

    for (int i=0;; ++i) {
        
        struct timespec start;
        clock_gettime(CLOCK_MONOTONIC, &start);
        

        
        if (i == 0) {
            
            b_out_c_in_data.vec.resize(b_out_c_in_size);
            
        }
        

        {
            
            //std::fprintf(stderr, "b: a_out_b_in_cond: wait\n");
            a_out_b_in_cond.wait(a_out_b_in_lock);
            

            
            int a_out_b_in_sum = 0;
            for (int j=0; j<a_out_b_in_data.vec.size(); ++j) {
                a_out_b_in_sum += a_out_b_in_data.vec[j];
            }
            std::fprintf(stderr, "b: b: first = %d, a_out_b_in_sum = %d\n", a_out_b_in_data.vec[0], a_out_b_in_sum);
            

            
            //std::fprintf(stderr, "b: a_out_b_in_ready_mutex: lock\n");
            dhmem::scoped_lock a_out_b_in_ready_lock(a_out_b_in_ready_mutex);
            

            
            //std::fprintf(stderr, "b: a_out_b_in_ready_cond: notify\n");
            a_out_b_in_ready_cond.notify_one();
            
        }

        {
            
            //std::fprintf(stderr, "b: b_out_c_in_ready_mutex: lock\n");
            dhmem::scoped_lock b_out_c_in_ready_lock(b_out_c_in_ready_mutex);
            

            
            for (int j=0; j<b_out_c_in_data.vec.size(); ++j) {
                b_out_c_in_data.vec[j]
                    = 100 * 100 * 100 * ("b"[0] - 'a' + 1)
                    + 100 * 100 *       ("c"[0] - 'a' + 1)
                    + 100 * i
                    + j;
            }
            

            
            {
                //std::fprintf(stderr, "b: b_out_c_in_mutex: lock\n");
                dhmem::scoped_lock lock(b_out_c_in_mutex);
                //std::fprintf(stderr, "b: b_out_c_in_cond: notify\n");
                b_out_c_in_cond.notify_one();
            }
            

            
            //std::fprintf(stderr, "b: b_out_c_in_ready_cond: wait\n");
            b_out_c_in_ready_cond.wait(b_out_c_in_ready_lock);
            
        }

        
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &end);

        useconds_t got_time
            = (1000 * 1000 * end.tv_sec + end.tv_nsec / 1000)
            - (1000 * 1000 * start.tv_sec + start.tv_nsec / 1000);

        if (exp_time == 0) {
            // no op
        } else if (got_time > exp_time) {
            std::fprintf(stderr, "b: loop took too %dus long\n", got_time - exp_time);
        } else {
            usleep(exp_time - got_time);
        }
        
    }
}

void c_function(dhmem::Dhmem &dhmem) {
    

    

    

    
    auto &a_out_c_in_mutex = dhmem.simple<dhmem::mutex>("a_out_c_in_mutex");
    auto &a_out_c_in_cond = dhmem.simple<dhmem::cond>("a_out_c_in_cond");
    auto &a_out_c_in_ready_mutex = dhmem.simple<dhmem::mutex>("a_out_c_in_ready_mutex");
    auto &a_out_c_in_ready_cond = dhmem.simple<dhmem::cond>("a_out_c_in_ready_cond");
    
    auto &b_out_c_in_mutex = dhmem.simple<dhmem::mutex>("b_out_c_in_mutex");
    auto &b_out_c_in_cond = dhmem.simple<dhmem::cond>("b_out_c_in_cond");
    auto &b_out_c_in_ready_mutex = dhmem.simple<dhmem::mutex>("b_out_c_in_ready_mutex");
    auto &b_out_c_in_ready_cond = dhmem.simple<dhmem::cond>("b_out_c_in_ready_cond");
    

    
    auto &a_out_c_in_data = dhmem.container<data>("a_out_c_in_data");
    
    auto &b_out_c_in_data = dhmem.container<data>("b_out_c_in_data");
    

    
    dhmem::scoped_lock a_out_c_in_lock(a_out_c_in_mutex);
    
    dhmem::scoped_lock b_out_c_in_lock(b_out_c_in_mutex);
    

    for (int i=0;; ++i) {
        

        

        {
            
            //std::fprintf(stderr, "c: a_out_c_in_cond: wait\n");
            a_out_c_in_cond.wait(a_out_c_in_lock);
            
            //std::fprintf(stderr, "c: b_out_c_in_cond: wait\n");
            b_out_c_in_cond.wait(b_out_c_in_lock);
            

            
            int a_out_c_in_sum = 0;
            for (int j=0; j<a_out_c_in_data.vec.size(); ++j) {
                a_out_c_in_sum += a_out_c_in_data.vec[j];
            }
            std::fprintf(stderr, "c: c: first = %d, a_out_c_in_sum = %d\n", a_out_c_in_data.vec[0], a_out_c_in_sum);
            
            int b_out_c_in_sum = 0;
            for (int j=0; j<b_out_c_in_data.vec.size(); ++j) {
                b_out_c_in_sum += b_out_c_in_data.vec[j];
            }
            std::fprintf(stderr, "c: c: first = %d, b_out_c_in_sum = %d\n", b_out_c_in_data.vec[0], b_out_c_in_sum);
            

            
            //std::fprintf(stderr, "c: a_out_c_in_ready_mutex: lock\n");
            dhmem::scoped_lock a_out_c_in_ready_lock(a_out_c_in_ready_mutex);
            
            //std::fprintf(stderr, "c: b_out_c_in_ready_mutex: lock\n");
            dhmem::scoped_lock b_out_c_in_ready_lock(b_out_c_in_ready_mutex);
            

            
            //std::fprintf(stderr, "c: a_out_c_in_ready_cond: notify\n");
            a_out_c_in_ready_cond.notify_one();
            
            //std::fprintf(stderr, "c: b_out_c_in_ready_cond: notify\n");
            b_out_c_in_ready_cond.notify_one();
            
        }

        {
            

            

            

            
        }

        
    }
}


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

    
    if (fork() == 0) {
        {
            std::fprintf(stderr, "a: forked\n");
            dhmem::scoped_lock barrier_lock(barrier_mutex);
            std::fprintf(stderr, "a: acquired lock\n");
            ++barrier_count;
            barrier_cond.notify_all();

            for (;;) {
                barrier_cond.wait(barrier_lock);
                std::fprintf(stderr, "a: waited on condition\n");
                if (barrier_count == 3) break;
            }
        }
        std::fprintf(stderr, "a: start\n");
        a_function(dhmem);
        std::fprintf(stderr, "a: finished\n");
        std::exit(0);
    }
    
    if (fork() == 0) {
        {
            std::fprintf(stderr, "b: forked\n");
            dhmem::scoped_lock barrier_lock(barrier_mutex);
            std::fprintf(stderr, "b: acquired lock\n");
            ++barrier_count;
            barrier_cond.notify_all();

            for (;;) {
                barrier_cond.wait(barrier_lock);
                std::fprintf(stderr, "b: waited on condition\n");
                if (barrier_count == 3) break;
            }
        }
        std::fprintf(stderr, "b: start\n");
        b_function(dhmem);
        std::fprintf(stderr, "b: finished\n");
        std::exit(0);
    }
    
    if (fork() == 0) {
        {
            std::fprintf(stderr, "c: forked\n");
            dhmem::scoped_lock barrier_lock(barrier_mutex);
            std::fprintf(stderr, "c: acquired lock\n");
            ++barrier_count;
            barrier_cond.notify_all();

            for (;;) {
                barrier_cond.wait(barrier_lock);
                std::fprintf(stderr, "c: waited on condition\n");
                if (barrier_count == 3) break;
            }
        }
        std::fprintf(stderr, "c: start\n");
        c_function(dhmem);
        std::fprintf(stderr, "c: finished\n");
        std::exit(0);
    }
    

    std::fprintf(stderr, "workflow: forked children\n");
    barrier_cond.notify_all();
    std::fprintf(stderr, "workflow: notified all\n");

    for (;;) {
        std::fprintf(stderr, "workflow: waiting on cond\n");
        barrier_cond.wait(barrier_lock);
        std::fprintf(stderr, "workflow: checking count: %d/%d\n", barrier_count, 3);
        if (barrier_count == 3) break;
    }

    barrier_cond.notify_all();
    barrier_lock.unlock();

    
    std::fprintf(stderr, "workflow: waiting on 1/3\n");
    wait(NULL);
    
    std::fprintf(stderr, "workflow: waiting on 2/3\n");
    wait(NULL);
    
    std::fprintf(stderr, "workflow: waiting on 3/3\n");
    wait(NULL);
    

    std::fprintf(stderr, "workflow: finished\n");
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    workflow();

    return 0;
}
