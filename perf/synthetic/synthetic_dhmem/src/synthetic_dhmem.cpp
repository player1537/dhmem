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
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x8_in_data\n");
        auto start_out_x8_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x9_in_data\n");
        auto start_out_x9_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x10_in_data\n");
        auto start_out_x10_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x11_in_data\n");
        auto start_out_x11_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x12_in_data\n");
        auto start_out_x12_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x13_in_data\n");
        auto start_out_x13_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x14_in_data\n");
        auto start_out_x14_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x15_in_data\n");
        auto start_out_x15_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x16_in_data\n");
        auto start_out_x16_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x17_in_data\n");
        auto start_out_x17_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x18_in_data\n");
        auto start_out_x18_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x19_in_data\n");
        auto start_out_x19_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x20_in_data\n");
        auto start_out_x20_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x21_in_data\n");
        auto start_out_x21_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x22_in_data\n");
        auto start_out_x22_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x23_in_data\n");
        auto start_out_x23_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x24_in_data\n");
        auto start_out_x24_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x25_in_data\n");
        auto start_out_x25_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x26_in_data\n");
        auto start_out_x26_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x27_in_data\n");
        auto start_out_x27_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x28_in_data\n");
        auto start_out_x28_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x29_in_data\n");
        auto start_out_x29_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x30_in_data\n");
        auto start_out_x30_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x31_in_data\n");
        auto start_out_x31_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "start: mpi start_out_x32_in_data\n");
        auto start_out_x32_in_data = mpi_data();
        
        

        
        

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
                
                start_out_x8_in_data.vec.resize(start_size);
                
                start_out_x9_in_data.vec.resize(start_size);
                
                start_out_x10_in_data.vec.resize(start_size);
                
                start_out_x11_in_data.vec.resize(start_size);
                
                start_out_x12_in_data.vec.resize(start_size);
                
                start_out_x13_in_data.vec.resize(start_size);
                
                start_out_x14_in_data.vec.resize(start_size);
                
                start_out_x15_in_data.vec.resize(start_size);
                
                start_out_x16_in_data.vec.resize(start_size);
                
                start_out_x17_in_data.vec.resize(start_size);
                
                start_out_x18_in_data.vec.resize(start_size);
                
                start_out_x19_in_data.vec.resize(start_size);
                
                start_out_x20_in_data.vec.resize(start_size);
                
                start_out_x21_in_data.vec.resize(start_size);
                
                start_out_x22_in_data.vec.resize(start_size);
                
                start_out_x23_in_data.vec.resize(start_size);
                
                start_out_x24_in_data.vec.resize(start_size);
                
                start_out_x25_in_data.vec.resize(start_size);
                
                start_out_x26_in_data.vec.resize(start_size);
                
                start_out_x27_in_data.vec.resize(start_size);
                
                start_out_x28_in_data.vec.resize(start_size);
                
                start_out_x29_in_data.vec.resize(start_size);
                
                start_out_x30_in_data.vec.resize(start_size);
                
                start_out_x31_in_data.vec.resize(start_size);
                
                start_out_x32_in_data.vec.resize(start_size);
                
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
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x8_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 9, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x8_in_data.vec.data(), vecsize, MPI_INT, 9, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x9_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 10, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x9_in_data.vec.data(), vecsize, MPI_INT, 10, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x10_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 11, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x10_in_data.vec.data(), vecsize, MPI_INT, 11, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x11_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 12, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x11_in_data.vec.data(), vecsize, MPI_INT, 12, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x12_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 13, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x12_in_data.vec.data(), vecsize, MPI_INT, 13, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x13_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 14, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x13_in_data.vec.data(), vecsize, MPI_INT, 14, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x14_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 15, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x14_in_data.vec.data(), vecsize, MPI_INT, 15, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x15_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 16, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x15_in_data.vec.data(), vecsize, MPI_INT, 16, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x16_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 17, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x16_in_data.vec.data(), vecsize, MPI_INT, 17, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x17_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 18, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x17_in_data.vec.data(), vecsize, MPI_INT, 18, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x18_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 19, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x18_in_data.vec.data(), vecsize, MPI_INT, 19, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x19_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 20, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x19_in_data.vec.data(), vecsize, MPI_INT, 20, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x20_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 21, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x20_in_data.vec.data(), vecsize, MPI_INT, 21, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x21_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 22, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x21_in_data.vec.data(), vecsize, MPI_INT, 22, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x22_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 23, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x22_in_data.vec.data(), vecsize, MPI_INT, 23, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x23_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 24, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x23_in_data.vec.data(), vecsize, MPI_INT, 24, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x24_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 25, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x24_in_data.vec.data(), vecsize, MPI_INT, 25, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x25_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 26, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x25_in_data.vec.data(), vecsize, MPI_INT, 26, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x26_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 27, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x26_in_data.vec.data(), vecsize, MPI_INT, 27, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x27_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 28, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x27_in_data.vec.data(), vecsize, MPI_INT, 28, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x28_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 29, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x28_in_data.vec.data(), vecsize, MPI_INT, 29, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x29_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 30, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x29_in_data.vec.data(), vecsize, MPI_INT, 30, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x30_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 31, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x30_in_data.vec.data(), vecsize, MPI_INT, 31, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x31_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 32, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x31_in_data.vec.data(), vecsize, MPI_INT, 32, 1, MPI_COMM_WORLD);
                }
                
                
                
                {
                    size_t vecsize;
                    vecsize = start_out_x32_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 33, 1, MPI_COMM_WORLD);
                    MPI_Send(start_out_x32_in_data.vec.data(), vecsize, MPI_INT, 33, 1, MPI_COMM_WORLD);
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
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x8_out_end_in_data\n");
        auto x8_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x9_out_end_in_data\n");
        auto x9_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x10_out_end_in_data\n");
        auto x10_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x11_out_end_in_data\n");
        auto x11_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x12_out_end_in_data\n");
        auto x12_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x13_out_end_in_data\n");
        auto x13_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x14_out_end_in_data\n");
        auto x14_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x15_out_end_in_data\n");
        auto x15_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x16_out_end_in_data\n");
        auto x16_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x17_out_end_in_data\n");
        auto x17_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x18_out_end_in_data\n");
        auto x18_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x19_out_end_in_data\n");
        auto x19_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x20_out_end_in_data\n");
        auto x20_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x21_out_end_in_data\n");
        auto x21_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x22_out_end_in_data\n");
        auto x22_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x23_out_end_in_data\n");
        auto x23_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x24_out_end_in_data\n");
        auto x24_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x25_out_end_in_data\n");
        auto x25_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x26_out_end_in_data\n");
        auto x26_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x27_out_end_in_data\n");
        auto x27_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x28_out_end_in_data\n");
        auto x28_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x29_out_end_in_data\n");
        auto x29_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x30_out_end_in_data\n");
        auto x30_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x31_out_end_in_data\n");
        auto x31_out_end_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "end: mpi x32_out_end_in_data\n");
        auto x32_out_end_in_data = mpi_data();
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

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
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 9, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x8_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x8_out_end_in_data.vec.data(), vecsize, MPI_INT, 9, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 10, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x9_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x9_out_end_in_data.vec.data(), vecsize, MPI_INT, 10, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 11, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x10_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x10_out_end_in_data.vec.data(), vecsize, MPI_INT, 11, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 12, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x11_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x11_out_end_in_data.vec.data(), vecsize, MPI_INT, 12, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 13, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x12_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x12_out_end_in_data.vec.data(), vecsize, MPI_INT, 13, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 14, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x13_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x13_out_end_in_data.vec.data(), vecsize, MPI_INT, 14, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 15, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x14_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x14_out_end_in_data.vec.data(), vecsize, MPI_INT, 15, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 16, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x15_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x15_out_end_in_data.vec.data(), vecsize, MPI_INT, 16, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 17, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x16_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x16_out_end_in_data.vec.data(), vecsize, MPI_INT, 17, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 18, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x17_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x17_out_end_in_data.vec.data(), vecsize, MPI_INT, 18, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 19, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x18_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x18_out_end_in_data.vec.data(), vecsize, MPI_INT, 19, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 20, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x19_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x19_out_end_in_data.vec.data(), vecsize, MPI_INT, 20, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 21, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x20_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x20_out_end_in_data.vec.data(), vecsize, MPI_INT, 21, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 22, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x21_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x21_out_end_in_data.vec.data(), vecsize, MPI_INT, 22, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 23, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x22_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x22_out_end_in_data.vec.data(), vecsize, MPI_INT, 23, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 24, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x23_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x23_out_end_in_data.vec.data(), vecsize, MPI_INT, 24, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 25, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x24_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x24_out_end_in_data.vec.data(), vecsize, MPI_INT, 25, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 26, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x25_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x25_out_end_in_data.vec.data(), vecsize, MPI_INT, 26, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 27, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x26_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x26_out_end_in_data.vec.data(), vecsize, MPI_INT, 27, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 28, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x27_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x27_out_end_in_data.vec.data(), vecsize, MPI_INT, 28, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 29, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x28_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x28_out_end_in_data.vec.data(), vecsize, MPI_INT, 29, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 30, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x29_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x29_out_end_in_data.vec.data(), vecsize, MPI_INT, 30, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 31, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x30_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x30_out_end_in_data.vec.data(), vecsize, MPI_INT, 31, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 32, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x31_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x31_out_end_in_data.vec.data(), vecsize, MPI_INT, 32, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 33, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    x32_out_end_in_data.vec.resize(vecsize);
                    MPI_Recv(x32_out_end_in_data.vec.data(), vecsize, MPI_INT, 33, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
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
                
                {
                    int *data = x8_out_end_in_data.vec.data();
                    int x8_out_end_in_sum = 0;
                    for (int j=0; j<x8_out_end_in_data.vec.size(); ++j) {
                        x8_out_end_in_sum += data[j];  // x8_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x8_out_end_in_sum = %d\n", i, x8_out_end_in_data.vec[0], x8_out_end_in_sum);
                }
                
                {
                    int *data = x9_out_end_in_data.vec.data();
                    int x9_out_end_in_sum = 0;
                    for (int j=0; j<x9_out_end_in_data.vec.size(); ++j) {
                        x9_out_end_in_sum += data[j];  // x9_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x9_out_end_in_sum = %d\n", i, x9_out_end_in_data.vec[0], x9_out_end_in_sum);
                }
                
                {
                    int *data = x10_out_end_in_data.vec.data();
                    int x10_out_end_in_sum = 0;
                    for (int j=0; j<x10_out_end_in_data.vec.size(); ++j) {
                        x10_out_end_in_sum += data[j];  // x10_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x10_out_end_in_sum = %d\n", i, x10_out_end_in_data.vec[0], x10_out_end_in_sum);
                }
                
                {
                    int *data = x11_out_end_in_data.vec.data();
                    int x11_out_end_in_sum = 0;
                    for (int j=0; j<x11_out_end_in_data.vec.size(); ++j) {
                        x11_out_end_in_sum += data[j];  // x11_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x11_out_end_in_sum = %d\n", i, x11_out_end_in_data.vec[0], x11_out_end_in_sum);
                }
                
                {
                    int *data = x12_out_end_in_data.vec.data();
                    int x12_out_end_in_sum = 0;
                    for (int j=0; j<x12_out_end_in_data.vec.size(); ++j) {
                        x12_out_end_in_sum += data[j];  // x12_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x12_out_end_in_sum = %d\n", i, x12_out_end_in_data.vec[0], x12_out_end_in_sum);
                }
                
                {
                    int *data = x13_out_end_in_data.vec.data();
                    int x13_out_end_in_sum = 0;
                    for (int j=0; j<x13_out_end_in_data.vec.size(); ++j) {
                        x13_out_end_in_sum += data[j];  // x13_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x13_out_end_in_sum = %d\n", i, x13_out_end_in_data.vec[0], x13_out_end_in_sum);
                }
                
                {
                    int *data = x14_out_end_in_data.vec.data();
                    int x14_out_end_in_sum = 0;
                    for (int j=0; j<x14_out_end_in_data.vec.size(); ++j) {
                        x14_out_end_in_sum += data[j];  // x14_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x14_out_end_in_sum = %d\n", i, x14_out_end_in_data.vec[0], x14_out_end_in_sum);
                }
                
                {
                    int *data = x15_out_end_in_data.vec.data();
                    int x15_out_end_in_sum = 0;
                    for (int j=0; j<x15_out_end_in_data.vec.size(); ++j) {
                        x15_out_end_in_sum += data[j];  // x15_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x15_out_end_in_sum = %d\n", i, x15_out_end_in_data.vec[0], x15_out_end_in_sum);
                }
                
                {
                    int *data = x16_out_end_in_data.vec.data();
                    int x16_out_end_in_sum = 0;
                    for (int j=0; j<x16_out_end_in_data.vec.size(); ++j) {
                        x16_out_end_in_sum += data[j];  // x16_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x16_out_end_in_sum = %d\n", i, x16_out_end_in_data.vec[0], x16_out_end_in_sum);
                }
                
                {
                    int *data = x17_out_end_in_data.vec.data();
                    int x17_out_end_in_sum = 0;
                    for (int j=0; j<x17_out_end_in_data.vec.size(); ++j) {
                        x17_out_end_in_sum += data[j];  // x17_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x17_out_end_in_sum = %d\n", i, x17_out_end_in_data.vec[0], x17_out_end_in_sum);
                }
                
                {
                    int *data = x18_out_end_in_data.vec.data();
                    int x18_out_end_in_sum = 0;
                    for (int j=0; j<x18_out_end_in_data.vec.size(); ++j) {
                        x18_out_end_in_sum += data[j];  // x18_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x18_out_end_in_sum = %d\n", i, x18_out_end_in_data.vec[0], x18_out_end_in_sum);
                }
                
                {
                    int *data = x19_out_end_in_data.vec.data();
                    int x19_out_end_in_sum = 0;
                    for (int j=0; j<x19_out_end_in_data.vec.size(); ++j) {
                        x19_out_end_in_sum += data[j];  // x19_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x19_out_end_in_sum = %d\n", i, x19_out_end_in_data.vec[0], x19_out_end_in_sum);
                }
                
                {
                    int *data = x20_out_end_in_data.vec.data();
                    int x20_out_end_in_sum = 0;
                    for (int j=0; j<x20_out_end_in_data.vec.size(); ++j) {
                        x20_out_end_in_sum += data[j];  // x20_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x20_out_end_in_sum = %d\n", i, x20_out_end_in_data.vec[0], x20_out_end_in_sum);
                }
                
                {
                    int *data = x21_out_end_in_data.vec.data();
                    int x21_out_end_in_sum = 0;
                    for (int j=0; j<x21_out_end_in_data.vec.size(); ++j) {
                        x21_out_end_in_sum += data[j];  // x21_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x21_out_end_in_sum = %d\n", i, x21_out_end_in_data.vec[0], x21_out_end_in_sum);
                }
                
                {
                    int *data = x22_out_end_in_data.vec.data();
                    int x22_out_end_in_sum = 0;
                    for (int j=0; j<x22_out_end_in_data.vec.size(); ++j) {
                        x22_out_end_in_sum += data[j];  // x22_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x22_out_end_in_sum = %d\n", i, x22_out_end_in_data.vec[0], x22_out_end_in_sum);
                }
                
                {
                    int *data = x23_out_end_in_data.vec.data();
                    int x23_out_end_in_sum = 0;
                    for (int j=0; j<x23_out_end_in_data.vec.size(); ++j) {
                        x23_out_end_in_sum += data[j];  // x23_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x23_out_end_in_sum = %d\n", i, x23_out_end_in_data.vec[0], x23_out_end_in_sum);
                }
                
                {
                    int *data = x24_out_end_in_data.vec.data();
                    int x24_out_end_in_sum = 0;
                    for (int j=0; j<x24_out_end_in_data.vec.size(); ++j) {
                        x24_out_end_in_sum += data[j];  // x24_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x24_out_end_in_sum = %d\n", i, x24_out_end_in_data.vec[0], x24_out_end_in_sum);
                }
                
                {
                    int *data = x25_out_end_in_data.vec.data();
                    int x25_out_end_in_sum = 0;
                    for (int j=0; j<x25_out_end_in_data.vec.size(); ++j) {
                        x25_out_end_in_sum += data[j];  // x25_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x25_out_end_in_sum = %d\n", i, x25_out_end_in_data.vec[0], x25_out_end_in_sum);
                }
                
                {
                    int *data = x26_out_end_in_data.vec.data();
                    int x26_out_end_in_sum = 0;
                    for (int j=0; j<x26_out_end_in_data.vec.size(); ++j) {
                        x26_out_end_in_sum += data[j];  // x26_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x26_out_end_in_sum = %d\n", i, x26_out_end_in_data.vec[0], x26_out_end_in_sum);
                }
                
                {
                    int *data = x27_out_end_in_data.vec.data();
                    int x27_out_end_in_sum = 0;
                    for (int j=0; j<x27_out_end_in_data.vec.size(); ++j) {
                        x27_out_end_in_sum += data[j];  // x27_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x27_out_end_in_sum = %d\n", i, x27_out_end_in_data.vec[0], x27_out_end_in_sum);
                }
                
                {
                    int *data = x28_out_end_in_data.vec.data();
                    int x28_out_end_in_sum = 0;
                    for (int j=0; j<x28_out_end_in_data.vec.size(); ++j) {
                        x28_out_end_in_sum += data[j];  // x28_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x28_out_end_in_sum = %d\n", i, x28_out_end_in_data.vec[0], x28_out_end_in_sum);
                }
                
                {
                    int *data = x29_out_end_in_data.vec.data();
                    int x29_out_end_in_sum = 0;
                    for (int j=0; j<x29_out_end_in_data.vec.size(); ++j) {
                        x29_out_end_in_sum += data[j];  // x29_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x29_out_end_in_sum = %d\n", i, x29_out_end_in_data.vec[0], x29_out_end_in_sum);
                }
                
                {
                    int *data = x30_out_end_in_data.vec.data();
                    int x30_out_end_in_sum = 0;
                    for (int j=0; j<x30_out_end_in_data.vec.size(); ++j) {
                        x30_out_end_in_sum += data[j];  // x30_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x30_out_end_in_sum = %d\n", i, x30_out_end_in_data.vec[0], x30_out_end_in_sum);
                }
                
                {
                    int *data = x31_out_end_in_data.vec.data();
                    int x31_out_end_in_sum = 0;
                    for (int j=0; j<x31_out_end_in_data.vec.size(); ++j) {
                        x31_out_end_in_sum += data[j];  // x31_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x31_out_end_in_sum = %d\n", i, x31_out_end_in_data.vec[0], x31_out_end_in_sum);
                }
                
                {
                    int *data = x32_out_end_in_data.vec.data();
                    int x32_out_end_in_sum = 0;
                    for (int j=0; j<x32_out_end_in_data.vec.size(); ++j) {
                        x32_out_end_in_sum += data[j];  // x32_out_end_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "end: i = %d, first = %d, x32_out_end_in_sum = %d\n", i, x32_out_end_in_data.vec[0], x32_out_end_in_sum);
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
    
    void x8_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X8_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x8_size = 
            (s = getenv("X8_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x8: mpi start_out_x8_in_data\n");
        auto start_out_x8_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x8: mpi x8_out_end_in_data\n");
        auto x8_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x8_out_end_in_data.vec.resize(x8_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x8_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x8_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x8_in_data.vec.data();
                    int start_out_x8_in_sum = 0;
                    for (int j=0; j<start_out_x8_in_data.vec.size(); ++j) {
                        start_out_x8_in_sum += data[j];  // start_out_x8_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x8: i = %d, first = %d, start_out_x8_in_sum = %d\n", i, start_out_x8_in_data.vec[0], start_out_x8_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x8_out_end_in_data.vec.data();
                    for (int j=0; j<x8_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x8"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x8_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x8_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x8: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x9_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X9_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x9_size = 
            (s = getenv("X9_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x9: mpi start_out_x9_in_data\n");
        auto start_out_x9_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x9: mpi x9_out_end_in_data\n");
        auto x9_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x9_out_end_in_data.vec.resize(x9_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x9_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x9_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x9_in_data.vec.data();
                    int start_out_x9_in_sum = 0;
                    for (int j=0; j<start_out_x9_in_data.vec.size(); ++j) {
                        start_out_x9_in_sum += data[j];  // start_out_x9_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x9: i = %d, first = %d, start_out_x9_in_sum = %d\n", i, start_out_x9_in_data.vec[0], start_out_x9_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x9_out_end_in_data.vec.data();
                    for (int j=0; j<x9_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x9"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x9_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x9_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x9: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x10_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X10_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x10_size = 
            (s = getenv("X10_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x10: mpi start_out_x10_in_data\n");
        auto start_out_x10_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x10: mpi x10_out_end_in_data\n");
        auto x10_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x10_out_end_in_data.vec.resize(x10_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x10_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x10_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x10_in_data.vec.data();
                    int start_out_x10_in_sum = 0;
                    for (int j=0; j<start_out_x10_in_data.vec.size(); ++j) {
                        start_out_x10_in_sum += data[j];  // start_out_x10_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x10: i = %d, first = %d, start_out_x10_in_sum = %d\n", i, start_out_x10_in_data.vec[0], start_out_x10_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x10_out_end_in_data.vec.data();
                    for (int j=0; j<x10_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x10"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x10_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x10_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x10: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x11_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X11_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x11_size = 
            (s = getenv("X11_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x11: mpi start_out_x11_in_data\n");
        auto start_out_x11_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x11: mpi x11_out_end_in_data\n");
        auto x11_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x11_out_end_in_data.vec.resize(x11_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x11_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x11_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x11_in_data.vec.data();
                    int start_out_x11_in_sum = 0;
                    for (int j=0; j<start_out_x11_in_data.vec.size(); ++j) {
                        start_out_x11_in_sum += data[j];  // start_out_x11_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x11: i = %d, first = %d, start_out_x11_in_sum = %d\n", i, start_out_x11_in_data.vec[0], start_out_x11_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x11_out_end_in_data.vec.data();
                    for (int j=0; j<x11_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x11"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x11_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x11_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x11: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x12_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X12_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x12_size = 
            (s = getenv("X12_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x12: mpi start_out_x12_in_data\n");
        auto start_out_x12_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x12: mpi x12_out_end_in_data\n");
        auto x12_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x12_out_end_in_data.vec.resize(x12_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x12_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x12_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x12_in_data.vec.data();
                    int start_out_x12_in_sum = 0;
                    for (int j=0; j<start_out_x12_in_data.vec.size(); ++j) {
                        start_out_x12_in_sum += data[j];  // start_out_x12_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x12: i = %d, first = %d, start_out_x12_in_sum = %d\n", i, start_out_x12_in_data.vec[0], start_out_x12_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x12_out_end_in_data.vec.data();
                    for (int j=0; j<x12_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x12"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x12_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x12_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x12: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x13_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X13_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x13_size = 
            (s = getenv("X13_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x13: mpi start_out_x13_in_data\n");
        auto start_out_x13_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x13: mpi x13_out_end_in_data\n");
        auto x13_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x13_out_end_in_data.vec.resize(x13_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x13_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x13_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x13_in_data.vec.data();
                    int start_out_x13_in_sum = 0;
                    for (int j=0; j<start_out_x13_in_data.vec.size(); ++j) {
                        start_out_x13_in_sum += data[j];  // start_out_x13_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x13: i = %d, first = %d, start_out_x13_in_sum = %d\n", i, start_out_x13_in_data.vec[0], start_out_x13_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x13_out_end_in_data.vec.data();
                    for (int j=0; j<x13_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x13"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x13_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x13_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x13: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x14_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X14_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x14_size = 
            (s = getenv("X14_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x14: mpi start_out_x14_in_data\n");
        auto start_out_x14_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x14: mpi x14_out_end_in_data\n");
        auto x14_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x14_out_end_in_data.vec.resize(x14_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x14_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x14_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x14_in_data.vec.data();
                    int start_out_x14_in_sum = 0;
                    for (int j=0; j<start_out_x14_in_data.vec.size(); ++j) {
                        start_out_x14_in_sum += data[j];  // start_out_x14_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x14: i = %d, first = %d, start_out_x14_in_sum = %d\n", i, start_out_x14_in_data.vec[0], start_out_x14_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x14_out_end_in_data.vec.data();
                    for (int j=0; j<x14_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x14"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x14_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x14_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x14: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x15_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X15_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x15_size = 
            (s = getenv("X15_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x15: mpi start_out_x15_in_data\n");
        auto start_out_x15_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x15: mpi x15_out_end_in_data\n");
        auto x15_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x15_out_end_in_data.vec.resize(x15_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x15_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x15_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x15_in_data.vec.data();
                    int start_out_x15_in_sum = 0;
                    for (int j=0; j<start_out_x15_in_data.vec.size(); ++j) {
                        start_out_x15_in_sum += data[j];  // start_out_x15_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x15: i = %d, first = %d, start_out_x15_in_sum = %d\n", i, start_out_x15_in_data.vec[0], start_out_x15_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x15_out_end_in_data.vec.data();
                    for (int j=0; j<x15_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x15"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x15_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x15_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x15: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x16_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X16_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x16_size = 
            (s = getenv("X16_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x16: mpi start_out_x16_in_data\n");
        auto start_out_x16_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x16: mpi x16_out_end_in_data\n");
        auto x16_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x16_out_end_in_data.vec.resize(x16_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x16_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x16_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x16_in_data.vec.data();
                    int start_out_x16_in_sum = 0;
                    for (int j=0; j<start_out_x16_in_data.vec.size(); ++j) {
                        start_out_x16_in_sum += data[j];  // start_out_x16_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x16: i = %d, first = %d, start_out_x16_in_sum = %d\n", i, start_out_x16_in_data.vec[0], start_out_x16_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x16_out_end_in_data.vec.data();
                    for (int j=0; j<x16_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x16"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x16_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x16_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x16: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x17_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X17_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x17_size = 
            (s = getenv("X17_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x17: mpi start_out_x17_in_data\n");
        auto start_out_x17_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x17: mpi x17_out_end_in_data\n");
        auto x17_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x17_out_end_in_data.vec.resize(x17_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x17_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x17_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x17_in_data.vec.data();
                    int start_out_x17_in_sum = 0;
                    for (int j=0; j<start_out_x17_in_data.vec.size(); ++j) {
                        start_out_x17_in_sum += data[j];  // start_out_x17_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x17: i = %d, first = %d, start_out_x17_in_sum = %d\n", i, start_out_x17_in_data.vec[0], start_out_x17_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x17_out_end_in_data.vec.data();
                    for (int j=0; j<x17_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x17"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x17_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x17_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x17: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x18_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X18_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x18_size = 
            (s = getenv("X18_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x18: mpi start_out_x18_in_data\n");
        auto start_out_x18_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x18: mpi x18_out_end_in_data\n");
        auto x18_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x18_out_end_in_data.vec.resize(x18_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x18_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x18_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x18_in_data.vec.data();
                    int start_out_x18_in_sum = 0;
                    for (int j=0; j<start_out_x18_in_data.vec.size(); ++j) {
                        start_out_x18_in_sum += data[j];  // start_out_x18_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x18: i = %d, first = %d, start_out_x18_in_sum = %d\n", i, start_out_x18_in_data.vec[0], start_out_x18_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x18_out_end_in_data.vec.data();
                    for (int j=0; j<x18_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x18"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x18_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x18_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x18: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x19_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X19_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x19_size = 
            (s = getenv("X19_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x19: mpi start_out_x19_in_data\n");
        auto start_out_x19_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x19: mpi x19_out_end_in_data\n");
        auto x19_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x19_out_end_in_data.vec.resize(x19_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x19_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x19_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x19_in_data.vec.data();
                    int start_out_x19_in_sum = 0;
                    for (int j=0; j<start_out_x19_in_data.vec.size(); ++j) {
                        start_out_x19_in_sum += data[j];  // start_out_x19_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x19: i = %d, first = %d, start_out_x19_in_sum = %d\n", i, start_out_x19_in_data.vec[0], start_out_x19_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x19_out_end_in_data.vec.data();
                    for (int j=0; j<x19_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x19"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x19_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x19_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x19: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x20_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X20_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x20_size = 
            (s = getenv("X20_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x20: mpi start_out_x20_in_data\n");
        auto start_out_x20_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x20: mpi x20_out_end_in_data\n");
        auto x20_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x20_out_end_in_data.vec.resize(x20_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x20_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x20_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x20_in_data.vec.data();
                    int start_out_x20_in_sum = 0;
                    for (int j=0; j<start_out_x20_in_data.vec.size(); ++j) {
                        start_out_x20_in_sum += data[j];  // start_out_x20_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x20: i = %d, first = %d, start_out_x20_in_sum = %d\n", i, start_out_x20_in_data.vec[0], start_out_x20_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x20_out_end_in_data.vec.data();
                    for (int j=0; j<x20_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x20"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x20_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x20_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x20: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x21_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X21_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x21_size = 
            (s = getenv("X21_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x21: mpi start_out_x21_in_data\n");
        auto start_out_x21_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x21: mpi x21_out_end_in_data\n");
        auto x21_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x21_out_end_in_data.vec.resize(x21_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x21_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x21_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x21_in_data.vec.data();
                    int start_out_x21_in_sum = 0;
                    for (int j=0; j<start_out_x21_in_data.vec.size(); ++j) {
                        start_out_x21_in_sum += data[j];  // start_out_x21_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x21: i = %d, first = %d, start_out_x21_in_sum = %d\n", i, start_out_x21_in_data.vec[0], start_out_x21_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x21_out_end_in_data.vec.data();
                    for (int j=0; j<x21_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x21"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x21_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x21_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x21: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x22_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X22_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x22_size = 
            (s = getenv("X22_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x22: mpi start_out_x22_in_data\n");
        auto start_out_x22_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x22: mpi x22_out_end_in_data\n");
        auto x22_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x22_out_end_in_data.vec.resize(x22_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x22_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x22_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x22_in_data.vec.data();
                    int start_out_x22_in_sum = 0;
                    for (int j=0; j<start_out_x22_in_data.vec.size(); ++j) {
                        start_out_x22_in_sum += data[j];  // start_out_x22_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x22: i = %d, first = %d, start_out_x22_in_sum = %d\n", i, start_out_x22_in_data.vec[0], start_out_x22_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x22_out_end_in_data.vec.data();
                    for (int j=0; j<x22_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x22"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x22_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x22_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x22: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x23_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X23_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x23_size = 
            (s = getenv("X23_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x23: mpi start_out_x23_in_data\n");
        auto start_out_x23_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x23: mpi x23_out_end_in_data\n");
        auto x23_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x23_out_end_in_data.vec.resize(x23_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x23_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x23_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x23_in_data.vec.data();
                    int start_out_x23_in_sum = 0;
                    for (int j=0; j<start_out_x23_in_data.vec.size(); ++j) {
                        start_out_x23_in_sum += data[j];  // start_out_x23_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x23: i = %d, first = %d, start_out_x23_in_sum = %d\n", i, start_out_x23_in_data.vec[0], start_out_x23_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x23_out_end_in_data.vec.data();
                    for (int j=0; j<x23_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x23"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x23_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x23_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x23: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x24_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X24_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x24_size = 
            (s = getenv("X24_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x24: mpi start_out_x24_in_data\n");
        auto start_out_x24_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x24: mpi x24_out_end_in_data\n");
        auto x24_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x24_out_end_in_data.vec.resize(x24_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x24_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x24_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x24_in_data.vec.data();
                    int start_out_x24_in_sum = 0;
                    for (int j=0; j<start_out_x24_in_data.vec.size(); ++j) {
                        start_out_x24_in_sum += data[j];  // start_out_x24_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x24: i = %d, first = %d, start_out_x24_in_sum = %d\n", i, start_out_x24_in_data.vec[0], start_out_x24_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x24_out_end_in_data.vec.data();
                    for (int j=0; j<x24_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x24"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x24_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x24_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x24: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x25_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X25_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x25_size = 
            (s = getenv("X25_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x25: mpi start_out_x25_in_data\n");
        auto start_out_x25_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x25: mpi x25_out_end_in_data\n");
        auto x25_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x25_out_end_in_data.vec.resize(x25_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x25_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x25_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x25_in_data.vec.data();
                    int start_out_x25_in_sum = 0;
                    for (int j=0; j<start_out_x25_in_data.vec.size(); ++j) {
                        start_out_x25_in_sum += data[j];  // start_out_x25_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x25: i = %d, first = %d, start_out_x25_in_sum = %d\n", i, start_out_x25_in_data.vec[0], start_out_x25_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x25_out_end_in_data.vec.data();
                    for (int j=0; j<x25_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x25"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x25_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x25_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x25: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x26_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X26_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x26_size = 
            (s = getenv("X26_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x26: mpi start_out_x26_in_data\n");
        auto start_out_x26_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x26: mpi x26_out_end_in_data\n");
        auto x26_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x26_out_end_in_data.vec.resize(x26_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x26_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x26_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x26_in_data.vec.data();
                    int start_out_x26_in_sum = 0;
                    for (int j=0; j<start_out_x26_in_data.vec.size(); ++j) {
                        start_out_x26_in_sum += data[j];  // start_out_x26_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x26: i = %d, first = %d, start_out_x26_in_sum = %d\n", i, start_out_x26_in_data.vec[0], start_out_x26_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x26_out_end_in_data.vec.data();
                    for (int j=0; j<x26_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x26"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x26_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x26_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x26: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x27_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X27_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x27_size = 
            (s = getenv("X27_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x27: mpi start_out_x27_in_data\n");
        auto start_out_x27_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x27: mpi x27_out_end_in_data\n");
        auto x27_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x27_out_end_in_data.vec.resize(x27_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x27_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x27_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x27_in_data.vec.data();
                    int start_out_x27_in_sum = 0;
                    for (int j=0; j<start_out_x27_in_data.vec.size(); ++j) {
                        start_out_x27_in_sum += data[j];  // start_out_x27_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x27: i = %d, first = %d, start_out_x27_in_sum = %d\n", i, start_out_x27_in_data.vec[0], start_out_x27_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x27_out_end_in_data.vec.data();
                    for (int j=0; j<x27_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x27"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x27_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x27_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x27: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x28_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X28_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x28_size = 
            (s = getenv("X28_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x28: mpi start_out_x28_in_data\n");
        auto start_out_x28_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x28: mpi x28_out_end_in_data\n");
        auto x28_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x28_out_end_in_data.vec.resize(x28_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x28_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x28_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x28_in_data.vec.data();
                    int start_out_x28_in_sum = 0;
                    for (int j=0; j<start_out_x28_in_data.vec.size(); ++j) {
                        start_out_x28_in_sum += data[j];  // start_out_x28_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x28: i = %d, first = %d, start_out_x28_in_sum = %d\n", i, start_out_x28_in_data.vec[0], start_out_x28_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x28_out_end_in_data.vec.data();
                    for (int j=0; j<x28_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x28"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x28_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x28_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x28: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x29_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X29_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x29_size = 
            (s = getenv("X29_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x29: mpi start_out_x29_in_data\n");
        auto start_out_x29_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x29: mpi x29_out_end_in_data\n");
        auto x29_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x29_out_end_in_data.vec.resize(x29_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x29_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x29_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x29_in_data.vec.data();
                    int start_out_x29_in_sum = 0;
                    for (int j=0; j<start_out_x29_in_data.vec.size(); ++j) {
                        start_out_x29_in_sum += data[j];  // start_out_x29_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x29: i = %d, first = %d, start_out_x29_in_sum = %d\n", i, start_out_x29_in_data.vec[0], start_out_x29_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x29_out_end_in_data.vec.data();
                    for (int j=0; j<x29_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x29"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x29_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x29_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x29: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x30_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X30_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x30_size = 
            (s = getenv("X30_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x30: mpi start_out_x30_in_data\n");
        auto start_out_x30_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x30: mpi x30_out_end_in_data\n");
        auto x30_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x30_out_end_in_data.vec.resize(x30_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x30_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x30_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x30_in_data.vec.data();
                    int start_out_x30_in_sum = 0;
                    for (int j=0; j<start_out_x30_in_data.vec.size(); ++j) {
                        start_out_x30_in_sum += data[j];  // start_out_x30_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x30: i = %d, first = %d, start_out_x30_in_sum = %d\n", i, start_out_x30_in_data.vec[0], start_out_x30_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x30_out_end_in_data.vec.data();
                    for (int j=0; j<x30_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x30"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x30_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x30_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x30: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x31_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X31_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x31_size = 
            (s = getenv("X31_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x31: mpi start_out_x31_in_data\n");
        auto start_out_x31_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x31: mpi x31_out_end_in_data\n");
        auto x31_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x31_out_end_in_data.vec.resize(x31_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x31_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x31_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x31_in_data.vec.data();
                    int start_out_x31_in_sum = 0;
                    for (int j=0; j<start_out_x31_in_data.vec.size(); ++j) {
                        start_out_x31_in_sum += data[j];  // start_out_x31_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x31: i = %d, first = %d, start_out_x31_in_sum = %d\n", i, start_out_x31_in_data.vec[0], start_out_x31_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x31_out_end_in_data.vec.data();
                    for (int j=0; j<x31_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x31"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x31_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x31_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x31: loop took too %dus long\n", got_time - exp_time);
            } else {
                usleep(exp_time - got_time);
            }
            
        }
    }
    
    void x32_function(dhmem::Dhmem &dhmem) {
        
        char *s;

        
        int do_print =
            (s = getenv("DHMEM_PRINT"))
                ? atoi(s)
                : 0;

        
        

        
        
        useconds_t exp_time =
            (s = getenv("X32_TIME"))
                ? (useconds_t)atol(s)
                : 0;
        

        
        size_t maxiter =
            (s = getenv("DHMEM_MAXITER"))
                ? (size_t)atol(s)
                : 512;

        
        
        
        
        size_t x32_size = 
            (s = getenv("X32_SIZE"))
                ? (size_t)atol(s)
                : 2621440UL;
        
        
        
        

        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        

        
        
        
        if (do_print) std::fprintf(stderr, "x32: mpi start_out_x32_in_data\n");
        auto start_out_x32_in_data = mpi_data();
        
        
        
        if (do_print) std::fprintf(stderr, "x32: mpi x32_out_end_in_data\n");
        auto x32_out_end_in_data = mpi_data();
        
        

        
        
        
        

        for (int i=0; (maxiter ? i<maxiter : 1); ++i) {
            
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            

            
            if (i == 0) {
                
                x32_out_end_in_data.vec.resize(x32_size);
                
            }
            

            // receive
            {
                
                
                

                
                
                
                {
                    size_t vecsize;
                    MPI_Recv(&vecsize, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    start_out_x32_in_data.vec.resize(vecsize);
                    MPI_Recv(start_out_x32_in_data.vec.data(), vecsize, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
                
                

                
                
                
                
                
                

                
                
                
                

                
                {
                    int *data = start_out_x32_in_data.vec.data();
                    int start_out_x32_in_sum = 0;
                    for (int j=0; j<start_out_x32_in_data.vec.size(); ++j) {
                        start_out_x32_in_sum += data[j];  // start_out_x32_in_data.vec[j];
                    }
                    if (do_print) std::fprintf(stderr, "x32: i = %d, first = %d, start_out_x32_in_sum = %d\n", i, start_out_x32_in_data.vec[0], start_out_x32_in_sum);
                }
                

                
                
                

                
                
                
            }

            // send
            {
                
                
                

                
                
                
                {
                    int *data = x32_out_end_in_data.vec.data();
                    for (int j=0; j<x32_out_end_in_data.vec.size(); ++j) {
                        
                        data[j]
                            = 100 * 100 * 100 * ("x32"[0] - 'a' + 1)
                            + 100 * 100 *       ("end"[0] - 'a' + 1)
                            + 100 * i
                            + j;
                    }
                }
                
                
                
                

                
                
                
                

                
                
                
                {
                    size_t vecsize;
                    vecsize = x32_out_end_in_data.vec.size();
                    MPI_Send(&vecsize, 1, MPI_LONG, 1, 1, MPI_COMM_WORLD);
                    MPI_Send(x32_out_end_in_data.vec.data(), vecsize, MPI_INT, 1, 1, MPI_COMM_WORLD);
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
                if (do_print) std::fprintf(stderr, "x32: loop took too %dus long\n", got_time - exp_time);
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
        
        } else if (rank == 9) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x8: starting\n");
            x8_function(dhmem);
        
        } else if (rank == 10) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x9: starting\n");
            x9_function(dhmem);
        
        } else if (rank == 11) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x10: starting\n");
            x10_function(dhmem);
        
        } else if (rank == 12) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x11: starting\n");
            x11_function(dhmem);
        
        } else if (rank == 13) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x12: starting\n");
            x12_function(dhmem);
        
        } else if (rank == 14) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x13: starting\n");
            x13_function(dhmem);
        
        } else if (rank == 15) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x14: starting\n");
            x14_function(dhmem);
        
        } else if (rank == 16) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x15: starting\n");
            x15_function(dhmem);
        
        } else if (rank == 17) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x16: starting\n");
            x16_function(dhmem);
        
        } else if (rank == 18) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x17: starting\n");
            x17_function(dhmem);
        
        } else if (rank == 19) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x18: starting\n");
            x18_function(dhmem);
        
        } else if (rank == 20) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x19: starting\n");
            x19_function(dhmem);
        
        } else if (rank == 21) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x20: starting\n");
            x20_function(dhmem);
        
        } else if (rank == 22) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x21: starting\n");
            x21_function(dhmem);
        
        } else if (rank == 23) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x22: starting\n");
            x22_function(dhmem);
        
        } else if (rank == 24) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x23: starting\n");
            x23_function(dhmem);
        
        } else if (rank == 25) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x24: starting\n");
            x24_function(dhmem);
        
        } else if (rank == 26) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x25: starting\n");
            x25_function(dhmem);
        
        } else if (rank == 27) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x26: starting\n");
            x26_function(dhmem);
        
        } else if (rank == 28) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x27: starting\n");
            x27_function(dhmem);
        
        } else if (rank == 29) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x28: starting\n");
            x28_function(dhmem);
        
        } else if (rank == 30) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x29: starting\n");
            x29_function(dhmem);
        
        } else if (rank == 31) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x30: starting\n");
            x30_function(dhmem);
        
        } else if (rank == 32) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x31: starting\n");
            x31_function(dhmem);
        
        } else if (rank == 33) {
            
            MPI_Barrier(MPI_COMM_WORLD);
            dhmem::Dhmem dhmem(dhmem::open_only, name);
            

            //std::fprintf(stderr, "x32: starting\n");
            x32_function(dhmem);
        
        } else {
            std::fprintf(stderr, "Error: Wrong number of ranks..? rank=%d expmax=%d\n", rank, 34);
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
