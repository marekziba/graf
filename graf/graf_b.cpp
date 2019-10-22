#include "graf.h"

Graf::Graf(std::vector< std::list<int> > vertexList) {
	_vertexList = vertexList;
	_n = vertexList.size();
}

void Graf::fromFile(const char* path) {
	std::cout << "konski chuj\n";
}

Graf::Graf(const char* path) {
	this->fromFile(path);
}

Graf::Graf() {
	colors.resize(1000);
	_vertexList.resize(1000);
	_n = 5;
}

void Graf::colorize() {

	bool* available = new bool[_n];

	for (int i = 0; i < _n; i++) {
		colors[i] = -1; available[i] = true;		// initially all vertices have unassigned color and all colors are available
	}

	colors[0] = 0;

	for (int i = 1; i < _n; i++) {

		std::list<int>::iterator j;
		for (j = _vertexList[i].begin(); j != _vertexList[i].end(); ++j) {
			if (colors[*j] != -1) {
				available[colors[*j]] = false;
			}
		}

		int col;
		for (col = 0; col < _n; col++) {
			if (available[col]) break;
		}

		colors[i] = col;

		for (j = _vertexList[i].begin(); j != _vertexList[i].end(); ++j) {
			if (colors[*j] != -1) {
				available[colors[*j]] = true;
			}
		}

	}
}

void Graf::printColors() {
	for (int i = 0; i < _n; i++) {
		std::cout << i << " -> " << colors[i] << "\n";
	}
}

void Graf::addEdge(int v1, int v2) {
	_vertexList[v1].push_back(v2);
	_vertexList[v2].push_back(v1);
}