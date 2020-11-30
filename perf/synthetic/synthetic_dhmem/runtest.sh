#!/usr/bin/env bash

cmake() {
    go.sh cmake "$@"
}

make() {
    go.sh make "$@"
}

timeit() {
    /usr/bin/time --format='%e,%U,%S' "$@" 2>&1 >/dev/null
}

def_simple() {
    np=2
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=1MB \
        a,b/period=0 \
        a/b/comm=${comm} \
        > definitions.txt
}

def_wide() {
    np=9
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=1MB \
        start,a,b,c,d,e,f,g,end/period=0 \
        start/a,b,c,d,e,f,g/comm=${comm} \
        a,b,c,d,e,f,g/end/comm=${comm} \
        > definitions.txt
}

def_long() {
    np=9
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=1MB \
        start,a,b,c,d,e,f,g,end/period=0 \
        start/a/comm=${comm} \
        a/b/comm=${comm} \
        b/c/comm=${comm} \
        c/d/comm=${comm} \
        d/e/comm=${comm} \
        e/f/comm=${comm} \
        f/g/comm=${comm} \
        g/end/comm=${comm} \
        > definitions.txt
}

comm_dhmem() {
    timeit go.sh exec stage/bin/perf_synthetic_dhmem
}

comm_mpi() {
    timeit mpirun -np ${np} go.sh exec stage/bin/perf_synthetic_dhmem
}

exec > >(tee -a results.txt)
printf $'def,maxiter,comm,real,user,sys\n'
for def in simple wide long; do
    for maxiter in 10240 20480; do
        for comm in dhmem mpi; do
            def_${def}
            cmake &>/dev/null
            make &>/dev/null
            printf $'%s,%s,%s,' ${def} ${maxiter} ${comm}
            comm_${comm}
        done
    done
done
