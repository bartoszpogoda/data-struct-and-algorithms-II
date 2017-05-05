#pragma once
#include "Graph.h"

#include <ostream>

class MatrixGraph : public Graph {
protected:
	int** adjacencyMatrix;
public:
	MatrixGraph(int n);
	virtual ~MatrixGraph();

	int degree(int verticle);
	Edge* getAdjacentEdges(int verticle);
};