#!/usr/bin/env bash

die() { printf $'Error: %s\n' "$*" >&2; exit 1; }

root=$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)
build=${root:?}/build
stage=${root:?}/stage

examples=1
perf=

ENV=${root:?}/${ENV:+${ENV}.}env.sh
[ -f "$ENV" ] && . "$ENV"

[ -z "${SPACK_ENV:-}" ] && die "Not in a spack environment"

go-env() {
	"$@"
}

go-cmake() {
	cmake -H"${root:?}" -B"${build:?}" \
		-DCMAKE_INSTALL_PREFIX:PATH="${stage:?}" \
		${examples:+-Dbuild_examples:BOOL=YES} \
		${perf:+-Dbuild_perf:BOOL=YES} \
        "$@" \
	&& \
	true
}

go-make() {
	make -C "${build:?}" \
		VERBOSE=1 \
		"$@" \
	&& \
	make -C "${build:?}" \
		install \
	&& \
	true
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

go-env go-"$@"
