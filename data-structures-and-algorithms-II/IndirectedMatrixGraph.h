#pragma once

#include "MatrixGraph.h"
#include <ostream>

class IndirectedMatrixGraph : public MatrixGraph {
public:
	IndirectedMatrixGraph(int n);

	void addEdge(int beginV, int endV, int weight);
	int checkEdge(int beginV, int endV);
	void removeEdge(int beginV, int endV);
	int degree();

	void print(std::ostream &out);
};