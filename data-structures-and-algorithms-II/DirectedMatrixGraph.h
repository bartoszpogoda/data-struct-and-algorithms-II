#pragma once

#include "MatrixGraph.h"
#include <ostream>

class DirectedMatrixGraph : public MatrixGraph {
public:
	DirectedMatrixGraph(int n);

	void addEdge(int beginV, int endV, int weight);
	int checkEdge(int beginV, int endV);
	void removeEdge(int beginV, int endV);
	int degree();

	void print(std::ostream &out);
};