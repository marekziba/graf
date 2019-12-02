#pragma once
#include "graf.h"

class Population
{
	std::vector<Solution> _solutions;
	// Generate n randomly generated chromosomes. Used in constructor and in refresh() function.
	std::vector<Solution> generate(int n, int nverts, int ncolors);

	// Sorts the solutions (chromosomes) by their performance
	void sort();
public:

	// Create the population consisting of n randomly generated chromosomes
	Population(Graf g, int n, int ncolors);

	// Remove the worse performing half of solutions (chromosomes) and replace them with randomly generated ones 
	void refresh();
};

