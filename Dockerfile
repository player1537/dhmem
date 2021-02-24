# Build stage with Spack pre-installed and ready to be used
FROM spack/ubuntu-bionic:latest as builder


# What we want to install and how we want to install it
# is specified in a manifest file (spack.yaml)
RUN mkdir /opt/spack-environment \
&&  (echo "spack:" \
&&   echo "  config:" \
&&   echo "    install_tree: /opt/software" \
&&   echo "  concretization: together" \
&&   echo "  specs:" \
&&   echo "  - boost" \
&&   echo "  - gcc" \
&&   echo "  - mpich@3.3.2" \
&&   echo "  - python@3.6.8" \
&&   echo "  view: /opt/view") > /opt/spack-environment/spack.yaml

# Install the software, remove unnecessary deps
RUN cd /opt/spack-environment && spack env activate . && spack install --fail-fast && spack gc -y

RUN cd /opt/spack-environment && spack env activate . && spack add cmake && spack install --fail-fast && spack gc -y

# Modifications to the environment that are necessary to run
RUN cd /opt/spack-environment && \
    spack env activate --sh -d . >> /etc/profile.d/z10_spack_environment.sh


# Bare OS image to run the installed executables
FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y \
        build-essential \
        time \
    && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /opt/spack-environment /opt/spack-environment
COPY --from=builder /opt/software /opt/software
COPY --from=builder /opt/view /opt/view
COPY --from=builder /etc/profile.d/z10_spack_environment.sh /etc/profile.d/z10_spack_environment.sh

ARG ENV=docker
ENV ENV=docker
WORKDIR /app
COPY . /app/

WORKDIR /app/perf/synthetic/synthetic_dhmem
RUN . /etc/profile && \
    python3 -m ensurepip && \
    python3 -m pip install virtualenv && \
    python3 -m virtualenv -p python3.6 venv && \
    venv/bin/pip install \
        jinja2 \
        dataclasses

WORKDIR /app
RUN ./go.sh cmake && \
    ./go.sh make

ENTRYPOINT ["/bin/bash", "--rcfile", "/etc/profile", "-l"]
