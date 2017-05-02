#pragma once

#include "Graph.h"
#include <ostream>

class MatrixGraph : public Graph {
protected:
	int** adjacencyMatrix;
public:
	MatrixGraph(int n) : Graph(n), adjacencyMatrix(new int*[n]) {}
	virtual ~MatrixGraph();
};