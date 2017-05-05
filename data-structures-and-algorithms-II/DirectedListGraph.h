#pragma once
#include "ListGraph.h"

#include <ostream>

class DirectedListGraph : public ListGraph {
public:
	DirectedListGraph(int n) : ListGraph(n) {};

	void addEdge(Edge edge);
	Edge* getAllEdges();

	void print(std::ostream &out);
};