#pragma once

#include "Graph.h"
#include"AdjacencyList.h"

class ListGraph : public Graph {
protected:
	AdjacencyList** adjacencyLists;
public:
	ListGraph(int n);
	virtual ~ListGraph();

	AdjacencyList** getAdjacencyLists() { return adjacencyLists; };
	void print(std::ostream &out);
};