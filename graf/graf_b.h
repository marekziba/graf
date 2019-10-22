#ifndef graf_h
#define graf_h

#include <iostream>
#include <vector>
#include <list>

class Graf {
private:
	std::vector< std::list<int> > _vertexList;
	int _n;
	std::vector<int> colors;
public:
	Graf(std::vector< std::list<int> > vertexList);
	Graf(const char* path);
	Graf();
	void fromFile(const char* path);
	void colorize();
	void printColors();
	void addEdge(int v1, int v2);
};

#endif /*graf_cpp*/