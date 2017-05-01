#pragma once

#include "ListGraph.h"
#include <ostream>

class DirectedListGraph : public ListGraph {
public:
	DirectedListGraph(int n);

	void addEdge(int beginV, int endV, int weight);
	int checkEdge(int beginV, int endV);
	void removeEdge(int beginV, int endV);
	int degree();

	void print(std::ostream &out);
};