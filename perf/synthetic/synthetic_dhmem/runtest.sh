#!/usr/bin/env bash

PAIRS=( _ )
for ((i=0; i<1000; ++i)); do
    PAIRS+=( x$((i+1))/x$((i+2)) )
done

go.sh() {
    while ! [ -f "go.sh" ] && ! [ "$PWD" = "/" ]; do
        cd ..
    done
    
    if ! [ -f "go.sh" ]; then
        printf $'Error: go.sh not found\n' >&2
        exit 1
    fi
    
    "$PWD/go.sh" "$@"
}

cmake() {
    ../../../go.sh cmake "$@"
}

make() {
    ../../../go.sh make "$@"
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
    if [ "$m" = 0 ]; then
        def_simple
        return
    fi
    np=$((2+m))
    eval printf \$"'%s\n'" \
        maxiter=${maxiter},print=0,segment=${segment} \
        start,end/period=${period},size=${size} \
        x{1..$m}/period=${period},size=${size} \
        start/x{1..$m}/comm=${comm} \
        x{1..$m}/end/comm=${comm} \
        > definitions.txt
}

def_long() {
    np=$((2+m))
    eval eval printf '%s\\\\n' \
        maxiter=${maxiter},print=0,segment=${segment} \
        x{1..$np}/period=${period},size=${size} \
        \\\${PAIRS[{1..$(($m+1))}]}/comm=${comm} \
        > definitions.txt
}

comm_dhmem() {
    timeit ../../../go.sh exec ../../../stage/bin/perf_synthetic_dhmem
}

comm_mpi() {
    timeit mpirun -np ${np} ../../../go.sh exec ../../../stage/bin/perf_synthetic_dhmem
}

exec > >(tee -a results.txt)
printf $'def,maxiter,comm,segment,size,period,m,real,user,sys\n'
for m in 7 {1..5..2} {8..32..4}; do
for segment in 16GB; do
for period in 0; do
for size in 10MB; do
for def in long wide; do
for maxiter in 256 512; do
for comm in hybrid mpi; do
for n in {1..5}; do

def_${def}
cmake &>/dev/null
make &>/dev/null
printf $'%s,%s,%s,%s,%s,%s,%s,' ${def} ${maxiter} ${comm} ${segment} ${size} ${period} ${m}
timeit timeout 4m mpirun -np ${np} ../../../go.sh exec ../../../stage/bin/perf_synthetic_dhmem

done
done
done
done
done
done
done
done
