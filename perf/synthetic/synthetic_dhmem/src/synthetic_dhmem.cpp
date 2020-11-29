
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

    
    void a_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        
        useconds_t exp_time =
            (s = getenv("A_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 1024;

        
        
        size_t a_out_b_in_size = 
            (s = getenv("A_OUT_B_IN_SIZE"))
                ? (size_t)atol(s)
                : 10240;
        

        
        
        
        

        
        
        
        

        
        
        
        std::fprintf(stderr, "a: mpi a_out_b_in_data\n");
        auto a_out_b_in_data = mpi_data();
        
        

        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                a_out_b_in_data.vec.resize(a_out_b_in_size);
                
            }
            

            // receive
            {
                

                
                

                

                

                
            }

            // send
            {
                
                
                

                
                for (int j=0; j<a_out_b_in_data.vec.size(); ++j) {
                    a_out_b_in_data.vec[j]
                        = 100 * 100 * 100 * ("a"[0] - 'a' + 1)
                        + 100 * 100 *       ("b"[0] - 'a' + 1)
                        + 100 * i
                        + j;
                }
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = a_out_b_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(a_out_b_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
                }
                
                

                
                
                
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

        
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 1024;

        
        

        
        
        
        

        
        
        
        

        
        
        
        std::fprintf(stderr, "b: mpi a_out_b_in_data\n");
        auto a_out_b_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            

            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    a_out_b_in_data.vec.resize(vecsize);
                    MPI_Recv(a_out_b_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                int a_out_b_in_sum = 0;
                for (int j=0; j<a_out_b_in_data.vec.size(); ++j) {
                    a_out_b_in_sum += a_out_b_in_data.vec[j];
                }
                std::fprintf(stderr, "b: i = %d, first = %d, a_out_b_in_sum = %d\n", i, a_out_b_in_data.vec[0], a_out_b_in_sum);
                

                
                
                

                
                
                
            }

            // send
            {
                

                

                
                

                
                

                
            }

            
        }
    }
    

    
    void workflow(void) {
        dhmem::Dhmem dhmem("foobar");

        int rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (0) {
        
        } else if (rank == 0) {
            std::fprintf(stderr, "a: starting\n");
            a_function(dhmem);
        
        } else if (rank == 1) {
            std::fprintf(stderr, "b: starting\n");
            b_function(dhmem);
        
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..?\n");
        }
    }
    

    

    int main(int argc, char **argv) {
        MPI_Init(&argc, &argv);

        (void)argc;
        (void)argv;

        workflow();

        return 0;
    }
