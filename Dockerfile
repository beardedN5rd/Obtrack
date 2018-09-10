FROM ubuntu:bionic

RUN apt-get update && apt-get install -y clang libboost-tools-dev libboost-test-dev
