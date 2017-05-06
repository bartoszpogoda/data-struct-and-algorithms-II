#pragma once
#include "ListGraph.h"

#include <string>

class DirectedListGraph : public ListGraph {
public:
	DirectedListGraph(int n) : ListGraph(n) {};

	void addEdge(Edge edge);
	Edge* getAllEdges();

	std::string toString();
};