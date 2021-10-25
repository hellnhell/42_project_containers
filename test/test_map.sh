#!/bin/bash

clang++ -Wall -Wextra -Werror -std=c++98 map.cpp -o map_test
if [[ "$1" == "lldb" ]] ; then
    lldb map_test
    rm -rf map_test.dSYM
    rm map_test
    exit
fi
if [[ "$1" == "leaks" ]] ; then
    leaks -atExit -- ./map_test
    rm -rf map_test.dSYM
    rm map_test
    exit
fi
if [[ "$1" == "valgrind" ]] ; then
    valgrind ./map_test
    rm -rf map_test.dSYM
    rm map_test
    exit
fi

./map_test
rm map_test