// graf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "graf.h"
#include "Solution.h"
#include "Population.h"
#include "GeneticAlgorithm.h"

void generate(int nVerts, float density) {		// old function, working but it's far from perfect
	int nEdges = round((nVerts * (nVerts - 1)) / 2 * density);
	nEdges -= nVerts;
	//std::srad(std::time(nullptr));
	int randEdge, randVert = -1;
	std::vector< std::list<int> > vertices; vertices.resize(nVerts);
	for (int i = 0; i < nVerts; i++) {

		randEdge = std::rand() % nEdges;
		
		do {
			randVert = std::rand() % nVerts;
		} while (randVert == i);

		vertices[i].push_back(randVert);

		for (int j = 0; j < randEdge; j++) {
			
			do {
				randVert = std::rand() % nVerts;
			} while (randVert == i || std::find( std::begin(vertices[i]), std::end(vertices[i]), randVert ) != std::end(vertices[i]) );

			vertices[i].push_back(randVert);

		}

		nEdges -= randEdge;
	}

	Graf gxf(vertices);
	gxf.print();
}

void generate2(int nVerts, float density, std::string path) {		// this one works fine
	// the std::array can only be fixed-size, therefore we're forced to use vector of vectors 
	std::vector<std::vector<int>> adjMX; adjMX.resize(nVerts);		
	//	initializing the "array"

	std::ofstream outfile(path);

	outfile << nVerts << "\n";

	for (int i = 0; i < nVerts; i++) {
		adjMX[i].resize(nVerts);
	}
	//	filling with zeros
	for (int i = 0; i < nVerts; i++) {
		for (int j = 0; j < nVerts; j++) {
			adjMX[i][j] = 0;
		}
	}
	//	and now we're determining the amount of edges and generating them by randomly choosing two vertices
	int nEdges = round((nVerts * (nVerts - 1)) / 2 * density);
	int v1, v2;
	//std::srad(std::time(nullptr));
	for (int i = 0; i < nEdges; i++) {
		do {
			v1 = std::rand() % nVerts;
			v2 = std::rand() % nVerts;
		} while (v1 == v2 || adjMX[v1][v2] == 1 || adjMX[v2][v1] == 1);	// we need to check whether the edge is not a self-loop and hasn't been generated yet

		adjMX[v1][v2] = 1; adjMX[v2][v1] = 1;	// writing an edge to the matrix
		//std::cout << v1 << " --- " << v2 << "\n";
	}

	for (int i = 0; i < nVerts; i++) {
		for (int j = 0; j < nVerts; j++) {
			if (adjMX[i][j] == 1 && i < j) {
				outfile << i+1 << " " << j+1 << "\n";
			}
		}
	}

	outfile.close();
}


int main()
{
	std::string path = "C:/Users/Lenovo/Documents/OK/testpop.txt";
	generate2(24, 0.85, path);
	std::srand(std::time(nullptr));
	//std::cout << "X";
	Graf g1(path.c_str());
	//g1.print();
	std::cout << "\n\n\n";
	//g1.colorize();
	//g1.printColors();
	//Population p(g1,50,8);
	//std::cout << p;
	int ncolors = 24;
	GeneticAlgorithm genalg(g1,ncolors);
	genalg.printResults();
	std::cout << "\n" << "-----------------\n";
	while (genalg.run(20000) && ncolors > 0) {
		std::cout << "Found solution for " << ncolors << " colors!\n";
		std::cout << genalg.getBest() <<"\n";
		genalg = GeneticAlgorithm(g1, --ncolors);
	}
	genalg.printResults();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
