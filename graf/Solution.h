#pragma once
#include "graf.h"
#include <iostream>
#include <sstream>

class Solution
{
	std::vector<int> _colors;
	int fitness;
public:
	Solution();
	Solution(int nverts, int ncolors, int i);
	int getFitness(Graf g);
	bool operator < (Solution &s);
	friend std::ostream & operator << (std::ostream& out, Solution& s);
};