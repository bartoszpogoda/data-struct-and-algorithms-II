#pragma once

#include "Graph.h"
#include"AdjacencyList.h"

class ListGraph : public Graph {
protected:
	AdjacencyList** adjacencyLists;
public:
	ListGraph(int n);
	virtual ~ListGraph();

	int degree(int verticle);
	Edge* getAdjacentEdges(int verticle);
};