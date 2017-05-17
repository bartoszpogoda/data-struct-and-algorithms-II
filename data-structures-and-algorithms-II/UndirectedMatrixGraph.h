#pragma once
#include "MatrixGraph.h"

#include <string>

class UndirectedMatrixGraph : public MatrixGraph {
public:
	UndirectedMatrixGraph(int n) : MatrixGraph(n) {};

	void addEdge(Edge edge);
	void remEdge(Edge edge);
	Edge* getAllEdges();

	std::string toString();
};