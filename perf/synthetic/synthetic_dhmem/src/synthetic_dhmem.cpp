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
                : 2048;

        
        
        
        
        size_t start_size = 
            (s = getenv("START_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        

        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_a_in_data\n");
        auto start_out_a_in_data = mpi_data();
        
        

        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                start_out_a_in_data.vec.resize(start_size);
                
            }
            

            // receive
            {
                

                
                

                
                

                

                

                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = start_out_a_in_data.vec.data();
                    for (int j=0; j<start_out_a_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("start"[0] - 'a' + 1)
                            + 100 * 100 *       ("a"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = start_out_a_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_a_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                : 2048;

        
        
        
        
        size_t a_size = 
            (s = getenv("A_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "a: mpi start_out_a_in_data\n");
        auto start_out_a_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "a: mpi a_out_b_in_data\n");
        auto a_out_b_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                a_out_b_in_data.vec.resize(a_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_a_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_a_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = start_out_a_in_data.vec.data();
                    int start_out_a_in_sum = 0;
                    for (int j=0; j<start_out_a_in_data.vec.size(); ++j) {
                        start_out_a_in_sum += data[j];  // start_out_a_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "a: i = %d, first = %d, start_out_a_in_sum = %d\n", i, start_out_a_in_data.vec[0], start_out_a_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = a_out_b_in_data.vec.data();
                    for (int j=0; j<a_out_b_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("a"[0] - 'a' + 1)
                            + 100 * 100 *       ("b"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = a_out_b_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 2, 1, MPI_COMM_WORLD);
                    MPI_Send(a_out_b_in_data.vec.data(), vecsize, MPI_INT, 2, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "a: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void b_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("B_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 2048;

        
        
        
        
        size_t b_size = 
            (s = getenv("B_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "b: mpi a_out_b_in_data\n");
        auto a_out_b_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "b: mpi b_out_c_in_data\n");
        auto b_out_c_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                b_out_c_in_data.vec.resize(b_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    a_out_b_in_data.vec.resize(vecsize);
                    MPI_Recv(a_out_b_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = a_out_b_in_data.vec.data();
                    int a_out_b_in_sum = 0;
                    for (int j=0; j<a_out_b_in_data.vec.size(); ++j) {
                        a_out_b_in_sum += data[j];  // a_out_b_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "b: i = %d, first = %d, a_out_b_in_sum = %d\n", i, a_out_b_in_data.vec[0], a_out_b_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = b_out_c_in_data.vec.data();
                    for (int j=0; j<b_out_c_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("b"[0] - 'a' + 1)
                            + 100 * 100 *       ("c"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = b_out_c_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 3, 1, MPI_COMM_WORLD);
                    MPI_Send(b_out_c_in_data.vec.data(), vecsize, MPI_INT, 3, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "b: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void c_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("C_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 2048;

        
        
        
        
        size_t c_size = 
            (s = getenv("C_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "c: mpi b_out_c_in_data\n");
        auto b_out_c_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "c: mpi c_out_d_in_data\n");
        auto c_out_d_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                c_out_d_in_data.vec.resize(c_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    b_out_c_in_data.vec.resize(vecsize);
                    MPI_Recv(b_out_c_in_data.vec.data(), vecsize, MPI_INT, 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = b_out_c_in_data.vec.data();
                    int b_out_c_in_sum = 0;
                    for (int j=0; j<b_out_c_in_data.vec.size(); ++j) {
                        b_out_c_in_sum += data[j];  // b_out_c_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "c: i = %d, first = %d, b_out_c_in_sum = %d\n", i, b_out_c_in_data.vec[0], b_out_c_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = c_out_d_in_data.vec.data();
                    for (int j=0; j<c_out_d_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("c"[0] - 'a' + 1)
                            + 100 * 100 *       ("d"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = c_out_d_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 4, 1, MPI_COMM_WORLD);
                    MPI_Send(c_out_d_in_data.vec.data(), vecsize, MPI_INT, 4, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "c: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void d_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("D_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 2048;

        
        
        
        
        size_t d_size = 
            (s = getenv("D_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "d: mpi c_out_d_in_data\n");
        auto c_out_d_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "d: mpi d_out_e_in_data\n");
        auto d_out_e_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                d_out_e_in_data.vec.resize(d_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 3, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    c_out_d_in_data.vec.resize(vecsize);
                    MPI_Recv(c_out_d_in_data.vec.data(), vecsize, MPI_INT, 3, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = c_out_d_in_data.vec.data();
                    int c_out_d_in_sum = 0;
                    for (int j=0; j<c_out_d_in_data.vec.size(); ++j) {
                        c_out_d_in_sum += data[j];  // c_out_d_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "d: i = %d, first = %d, c_out_d_in_sum = %d\n", i, c_out_d_in_data.vec[0], c_out_d_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = d_out_e_in_data.vec.data();
                    for (int j=0; j<d_out_e_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("d"[0] - 'a' + 1)
                            + 100 * 100 *       ("e"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = d_out_e_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 5, 1, MPI_COMM_WORLD);
                    MPI_Send(d_out_e_in_data.vec.data(), vecsize, MPI_INT, 5, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "d: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void e_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("E_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 2048;

        
        
        
        
        size_t e_size = 
            (s = getenv("E_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "e: mpi d_out_e_in_data\n");
        auto d_out_e_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "e: mpi e_out_f_in_data\n");
        auto e_out_f_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                e_out_f_in_data.vec.resize(e_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 4, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    d_out_e_in_data.vec.resize(vecsize);
                    MPI_Recv(d_out_e_in_data.vec.data(), vecsize, MPI_INT, 4, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = d_out_e_in_data.vec.data();
                    int d_out_e_in_sum = 0;
                    for (int j=0; j<d_out_e_in_data.vec.size(); ++j) {
                        d_out_e_in_sum += data[j];  // d_out_e_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "e: i = %d, first = %d, d_out_e_in_sum = %d\n", i, d_out_e_in_data.vec[0], d_out_e_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = e_out_f_in_data.vec.data();
                    for (int j=0; j<e_out_f_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("e"[0] - 'a' + 1)
                            + 100 * 100 *       ("f"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = e_out_f_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 6, 1, MPI_COMM_WORLD);
                    MPI_Send(e_out_f_in_data.vec.data(), vecsize, MPI_INT, 6, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "e: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void f_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("F_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 2048;

        
        
        
        
        size_t f_size = 
            (s = getenv("F_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "f: mpi e_out_f_in_data\n");
        auto e_out_f_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "f: mpi f_out_g_in_data\n");
        auto f_out_g_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                f_out_g_in_data.vec.resize(f_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 5, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    e_out_f_in_data.vec.resize(vecsize);
                    MPI_Recv(e_out_f_in_data.vec.data(), vecsize, MPI_INT, 5, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = e_out_f_in_data.vec.data();
                    int e_out_f_in_sum = 0;
                    for (int j=0; j<e_out_f_in_data.vec.size(); ++j) {
                        e_out_f_in_sum += data[j];  // e_out_f_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "f: i = %d, first = %d, e_out_f_in_sum = %d\n", i, e_out_f_in_data.vec[0], e_out_f_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = f_out_g_in_data.vec.data();
                    for (int j=0; j<f_out_g_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("f"[0] - 'a' + 1)
                            + 100 * 100 *       ("g"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = f_out_g_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 7, 1, MPI_COMM_WORLD);
                    MPI_Send(f_out_g_in_data.vec.data(), vecsize, MPI_INT, 7, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "f: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void g_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        
        useconds_t exp_time =
            (s = getenv("G_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 2048;

        
        
        
        
        size_t g_size = 
            (s = getenv("G_SIZE"))
                ? (size_t)atol(s)
                : 2621440;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "g: mpi f_out_g_in_data\n");
        auto f_out_g_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "g: mpi g_out_end_in_data\n");
        auto g_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                g_out_end_in_data.vec.resize(g_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 6, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    f_out_g_in_data.vec.resize(vecsize);
                    MPI_Recv(f_out_g_in_data.vec.data(), vecsize, MPI_INT, 6, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = f_out_g_in_data.vec.data();
                    int f_out_g_in_sum = 0;
                    for (int j=0; j<f_out_g_in_data.vec.size(); ++j) {
                        f_out_g_in_sum += data[j];  // f_out_g_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "g: i = %d, first = %d, f_out_g_in_sum = %d\n", i, f_out_g_in_data.vec[0], f_out_g_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = g_out_end_in_data.vec.data();
                    for (int j=0; j<g_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("g"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    int vecsize;
                    vecsize = g_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_INT, 8, 1, MPI_COMM_WORLD);
                    MPI_Send(g_out_end_in_data.vec.data(), vecsize, MPI_INT, 8, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "g: loop took too %dus long\n", got_time - exp_time);
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
                : 2048;

        
        
        
        

        
        
        
        

        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi g_out_end_in_data\n");
        auto g_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            

            

            // receive
            {
                
                
                

                
                
                
                {
                    int vecsize;
                    MPI_Recv(&vecsize, 1, MPI_INT, 7, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    g_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(g_out_end_in_data.vec.data(), vecsize, MPI_INT, 7, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                

                
                {
                    int *data = g_out_end_in_data.vec.data();
                    int g_out_end_in_sum = 0;
                    for (int j=0; j<g_out_end_in_data.vec.size(); ++j) {
                        g_out_end_in_sum += data[j];  // g_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, g_out_end_in_sum = %d\n", i, g_out_end_in_data.vec[0], g_out_end_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                

                
                
                

                
                

                
                

                
                

                
            }

            
        }
    }
    

    
    void workflow(std::string &name, int segment) {
        int rank;

        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (0) {
        
        } else if (rank == 0) {
            
            dhmem::Dhmem dhmem(dhmem::force_create_only, name, segment);
            MPI_Barrier(MPI_COMM_WORLD);
            

            //std::fprintf(stderr, "start: starting\n");
            start_function(dhmem);
        
        } else if (rank == 1) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "a: starting\n");
            a_function(dhmem);
        
        } else if (rank == 2) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "b: starting\n");
            b_function(dhmem);
        
        } else if (rank == 3) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "c: starting\n");
            c_function(dhmem);
        
        } else if (rank == 4) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "d: starting\n");
            d_function(dhmem);
        
        } else if (rank == 5) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "e: starting\n");
            e_function(dhmem);
        
        } else if (rank == 6) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "f: starting\n");
            f_function(dhmem);
        
        } else if (rank == 7) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "g: starting\n");
            g_function(dhmem);
        
        } else if (rank == 8) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "end: starting\n");
            end_function(dhmem);
        
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..? rank=%d expmax=%d\n", rank, 9);
        }
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
                : 1073741824;

        workflow(name, segment);

        return 0;
    }
