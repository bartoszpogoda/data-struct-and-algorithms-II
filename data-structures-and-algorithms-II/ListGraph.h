#pragma once

#include "Graph.h"
#include"AdjacencyList.h"

class ListGraph : public Graph {
protected:
	AdjacencyList** adjacencyLists;
	ListGraph(int n);

	void print(std::ostream &out);
};