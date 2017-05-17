#pragma once
#include "Graph.h"

/*
	First implemented but NOT USED for tests
*/
class GraphGeneratorInexact {
private:
	double maxError;

	void insertSkeleton(Graph * graph, int weightMin, int weightMax);
	bool insertEdges(Graph * graph, int weightMin, int weightMax, int edgeDensity);
	void insertSkeletonUndirected(Graph * graph, int weightMin, int weightMax);
	bool insertEdgesUndirected(Graph * graph, int weightMin, int weightMax, int edgeDensity);

public:
	GraphGeneratorInexact(int maxError) : maxError(maxError) {}

	bool fillGraph(Graph * graph, int weightRange, int edgeDensity);
	bool fillGraphUndirected(Graph * graph, int weightRange, int edgeDensity);
	int randomFirstVerticle(Graph* graph) { return rand() % graph->getSize(); }
};
