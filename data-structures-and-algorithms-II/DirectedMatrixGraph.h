#pragma once

#include "MatrixGraph.h"
#include <ostream>

class DirectedMatrixGraph : public MatrixGraph {
public:
	DirectedMatrixGraph(int n) : MatrixGraph(n) {};

	int degree(int verticle);

	void addEdge(Edge edge);
	Edge* getAdjacentEdges(int verticle);
	Edge* getAllEdges();

	void print(std::ostream &out);
};