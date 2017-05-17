#pragma once
#include "Graph.h"

class GraphGenerator {
	double maxError;

	Edge randomEdge(int verticleRange, int weightRange);

public:
	GraphGenerator(double maxError) : maxError(maxError) {};

	void fillGraph(Graph* graph, int weightRange, double edgeDensity);
	bool fillGraphUndirected(Graph* graph, int weightRange, double edgeDensity);

	int randomFirstVerticle(Graph* graph) { return rand() % graph->getSize(); }
};