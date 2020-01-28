#include "Population.h"
#include "misc.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <ctime>

#define MUTATION_PROBALITY 90

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

	// a wi�c zasadniczo to zmieni�em i teraz:

	this->sort();
	int breakPoint = (int) round(_solutions.size() / 2);
	int mode;
	for (int i = breakPoint; i < _solutions.size(); i++) {
		// najpierw tutaj dla do gorszej po�owy wektora wpisujemy nowe randomowe osobniki
		// (ten konstruktor generuje randomowe rozwi�zanie)
		_solutions[i] = Solution(_g, _ncolors);
	}
	this->sort();
	for (int i = breakPoint; i < (int)_solutions.size() / 2; i++) {
		// teraz zasadniczo sprawdzamy fitness populacji i wybieramy mode (tak jak by�o)
		if (_solutions[0].getFitness() > 4) {
			mode = 0;
		}
		else {
			mode = 1;
		}
		// znajdujemy rodzic�w wg wybranego mode i robimy crossover
		Solution child = reproduce(*this, _g, mode);
		// i mutujemy tego dzieciaka z pewnym prawdopodobie�stwm
		if (std::rand() % 100 < MUTATION_PROBALITY) {
			child.mutate(_g,_ncolors,mode);
		}
		// i na ko�cu dodajemy go do populacji
		// p�tla znowu leci po gorszej po�owie populacji (populacja zosta�a 
		// posortowana po dodaniu randomowych rozwi�za� wi�c nie jest tak �e 
		// usuwamy to co przed chwil� dodane, no chyba �e akurat wszystkie dodane
		// randomowe rozwi�zania znajd� si� akurat w tej gorszej po�owie - w sumie warto
		// to jako� sprawdzi�)
		_solutions[i] = child;
	}
	this->sort();
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