#pragma once

#include "Graph.h"
#include <ostream>

class MatrixGraph : public Graph {
protected:
	int** adjacencyMatrix;

	MatrixGraph(int n) : Graph(n), adjacencyMatrix(new int*[n]) {}
};