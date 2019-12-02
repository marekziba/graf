#pragma once
#include "graf.h"

class Solution
{
	std::vector<int> _colors;
public:
	Solution(int nverts, int ncolors);
	int getFitness(Graf g);
};

