#pragma once
#include "Population.h"
#include "Solution.h"

#define SEL_RANDOM 0
#define SEL_BEST 1

void crossover(Solution s1, Solution s2);

Solution reproduce(Population& p, Graf &g, int mode);