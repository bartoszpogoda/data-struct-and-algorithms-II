#pragma once

#include "ListGraph.h"
#include <ostream>

class IndirectedListGraph : public ListGraph {
public:
	IndirectedListGraph(int n) : ListGraph(n) {};

	int degree(int verticle);

	void addEdge(Edge edge);
	Edge* getAdjacentEdges(int verticle);
	Edge* getAllEdges();

};