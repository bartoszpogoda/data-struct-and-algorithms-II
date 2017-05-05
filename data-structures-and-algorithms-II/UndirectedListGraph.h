#pragma once
#include "ListGraph.h"

#include <ostream>

class UndirectedListGraph : public ListGraph {
public:
	UndirectedListGraph(int n) : ListGraph(n) {};

	void addEdge(Edge edge);
	Edge* getAllEdges();

	void print(std::ostream &out);
};