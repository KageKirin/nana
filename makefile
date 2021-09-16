CLANG_CPP_OPTS := --std=c++11

task1: task1.cpp
	clang++ ${CLANG_CPP_OPTS} -o $@ $<

include format.make
