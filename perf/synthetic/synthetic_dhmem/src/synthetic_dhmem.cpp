
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

    
    void start_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("START_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 10240;

        
        
        size_t start_out_a_in_size = 
            (s = getenv("START_OUT_A_IN_SIZE"))
                ? (size_t)atol(s)
                : 10240;
        

        
        
        
        auto &start_out_a_in_mutex = dhmem.simple<dhmem::mutex>("start_out_a_in_mutex");
        auto &start_out_a_in_cond = dhmem.simple<dhmem::cond>("start_out_a_in_cond");
        //auto &start_out_a_in_ready_mutex = dhmem.simple<dhmem::mutex>("start_out_a_in_ready_mutex");
        //auto &start_out_a_in_ready_cond = dhmem.simple<dhmem::cond>("start_out_a_in_ready_cond");
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "start: dhmem start_out_a_in_data\n");
        auto &start_out_a_in_data = dhmem.container<dhmem_data>("start_out_a_in_data");
        
        

        
        
        
        

        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                start_out_a_in_data.vec.resize(start_out_a_in_size);
                
            }
            

            // receive
            {
                

                
                

                

                

                
            }

            // send
            {
                
                
                //std::fprintf(stderr, "start: start_out_a_in_ready_mutex: lock\n");
                //dhmem::scoped_lock start_out_a_in_ready_lock(start_out_a_in_ready_mutex);
                
                

                
                for (int j=0; j<start_out_a_in_data.vec.size(); ++j) {
                    start_out_a_in_data.vec[j]
                        = 100 * 100 * 100 * ("start"[0] - 'a' + 1)
                        + 100 * 100 *       ("a"[0] - 'a' + 1)
                        + 100 * i
                        + j;
                }
                

                
                
                
                {
                    //std::fprintf(stderr, "start: start_out_a_in_mutex: lock\n");
                    dhmem::scoped_lock lock(start_out_a_in_mutex);
                    //std::fprintf(stderr, "start: start_out_a_in_cond: notify\n");
                    start_out_a_in_cond.notify_one();
                }
                
                

                
                
                
                

                
                
                //std::fprintf(stderr, "start: start_out_a_in_ready_cond: wait\n");
                //start_out_a_in_ready_cond.wait(start_out_a_in_ready_lock);
                
                
            }

            
            struct timespec end;
            clock_gettime(CLOCK_MONOTONIC, &end);

            useconds_t got_time
                = (1000 * 1000 * end.tv_sec + end.tv_nsec / 1000)
                - (1000 * 1000 * start.tv_sec + start.tv_nsec / 1000);

            if (exp_time == 0) {
                // no op
            } else if (got_time > exp_time) {
                if (do_print) std::fprintf(stderr, "start: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void a_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("A_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 10240;

        
        
        size_t a_out_end_in_size = 
            (s = getenv("A_OUT_END_IN_SIZE"))
                ? (size_t)atol(s)
                : 10240;
        

        
        
        
        auto &start_out_a_in_mutex = dhmem.simple<dhmem::mutex>("start_out_a_in_mutex");
        auto &start_out_a_in_cond = dhmem.simple<dhmem::cond>("start_out_a_in_cond");
        //auto &start_out_a_in_ready_mutex = dhmem.simple<dhmem::mutex>("start_out_a_in_ready_mutex");
        //auto &start_out_a_in_ready_cond = dhmem.simple<dhmem::cond>("start_out_a_in_ready_cond");
        
        
        
        auto &a_out_end_in_mutex = dhmem.simple<dhmem::mutex>("a_out_end_in_mutex");
        auto &a_out_end_in_cond = dhmem.simple<dhmem::cond>("a_out_end_in_cond");
        //auto &a_out_end_in_ready_mutex = dhmem.simple<dhmem::mutex>("a_out_end_in_ready_mutex");
        //auto &a_out_end_in_ready_cond = dhmem.simple<dhmem::cond>("a_out_end_in_ready_cond");
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "a: dhmem start_out_a_in_data\n");
        auto &start_out_a_in_data = dhmem.container<dhmem_data>("start_out_a_in_data");
        
        
        
        if (do_print) std::fprintf(stderr, "a: dhmem a_out_end_in_data\n");
        auto &a_out_end_in_data = dhmem.container<dhmem_data>("a_out_end_in_data");
        
        

        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "a: start_out_a_in_lock\n");
        dhmem::scoped_lock start_out_a_in_lock(start_out_a_in_mutex);
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                a_out_end_in_data.vec.resize(a_out_end_in_size);
                
            }
            

            // receive
            {
                
                
                //std::fprintf(stderr, "a: start_out_a_in_cond: wait\n");
                start_out_a_in_cond.wait(start_out_a_in_lock);
                
                

                
                
                
                

                
                int start_out_a_in_sum = 0;
                for (int j=0; j<start_out_a_in_data.vec.size(); ++j) {
                    start_out_a_in_sum += start_out_a_in_data.vec[j];
                }
                if (do_print) std::fprintf(stderr, "a: i = %d, first = %d, start_out_a_in_sum = %d\n", i, start_out_a_in_data.vec[0], start_out_a_in_sum);
                

                
                
                //std::fprintf(stderr, "a: start_out_a_in_ready_mutex: lock\n");
                //dhmem::scoped_lock start_out_a_in_ready_lock(start_out_a_in_ready_mutex);
                
                

                
                
                //std::fprintf(stderr, "a: start_out_a_in_ready_cond: notify\n");
                //start_out_a_in_ready_cond.notify_one();
                
                
            }

            // send
            {
                
                
                //std::fprintf(stderr, "a: a_out_end_in_ready_mutex: lock\n");
                //dhmem::scoped_lock a_out_end_in_ready_lock(a_out_end_in_ready_mutex);
                
                

                
                for (int j=0; j<a_out_end_in_data.vec.size(); ++j) {
                    a_out_end_in_data.vec[j]
                        = 100 * 100 * 100 * ("a"[0] - 'a' + 1)
                        + 100 * 100 *       ("end"[0] - 'a' + 1)
                        + 100 * i
                        + j;
                }
                

                
                
                
                {
                    //std::fprintf(stderr, "a: a_out_end_in_mutex: lock\n");
                    dhmem::scoped_lock lock(a_out_end_in_mutex);
                    //std::fprintf(stderr, "a: a_out_end_in_cond: notify\n");
                    a_out_end_in_cond.notify_one();
                }
                
                

                
                
                
                

                
                
                //std::fprintf(stderr, "a: a_out_end_in_ready_cond: wait\n");
                //a_out_end_in_ready_cond.wait(a_out_end_in_ready_lock);
                
                
            }

            
            struct timespec end;
            clock_gettime(CLOCK_MONOTONIC, &end);

            useconds_t got_time
                = (1000 * 1000 * end.tv_sec + end.tv_nsec / 1000)
                - (1000 * 1000 * start.tv_sec + start.tv_nsec / 1000);

            if (exp_time == 0) {
                // no op
            } else if (got_time > exp_time) {
                if (do_print) std::fprintf(stderr, "a: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void end_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 10240;

        
        

        
        
        
        auto &a_out_end_in_mutex = dhmem.simple<dhmem::mutex>("a_out_end_in_mutex");
        auto &a_out_end_in_cond = dhmem.simple<dhmem::cond>("a_out_end_in_cond");
        //auto &a_out_end_in_ready_mutex = dhmem.simple<dhmem::mutex>("a_out_end_in_ready_mutex");
        //auto &a_out_end_in_ready_cond = dhmem.simple<dhmem::cond>("a_out_end_in_ready_cond");
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "end: dhmem a_out_end_in_data\n");
        auto &a_out_end_in_data = dhmem.container<dhmem_data>("a_out_end_in_data");
        
        

        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "end: a_out_end_in_lock\n");
        dhmem::scoped_lock a_out_end_in_lock(a_out_end_in_mutex);
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            

            

            // receive
            {
                
                
                //std::fprintf(stderr, "end: a_out_end_in_cond: wait\n");
                a_out_end_in_cond.wait(a_out_end_in_lock);
                
                

                
                
                
                

                
                int a_out_end_in_sum = 0;
                for (int j=0; j<a_out_end_in_data.vec.size(); ++j) {
                    a_out_end_in_sum += a_out_end_in_data.vec[j];
                }
                if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, a_out_end_in_sum = %d\n", i, a_out_end_in_data.vec[0], a_out_end_in_sum);
                

                
                
                //std::fprintf(stderr, "end: a_out_end_in_ready_mutex: lock\n");
                //dhmem::scoped_lock a_out_end_in_ready_lock(a_out_end_in_ready_mutex);
                
                

                
                
                //std::fprintf(stderr, "end: a_out_end_in_ready_cond: notify\n");
                //a_out_end_in_ready_cond.notify_one();
                
                
            }

            // send
            {
                

                

                
                

                
                

                
            }

            
        }
    }
    

    

    
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

        
        if (fork() == 0) {
            {
                //std::fprintf(stderr, "start: forked\n");
                dhmem::scoped_lock barrier_lock(barrier_mutex);
                //std::fprintf(stderr, "start: acquired lock\n");
                ++barrier_count;
                barrier_cond.notify_all();

                for (;;) {
                    barrier_cond.wait(barrier_lock);
                    //std::fprintf(stderr, "start: waited on condition\n");
                    if (barrier_count == 3) break;
                }
            }
            //std::fprintf(stderr, "start: start\n");
            start_function(dhmem);
            //std::fprintf(stderr, "start: finished\n");
            std::exit(0);
        }
        
        if (fork() == 0) {
            {
                //std::fprintf(stderr, "a: forked\n");
                dhmem::scoped_lock barrier_lock(barrier_mutex);
                //std::fprintf(stderr, "a: acquired lock\n");
                ++barrier_count;
                barrier_cond.notify_all();

                for (;;) {
                    barrier_cond.wait(barrier_lock);
                    //std::fprintf(stderr, "a: waited on condition\n");
                    if (barrier_count == 3) break;
                }
            }
            //std::fprintf(stderr, "a: start\n");
            a_function(dhmem);
            //std::fprintf(stderr, "a: finished\n");
            std::exit(0);
        }
        
        if (fork() == 0) {
            {
                //std::fprintf(stderr, "end: forked\n");
                dhmem::scoped_lock barrier_lock(barrier_mutex);
                //std::fprintf(stderr, "end: acquired lock\n");
                ++barrier_count;
                barrier_cond.notify_all();

                for (;;) {
                    barrier_cond.wait(barrier_lock);
                    //std::fprintf(stderr, "end: waited on condition\n");
                    if (barrier_count == 3) break;
                }
            }
            //std::fprintf(stderr, "end: start\n");
            end_function(dhmem);
            //std::fprintf(stderr, "end: finished\n");
            std::exit(0);
        }
        

        //std::fprintf(stderr, "workflow: forked children\n");
        barrier_cond.notify_all();
        //std::fprintf(stderr, "workflow: notified all\n");

        for (;;) {
            //std::fprintf(stderr, "workflow: waiting on cond\n");
            barrier_cond.wait(barrier_lock);
            //std::fprintf(stderr, "workflow: checking count: %d/%d\n", barrier_count, 3);
            if (barrier_count == 3) break;
        }

        barrier_cond.notify_all();
        barrier_lock.unlock();

        
        //std::fprintf(stderr, "workflow: waiting on 1/3\n");
        wait(NULL);
        
        //std::fprintf(stderr, "workflow: waiting on 2/3\n");
        wait(NULL);
        
        //std::fprintf(stderr, "workflow: waiting on 3/3\n");
        wait(NULL);
        

        //std::fprintf(stderr, "workflow: finished\n");
	}
    

    int main(int argc, char **argv) {
        char *s;
        std::string name;
        int segment;

        MPI_Init(&argc, &argv);

        (void)argc;
        (void)argv;

        name =
            (s = getenv("DHMEM_NAME"))
                ? s
                : "dhmem";

        segment =
            (s = getenv("DHMEM_SEGMENT"))
                ? atoi(s)
                : 1048576;

        workflow(name, segment);

        return 0;
    }
