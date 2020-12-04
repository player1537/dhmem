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
        a,b/period=${period},size=${size} \
        a/b/comm=${comm} \
        > definitions.txt
}

def_wide() {
    np=9
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=${segment} \
        start,a,b,c,d,e,f,g,end/period=${period},size=${size} \
        start/a,b,c,d,e,f,g/comm=${comm} \
        a,b,c,d,e,f,g/end/comm=${comm} \
        > definitions.txt
}

def_long() {
    np=9
    printf $'%s\n' \
        maxiter=${maxiter},print=0,segment=${segment} \
        start,a,b,c,d,e,f,g,end/period=${period},size=${size} \
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
printf $'def,maxiter,comm,segment,size,period,real,user,sys\n'
for segment in 1GB; do
for size in 10MB; do
for period in 0; do
for comm in hybrid dhmem mpi; do
for def in wide simple long; do
for maxiter in 1024 2048; do
for n in {1..4}; do

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
done
