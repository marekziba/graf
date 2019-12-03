#pragma once
#include "graf.h"
#include "Solution.h"
#include <iostream>

class Population
{
	int _ncolors, _nverts;
	std::vector<Solution> _solutions;
	Graf _g;
	// Generate n randomly generated chromosomes. Used in constructor and in refresh() function.
	//std::vector<Solution> generate(int n, int nverts, int ncolors);

public:

	// Sorts the solutions (chromosomes) by their performance
	void sort();

	// Create the population consisting of n randomly generated chromosomes
	Population(Graf &g, int n, int ncolors);

	// Remove the worse performing half of solutions (chromosomes) and replace them with randomly generated ones 
	void refresh();
	friend std::ostream& operator << (std::ostream& out, Population& p);
	Solution& operator[] (int i);
	int size();
};

