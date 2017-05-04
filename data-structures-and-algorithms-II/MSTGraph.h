#pragma once

#include "IndirectedListGraph.h"

class MSTGraph : public IndirectedListGraph {
	int weight;
public:
	MSTGraph(int n) : IndirectedListGraph(n), weight(0) {};

	void addEdge(Edge e) { IndirectedListGraph::addEdge(e); this->weight += e.getWeight(); }

	void print(std::ostream &out) { out << "To override;" << std::endl; }
};
