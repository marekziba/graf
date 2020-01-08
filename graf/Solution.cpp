#include "Solution.h"
#include <random>
#include <ctime>
#include <algorithm>

Solution::Solution() {}

Solution::Solution(Graf &g, int ncolors){
	fitness = 0;
	_colors.resize(g.size());
	std::generate(_colors.begin(), _colors.end(), std::rand);

	for (int i = 0; i < _colors.size(); i++) {
		_colors[i] = _colors[i] % ncolors;
	}

	/*for (int i = 0; i < _colors.size(); i++) {
		for (int j = i+1; j < _colors.size(); j++) {
			if (_colors[i] == _colors[j] && g.checkEdge(i,j)) {
				this->fitness++;
				//std::cout << "invEdge\n";
			}
		}
	}*/
	calculateFitness(g);
	//std::cout << fitness <<"\n";
}

Solution::Solution(Graf &g, std::vector<int> v) {
	fitness = 0;
	_colors = v;
	calculateFitness(g);
}

int Solution::getFitness() {
	// Insert code here and git push
	return fitness;
}

void Solution::calculateFitness(Graf &g) {
	for (int i = 0; i < _colors.size(); i++) {
		for (int j = i + 1; j < _colors.size(); j++) {
			if (_colors[i] == _colors[j] && g.checkEdge(i, j)) {
				this->fitness++;
				//std::cout << "invEdge\n";
			}
		}
	}
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

void Solution::mutate(Graf& g, int ncolors, int mode) {
	//ncolors--;
	if (mode == 0) {
		std::vector<int> adjacent;
		int currentColor;
		int idx, cidx;
		std::vector<int> validColors, tmp, tmp2;
		for (int i = 0; i < ncolors; i++) {
			validColors.push_back(i);
		}
		for (int i = 0; i < _colors.size(); i++) {
			adjacent = g.getAdjacentVertices(i);
			tmp = validColors;
			tmp2 = {};
			currentColor = _colors[i];
			for (int j : adjacent) {
				if (_colors[j] == currentColor) {
					/*
					std::vector<int>::iterator position = std::find(validColors.begin(), validColors.end(), j);
					if (position != validColors.end()) {
						validColors.erase(position);
					}
					*/
					tmp[currentColor] = -1;
				}
			}
			for (int col : tmp) {
				if (col >= 0) {
					tmp2.push_back(col);
				}
			}
			cidx = std::rand() % tmp2.size();
			_colors[i] = tmp2[cidx];
			// copy validColors !!!
		}
	}
	else{
		std::vector<int> adjacent;
		int currentColor;
		int idx, cidx;
		bool goodColor;
		for (int i = 0; i < _colors.size(); i++) {
			goodColor = true;
			adjacent = g.getAdjacentVertices(i);
			currentColor = _colors[i];
			for (int j : adjacent) {
				if (_colors[j] == currentColor) {
					goodColor = false;
					break;
				}
			}
			if (!goodColor){
				int gh = std::rand() % ncolors;
				_colors[i] = gh;
			}
		}


	}
	

}















/*
void Solution::mutate(Graf& g, int ncolors, int mode) {
	std::vector<int> allColors, validColors, adjacent, tmp;
	int currentColor;
	for (int i = 0; i < _colors.size(); i++) {
		adjacent = g.getAdjacentVertices(i);
		tmp = validColors;
		for (int j = 0; j < adjacent.size(); j++) {

		}
	}
}
*/