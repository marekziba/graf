#include "Population.h"
#include "misc.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <ctime>

Population::Population(Graf &g, int n, int ncolors): _g(g) {

	_nverts = g.size(); _ncolors = ncolors;

	_solutions.resize(n);
	
	for (int i = 0; i < _solutions.size(); i++) {
		_solutions[i] = Solution(_g, ncolors);
		//std::cout << _solutions[i] <<"\n";
	}
	sort();
}

void Population::refresh() {
	this->sort();
	int breakPoint = (int) round(_solutions.size() / 2);
	for (int i = breakPoint; i < _solutions.size(); i++) {
		//getParents();
		//crossover

		// put this in main() later
		Solution child = reproduce(*this, _g, 0);
		child.mutate(_g, _ncolors, 1);
		_solutions[i] = child;
	}
}

void Population::sort() {
	std::sort(_solutions.begin(), _solutions.end());
}

std::ostream& operator << (std::ostream& out, Population& p) {
	for (Solution s : p._solutions) {
		out << s <<"\t" <<s.getFitness() <<"\n";
	}
	return out;
}

Solution& Population::operator[] (int i) {
	return _solutions[i];
}

int Population::size() {
	return _solutions.size();
}