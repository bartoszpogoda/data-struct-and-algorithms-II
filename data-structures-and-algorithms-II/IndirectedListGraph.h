#pragma once

#include "ListGraph.h"
#include <ostream>

class IndirectedListGraph : public ListGraph {
public:
	IndirectedListGraph(int n);

	void addEdge(int beginV, int endV, int weight);
	int checkEdge(int beginV, int endV);
	void removeEdge(int beginV, int endV);
	int degree();

	void print(std::ostream &out);
};