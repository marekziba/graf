#include "Solution.h"
#include <random>
#include <ctime>

Solution::Solution(int nverts, int ncolors) {
	_colors.resize(nverts);
	std::srand(std::time(nullptr));
	for (int i = 0; i < _colors.size(); i++) {
		_colors[i] = std::rand() % ncolors;
	}
}

int Solution::getFitness(Graf g) {
	// Insert code here and git push
}