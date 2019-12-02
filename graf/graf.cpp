#include "graf.h"

Graf::Graf(std::vector< std::list<int> > vertexList) {
	_vertexList = vertexList;
	_n = vertexList.size();
	_vertexList.resize(_n); colors.resize(_n);
}

void Graf::fromFile(const char* path) {
	std::ifstream myfile;
	myfile.open(path);

	int x, y, vertices_count;

	if (myfile.is_open())
	{
		myfile >> _n;
		//std::cout << "Amount of vertices: " << _n << "\n";
		_vertexList.resize(_n); colors.resize(_n); 
		std::cout << _n << "\n";
		if (myfile.peek() == std::ifstream::traits_type::eof()) /*TODO: throw exception*/;
		else
		{
			while (myfile >> x >> y)
			{
				//std::cout << x << " -> " << y << "\n";
				this->addEdge(x-1, y-1);
			}
		}
		//std::cout << " _vertexList.size(" << _vertexList.size() << "); colors.size(" << colors.size() << ")\n";
	}
	else
	{
		//TODO: some kind of exception maybe, idk
	}
}

Graf::Graf(const char* path) {
	this->fromFile(path);
}


void Graf::colorize() {

	bool* available = new bool[_n];

	for (int i = 0; i < _n; i++) {
		colors[i] = -1; available[i] = true;		// initially all vertices have unassigned color and all colors are available
	}

	colors[0] = 0;		// first color is assigned to first vertex

	for (int i = 1; i < _n; i++) {

		for (auto j : _vertexList[i]) {
			if (colors[j] != -1) {
				available[colors[j]] = false;
			}
		}

		int col;
		for (col = 0; col < _n; col++) {
			if (available[col]) break;
		}

		colors[i] = col;

		for (auto j : _vertexList[i]) {
			if (colors[j] != -1) {
				available[colors[j]] = true;
			}
		}

	}
}

void Graf::printColors() {
	int max = 0;
	for (int i = 0; i < _n; i++) {
		if (colors[i]+1 > max) {
			max = colors[i]+1;
		}
		std::cout << i+1 << " -> " << colors[i]+1 << "\n";
	}

	std::cout << "\nTotal colors:\t" << max << "\n";
}

void Graf::addEdge(int v1, int v2) {
	_vertexList[v1].push_back(v2);
	_vertexList[v2].push_back(v1);
}

void Graf::print() {
	std::list<int>::iterator j;
	for (int i = 0; i < _n; i++) {
		std::cout << i + 1 <<" : ";
		for (j = _vertexList[i].begin(); j != _vertexList[i].end(); j++) {
			std::cout << *j+1 <<" ";
		}
		std::cout << "\n";
	}
}