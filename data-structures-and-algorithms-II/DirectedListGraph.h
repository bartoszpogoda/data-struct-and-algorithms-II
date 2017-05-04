#pragma once

#include "ListGraph.h"
#include <ostream>

class DirectedListGraph : public ListGraph {
public:
	DirectedListGraph(int n) : ListGraph(n) {};

	int degree(int verticle);

	void addEdge(Edge edge);
	Edge* getAdjacentEdges(int verticle);	
	Edge* getAllEdges();

};