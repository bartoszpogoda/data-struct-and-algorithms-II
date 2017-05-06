#pragma once
#include "ListGraph.h"

#include <string>

class UndirectedListGraph : public ListGraph {
public:
	UndirectedListGraph(int n) : ListGraph(n) {};

	void addEdge(Edge edge);
	Edge* getAllEdges();

	std::string toString();
};