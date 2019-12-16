#pragma once
#include "Population.h"
#include <vector>

class GeneticAlgorithm
{
	Population _p;
	Graf _g;
	int _ncolors;
public:
	GeneticAlgorithm(Graf& g,int ncolors);
	int run(int);
	void printResults();
	Solution& getBest();
};

