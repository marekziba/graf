#pragma once
#include "graf.h"
#include <iostream>
#include <sstream>

class Solution
{
	std::vector<int> _colors;
	int fitness;
	//Graf _g;
public:
	Solution();
	Solution(Graf &g, int ncolors);
	int getFitness();
	bool operator < (Solution &s);
	friend std::ostream & operator << (std::ostream& out, Solution& s);
	int size();
	int & operator [] (int i);
	void mutate(Graf &g, int mode);
};