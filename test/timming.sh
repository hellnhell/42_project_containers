#!/bin/bash

clang++ -Wall -Wextra -Werror -std=c++98 timming.cpp -o timming_test
if [[ "$1" == "lldb" ]] ; then
    lldb timming_test
    rm -rf timming_test.dSYM
    rm timming_test
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./timming_test
    rm -rf timming_test.dSYM
    rm timming_test
    exit
fi
if [[ "$1" == "valgrind" ]] ; then
    valgrind ./timming_test
    rm -rf timming_test.dSYM
    rm timming_test
    exit
fi

./timming_test
rm timming_test