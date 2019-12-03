#include "Solution.h"
#include <random>
#include <ctime>

Solution::Solution() {}

Solution::Solution(Graf &g, int ncolors){
	fitness = 0;
	_colors.resize(g.size());
	std::generate(_colors.begin(), _colors.end(), std::rand);

	for (int i = 0; i < _colors.size(); i++) {
		_colors[i] = _colors[i] % ncolors;
	}

	for (int i = 0; i < _colors.size(); i++) {
		for (int j = i+1; j < _colors.size(); j++) {
			if (_colors[i] == _colors[j] && g.checkEdge(i,j)) {
				this->fitness++;
				//std::cout << "invEdge\n";
			}
		}
	}
	//std::cout << fitness <<"\n";
}

int Solution::getFitness() {
	// Insert code here and git push
	return fitness;
}

bool Solution::operator < (Solution &s) {
	return this->fitness < s.fitness;
}

std::ostream& operator << (std::ostream& stream, Solution& s) {
	stream << "[";
	for (int i = 0; i < s._colors.size(); i++) {
		if (i == s._colors.size() - 1) {
			stream << s._colors[i] << "]";
		}
		else {
			stream << s._colors[i] << ", ";
		}
	}
	//out << stream.str();
	return stream;
}

int Solution::size() {
	return _colors.size();
}

int& Solution::operator [] (int i) {
	return _colors[i];
}

void Solution::mutate(Graf& g, int mode) {
	// Insert code here and git push
}