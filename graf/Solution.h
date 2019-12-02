#pragma once
#include "graf.h"

class Solution
{
	std::vector<int> _colors;
	int fitness;
public:
	Solution(int nverts, int ncolors);
	int getFitness(Graf g);
};

