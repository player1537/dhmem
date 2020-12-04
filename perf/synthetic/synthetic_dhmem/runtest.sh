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
        maxiter=${maxiter},print=0,segment=${segment} \
        a,b/period=${period} \
        a/b/comm=${comm},size=${size} \
        > definitions.txt
}

def_wide() {
    np=9
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=${segment} \
        start,a,b,c,d,e,f,g,end/period=${period} \
        start/a,b,c,d,e,f,g/comm=${comm},size=${size} \
        a,b,c,d,e,f,g/end/comm=${comm},size=${size} \
        > definitions.txt
}

def_long() {
    np=9
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=${segment} \
        start,a,b,c,d,e,f,g,end/period=${period} \
        start/a/comm=${comm},size=${size} \
        a/b/comm=${comm},size=${size} \
        b/c/comm=${comm},size=${size} \
        c/d/comm=${comm},size=${size} \
        d/e/comm=${comm},size=${size} \
        e/f/comm=${comm},size=${size} \
        f/g/comm=${comm},size=${size} \
        g/end/comm=${comm},size=${size} \
        > definitions.txt
}

comm_dhmem() {
    timeit go.sh exec stage/bin/perf_synthetic_dhmem
}

comm_mpi() {
    timeit mpirun -np ${np} go.sh exec stage/bin/perf_synthetic_dhmem
}

exec > >(tee -a results.txt)
printf $'def,maxiter,comm,segment,size,period,real,user,sys\n'
for segment in 1GB; do
for size in 10MB; do
for period in 0; do
for comm in hybrid dhmem mpi; do
for def in simple wide long; do
for maxiter in 1024 2048; do

def_${def}
cmake &>/dev/null
make &>/dev/null
printf $'%s,%s,%s,%s,%s,%s,' ${def} ${maxiter} ${comm} ${segment} ${size} ${period}
timeit mpirun -np ${np} go.sh exec stage/bin/perf_synthetic_dhmem

done
done
done
done
done
done
