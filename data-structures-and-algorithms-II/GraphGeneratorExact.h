#pragma once
#include "Graph.h"

class GraphGeneratorExact {
	Edge randomEdge(int verticleRange, int weightRange);

public:
	void fillGraph(Graph* graph, int weightRange, double edgeDensity);
	void fillGraphUndirected(Graph* graph, int weightRange, double edgeDensity);
	int randomFirstVerticle(Graph* graph) { return rand() % graph->getSize(); }
};