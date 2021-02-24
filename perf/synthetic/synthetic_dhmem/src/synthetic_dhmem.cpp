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
                : 512;

        
        
        
        
        size_t start_size = 
            (s = getenv("START_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x1_in_data\n");
        auto start_out_x1_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x2_in_data\n");
        auto start_out_x2_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x3_in_data\n");
        auto start_out_x3_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x4_in_data\n");
        auto start_out_x4_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x5_in_data\n");
        auto start_out_x5_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x6_in_data\n");
        auto start_out_x6_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x7_in_data\n");
        auto start_out_x7_in_data = mpi_data();
        
        

        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                start_out_x1_in_data.vec.resize(start_size);
                
                start_out_x2_in_data.vec.resize(start_size);
                
                start_out_x3_in_data.vec.resize(start_size);
                
                start_out_x4_in_data.vec.resize(start_size);
                
                start_out_x5_in_data.vec.resize(start_size);
                
                start_out_x6_in_data.vec.resize(start_size);
                
                start_out_x7_in_data.vec.resize(start_size);
                
            }
            

            // receive
            {
                

                
                

                
                
                
                

                
                

                

                

                
            }

            // send
            {
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                
                {
                    int *data = start_out_x1_in_data.vec.data();
                    for (int j=0; j<start_out_x1_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("start"[0] - 'a' + 1)
                            + 100 * 100 *       ("x1"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x1_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 2, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x1_in_data.vec.data(), vecsize, MPI_INT, 2, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x2_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 3, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x2_in_data.vec.data(), vecsize, MPI_INT, 3, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x3_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 4, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x3_in_data.vec.data(), vecsize, MPI_INT, 4, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x4_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 5, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x4_in_data.vec.data(), vecsize, MPI_INT, 5, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x5_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 6, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x5_in_data.vec.data(), vecsize, MPI_INT, 6, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x6_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 7, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x6_in_data.vec.data(), vecsize, MPI_INT, 7, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x7_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 8, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x7_in_data.vec.data(), vecsize, MPI_INT, 8, 1, MPI_COMM_WORLD);
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
    
    void end_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x1_out_end_in_data\n");
        auto x1_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x2_out_end_in_data\n");
        auto x2_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x3_out_end_in_data\n");
        auto x3_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x4_out_end_in_data\n");
        auto x4_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x5_out_end_in_data\n");
        auto x5_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x6_out_end_in_data\n");
        auto x6_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x7_out_end_in_data\n");
        auto x7_out_end_in_data = mpi_data();
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            

            

            // receive
            {
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x1_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x1_out_end_in_data.vec.data(), vecsize, MPI_INT, 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 3, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x2_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x2_out_end_in_data.vec.data(), vecsize, MPI_INT, 3, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 4, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x3_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x3_out_end_in_data.vec.data(), vecsize, MPI_INT, 4, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 5, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x4_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x4_out_end_in_data.vec.data(), vecsize, MPI_INT, 5, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 6, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x5_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x5_out_end_in_data.vec.data(), vecsize, MPI_INT, 6, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 7, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x6_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x6_out_end_in_data.vec.data(), vecsize, MPI_INT, 7, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 8, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x7_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x7_out_end_in_data.vec.data(), vecsize, MPI_INT, 8, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                {
                    int *data = x1_out_end_in_data.vec.data();
                    int x1_out_end_in_sum = 0;
                    for (int j=0; j<x1_out_end_in_data.vec.size(); ++j) {
                        x1_out_end_in_sum += data[j];  // x1_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x1_out_end_in_sum = %d\n", i, x1_out_end_in_data.vec[0], x1_out_end_in_sum);
                }
                
                {
                    int *data = x2_out_end_in_data.vec.data();
                    int x2_out_end_in_sum = 0;
                    for (int j=0; j<x2_out_end_in_data.vec.size(); ++j) {
                        x2_out_end_in_sum += data[j];  // x2_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x2_out_end_in_sum = %d\n", i, x2_out_end_in_data.vec[0], x2_out_end_in_sum);
                }
                
                {
                    int *data = x3_out_end_in_data.vec.data();
                    int x3_out_end_in_sum = 0;
                    for (int j=0; j<x3_out_end_in_data.vec.size(); ++j) {
                        x3_out_end_in_sum += data[j];  // x3_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x3_out_end_in_sum = %d\n", i, x3_out_end_in_data.vec[0], x3_out_end_in_sum);
                }
                
                {
                    int *data = x4_out_end_in_data.vec.data();
                    int x4_out_end_in_sum = 0;
                    for (int j=0; j<x4_out_end_in_data.vec.size(); ++j) {
                        x4_out_end_in_sum += data[j];  // x4_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x4_out_end_in_sum = %d\n", i, x4_out_end_in_data.vec[0], x4_out_end_in_sum);
                }
                
                {
                    int *data = x5_out_end_in_data.vec.data();
                    int x5_out_end_in_sum = 0;
                    for (int j=0; j<x5_out_end_in_data.vec.size(); ++j) {
                        x5_out_end_in_sum += data[j];  // x5_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x5_out_end_in_sum = %d\n", i, x5_out_end_in_data.vec[0], x5_out_end_in_sum);
                }
                
                {
                    int *data = x6_out_end_in_data.vec.data();
                    int x6_out_end_in_sum = 0;
                    for (int j=0; j<x6_out_end_in_data.vec.size(); ++j) {
                        x6_out_end_in_sum += data[j];  // x6_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x6_out_end_in_sum = %d\n", i, x6_out_end_in_data.vec[0], x6_out_end_in_sum);
                }
                
                {
                    int *data = x7_out_end_in_data.vec.data();
                    int x7_out_end_in_sum = 0;
                    for (int j=0; j<x7_out_end_in_data.vec.size(); ++j) {
                        x7_out_end_in_sum += data[j];  // x7_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x7_out_end_in_sum = %d\n", i, x7_out_end_in_data.vec[0], x7_out_end_in_sum);
                }
                

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            }

            // send
            {
                

                
                
                

                
                

                
                

                
                
                
                

                
                

                
            }

            
        }
    }
    
    void x1_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X1_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x1_size = 
            (s = getenv("X1_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x1: mpi start_out_x1_in_data\n");
        auto start_out_x1_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x1: mpi x1_out_end_in_data\n");
        auto x1_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x1_out_end_in_data.vec.resize(x1_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x1_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x1_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x1_in_data.vec.data();
                    int start_out_x1_in_sum = 0;
                    for (int j=0; j<start_out_x1_in_data.vec.size(); ++j) {
                        start_out_x1_in_sum += data[j];  // start_out_x1_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x1: i = %d, first = %d, start_out_x1_in_sum = %d\n", i, start_out_x1_in_data.vec[0], start_out_x1_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x1_out_end_in_data.vec.data();
                    for (int j=0; j<x1_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x1"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x1_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x1_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x1: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x2_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X2_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x2_size = 
            (s = getenv("X2_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x2: mpi start_out_x2_in_data\n");
        auto start_out_x2_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x2: mpi x2_out_end_in_data\n");
        auto x2_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x2_out_end_in_data.vec.resize(x2_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x2_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x2_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x2_in_data.vec.data();
                    int start_out_x2_in_sum = 0;
                    for (int j=0; j<start_out_x2_in_data.vec.size(); ++j) {
                        start_out_x2_in_sum += data[j];  // start_out_x2_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x2: i = %d, first = %d, start_out_x2_in_sum = %d\n", i, start_out_x2_in_data.vec[0], start_out_x2_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x2_out_end_in_data.vec.data();
                    for (int j=0; j<x2_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x2"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x2_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x2_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x2: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x3_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X3_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x3_size = 
            (s = getenv("X3_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x3: mpi start_out_x3_in_data\n");
        auto start_out_x3_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x3: mpi x3_out_end_in_data\n");
        auto x3_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x3_out_end_in_data.vec.resize(x3_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x3_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x3_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x3_in_data.vec.data();
                    int start_out_x3_in_sum = 0;
                    for (int j=0; j<start_out_x3_in_data.vec.size(); ++j) {
                        start_out_x3_in_sum += data[j];  // start_out_x3_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x3: i = %d, first = %d, start_out_x3_in_sum = %d\n", i, start_out_x3_in_data.vec[0], start_out_x3_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x3_out_end_in_data.vec.data();
                    for (int j=0; j<x3_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x3"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x3_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x3_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x3: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x4_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X4_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x4_size = 
            (s = getenv("X4_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x4: mpi start_out_x4_in_data\n");
        auto start_out_x4_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x4: mpi x4_out_end_in_data\n");
        auto x4_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x4_out_end_in_data.vec.resize(x4_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x4_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x4_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x4_in_data.vec.data();
                    int start_out_x4_in_sum = 0;
                    for (int j=0; j<start_out_x4_in_data.vec.size(); ++j) {
                        start_out_x4_in_sum += data[j];  // start_out_x4_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x4: i = %d, first = %d, start_out_x4_in_sum = %d\n", i, start_out_x4_in_data.vec[0], start_out_x4_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x4_out_end_in_data.vec.data();
                    for (int j=0; j<x4_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x4"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x4_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x4_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x4: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x5_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X5_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x5_size = 
            (s = getenv("X5_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x5: mpi start_out_x5_in_data\n");
        auto start_out_x5_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x5: mpi x5_out_end_in_data\n");
        auto x5_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x5_out_end_in_data.vec.resize(x5_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x5_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x5_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x5_in_data.vec.data();
                    int start_out_x5_in_sum = 0;
                    for (int j=0; j<start_out_x5_in_data.vec.size(); ++j) {
                        start_out_x5_in_sum += data[j];  // start_out_x5_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x5: i = %d, first = %d, start_out_x5_in_sum = %d\n", i, start_out_x5_in_data.vec[0], start_out_x5_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x5_out_end_in_data.vec.data();
                    for (int j=0; j<x5_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x5"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x5_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x5_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x5: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x6_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X6_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x6_size = 
            (s = getenv("X6_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x6: mpi start_out_x6_in_data\n");
        auto start_out_x6_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x6: mpi x6_out_end_in_data\n");
        auto x6_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x6_out_end_in_data.vec.resize(x6_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x6_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x6_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x6_in_data.vec.data();
                    int start_out_x6_in_sum = 0;
                    for (int j=0; j<start_out_x6_in_data.vec.size(); ++j) {
                        start_out_x6_in_sum += data[j];  // start_out_x6_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x6: i = %d, first = %d, start_out_x6_in_sum = %d\n", i, start_out_x6_in_data.vec[0], start_out_x6_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x6_out_end_in_data.vec.data();
                    for (int j=0; j<x6_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x6"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x6_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x6_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x6: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x7_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X7_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x7_size = 
            (s = getenv("X7_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x7: mpi start_out_x7_in_data\n");
        auto start_out_x7_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x7: mpi x7_out_end_in_data\n");
        auto x7_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x7_out_end_in_data.vec.resize(x7_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x7_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x7_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x7_in_data.vec.data();
                    int start_out_x7_in_sum = 0;
                    for (int j=0; j<start_out_x7_in_data.vec.size(); ++j) {
                        start_out_x7_in_sum += data[j];  // start_out_x7_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x7: i = %d, first = %d, start_out_x7_in_sum = %d\n", i, start_out_x7_in_data.vec[0], start_out_x7_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x7_out_end_in_data.vec.data();
                    for (int j=0; j<x7_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x7"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x7_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x7_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x7: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    

    
    void workflow(std::string &name, size_t segment) {
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
            

            //std::fprintf(stderr, "end: starting\n");
            end_function(dhmem);
        
        } else if (rank == 2) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x1: starting\n");
            x1_function(dhmem);
        
        } else if (rank == 3) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x2: starting\n");
            x2_function(dhmem);
        
        } else if (rank == 4) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x3: starting\n");
            x3_function(dhmem);
        
        } else if (rank == 5) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x4: starting\n");
            x4_function(dhmem);
        
        } else if (rank == 6) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x5: starting\n");
            x5_function(dhmem);
        
        } else if (rank == 7) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x6: starting\n");
            x6_function(dhmem);
        
        } else if (rank == 8) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x7: starting\n");
            x7_function(dhmem);
        
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..? rank=%d expmax=%d\n", rank, 9);
        }

        MPI_Barrier(MPI_COMM_WORLD);
    }
    

    

    int main(int argc, char **argv) {
        char *s;
        std::string name;
        size_t segment;

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
                : 17179869184UL;

        workflow(name, segment);

        return 0;
    }
