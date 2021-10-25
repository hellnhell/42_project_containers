#!/bin/bash

clang++ -Wall -Wextra -Werror -std=c++98 stack.cpp -o stack_test
if [[ "$1" == "lldb" ]] ; then
    lldb stack_test
    rm -rf stack_test.dSYM
    rm stack_test
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./stack_test
    rm -rf stack_test.dSYM
    rm stack_test
    exit
fi
if [[ "$1" == "valgrind" ]] ; then
    valgrind ./stack_test
    rm -rf stack_test.dSYM
    rm stack_test
    exit
fi

./stack_test
rm stack_test