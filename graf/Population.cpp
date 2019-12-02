#include "Population.h"

Population::Population(Graf g, int n, int ncolors) {

	_solutions.resize(n);
	
	for (int i = 0; i < _solutions.size(); i++) {
		_solutions[i] = Solution(g.size(), ncolors);
	}

}