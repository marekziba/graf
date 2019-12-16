#pragma once
#include "graf.h"
#include <iostream>
#include <sstream>

class Solution
{
	std::vector<int> _colors;
	int fitness;
	void calculateFitness(Graf &g);
	//Graf _g;
public:
	Solution();
	Solution(Graf &g, int ncolors);
	Solution(Graf &g, std::vector<int>);
	int getFitness();
	bool operator < (Solution &s);
	friend std::ostream & operator << (std::ostream& out, Solution& s);
	int size();
	int & operator [] (int i);
	void mutate(Graf &g, int ncolors, int mode);
};