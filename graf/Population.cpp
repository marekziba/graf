#include "Population.h"
#include <cmath>
#include <algorithm>

Population::Population(Graf g, int n, int ncolors) {

	_solutions.resize(n);
	
	for (int i = 0; i < _solutions.size(); i++) {
		_solutions[i] = Solution(g.size(), ncolors);
	}

}

void Population::refresh() {
	this->sort();
	int breakPoint = (int) round(_solutions.size() / 2);
	for (int i = breakPoint; i < _solutions.size(); i++) {
		_solutions[i] = Solution(_nverts, _ncolors);
	}
}

void Population::sort() {
	std::sort(_solutions.begin(), _solutions.end());
}