#!/bin/bash

clang++ -Wall -Wextra -Werror -std=c++98 vector.cpp -o vector_test
if [[ "$1" == "lldb" ]] ; then
    lldb vector_test
    rm -rf vector_test.dSYM
    rm vector_test
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./vector_test
    rm -rf vector_test.dSYM
    rm vector_test
    exit
fi
if [[ "$1" == "valgrind" ]] ; then
    valgrind ./vector_test
    rm -rf vector_test.dSYM
    rm vector_test
    exit
fi

./vector_test
rm vector_test