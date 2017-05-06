#pragma once
#include "MatrixGraph.h"

#include <ostream>

class DirectedMatrixGraph : public MatrixGraph {
public:
	DirectedMatrixGraph(int n) : MatrixGraph(n) {};

	void addEdge(Edge edge);
	Edge* getAllEdges();

	std::string toString();
};