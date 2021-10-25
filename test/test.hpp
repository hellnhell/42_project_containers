#pragma once


#include "../vector/vector.hpp"
#include "../stack/stack.hpp"
#include "../map/map.hpp"


#include <type_traits>
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <math.h>
#include <assert.h>


#define GREEN    "\033[92m"
#define RED      "\033[91m"
#define RESET    "\033[0m"

#define WHITE   "\033[97m"
#define YELLOW  "\033[93m"
#define BLUE    "\033[94m" 
#define MAGENTA "\033[95m"

#define PUT_STR(str) (printf("\n%-4s%-15s%-4s", "->",str , ":"))
# define OK (printf(GREEN "[OK] " RESET))
# define KO (printf(RED "[KO] " RESET))

template <typename T>
void TEST(T first, T second) {
  if (first == second)
    OK;
  else
    KO;
};

int vector_test();
int map_test();
int stack_test();
