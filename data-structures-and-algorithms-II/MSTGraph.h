#pragma once
#include "UndirectedListGraph.h"

class MSTGraph : public UndirectedListGraph {
	int weight;
public:
	MSTGraph(int n) : UndirectedListGraph(n), weight(0) {};
	void addEdge(Edge e) { UndirectedListGraph::addEdge(e); this->weight += e.getWeight(); }

	std::string toString();
};
