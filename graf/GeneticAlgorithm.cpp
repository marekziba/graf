#include "GeneticAlgorithm.h"
#include <iostream>
#include <ctime>
#include <random>

GeneticAlgorithm::GeneticAlgorithm(Graf& g, int ncolors) :
	_p(g, g.size(), ncolors), _g(g)
{
	_ncolors = ncolors;
}

int GeneticAlgorithm::run(int termCondition) {
	int nIter = 0;
	std::srand(std::time(nullptr));
	while (nIter <= termCondition && _p[0].getFitness() != 0) {
		_p.refresh();
		nIter++;
	}
	std::cout << "cmon do something\n";
	if (_p[0].getFitness() == 0) return 1;
	else return 0;
}

void GeneticAlgorithm::printResults() {
	std::cout << _p;
}

Solution& GeneticAlgorithm::getBest() {
	return _p[0];
}