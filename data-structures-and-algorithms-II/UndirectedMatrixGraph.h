#pragma once
#include "MatrixGraph.h"

#include <ostream>

class UndirectedMatrixGraph : public MatrixGraph {
public:
	UndirectedMatrixGraph(int n) : MatrixGraph(n) {};

	void addEdge(Edge edge);
	Edge* getAllEdges();

	std::string toString();
};