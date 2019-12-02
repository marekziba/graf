#include "Solution.h"
#include <random>
#include <ctime>

Solution::Solution() {}

Solution::Solution(int nverts, int ncolors, int i) {
	_colors.resize(nverts);
	std::generate(_colors.begin(), _colors.end(), std::rand);

	for (int i = 0; i < _colors.size(); i++) {
		_colors[i] = _colors[i] % ncolors;
	}
}

int Solution::getFitness(Graf g) {
	// Insert code here and git push
	return 0;
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