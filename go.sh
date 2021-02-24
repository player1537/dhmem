#!/usr/bin/env bash

die() { printf $'Error: %s\n' "$*" >&2; exit 1; }

root=$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)
build=${root:?}/build
stage=${root:?}/stage

tag=dhmem_$USER:latest

examples=1
perf=

_env=${root:?}/${ENV:+${ENV}.}env.sh
[ -f "$_env" ] && . "$_env"

go-env() {
	"$@"
}

go-cmake() {
	[ -z "${SPACK_ENV:-}" ] && die "Not in a spack environment"

	cmake -H"${root:?}" -B"${build:?}" \
		-DCMAKE_INSTALL_PREFIX:PATH="${stage:?}" \
		-DCMAKE_C_COMPILER=gcc \
		-DCMAKE_CXX_COMPILER=g++ \
		${examples:+-Dbuild_examples:BOOL=YES} \
		${perf:+-Dbuild_perf:BOOL=YES} \
		-DPYBIND11_PYTHON_VERSION:STRING=3.6 \
        "$@"
}

go-make() {
	make -C "${build:?}" \
		VERBOSE=1 \
		"$@" \
	&& \
	make -C "${build:?}" \
		install
}

go-exec() {
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH:+${LD_LIBRARY_PATH:?}:}${stage:?}/lib
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH:+${LD_LIBRARY_PATH:?}:}${build:?}/examples/decaf_newtons_method/ext/Decaf/lib
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH:+${LD_LIBRARY_PATH:?}:}${build:?}/examples/decaf_newtons_method/ext/Henson/lib
	exec "$@"
}

go-grep() {
	shopt -s globstar
	grep "$@" -R "${root:?}"/{,**/}*.{cpp,hpp,h,c}
}

go-docker() { go-docker-"$@"; }

go-docker-build() {
	docker build \
		${tag:+--tag "$tag"} \
		${ENV:+--build-arg ENV="$ENV"} \
		${root:?}
}

go-docker-run() {
	docker run \
		-it \
		--rm \
		--shm-size 16GB \
		"${tag:?}"
}

go-docker-push() {
	tag=thobson2/dhmem:latest \
		go-docker-build
	docker push thobson2/dhmem:latest
}

go-"$@"
