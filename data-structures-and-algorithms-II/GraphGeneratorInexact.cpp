#include "GraphGeneratorInexact.h"

#include <iostream>

void GraphGeneratorInexact::insertSkeleton(Graph * graph, int weightMin, int weightMax) {
	int V = graph->getSize();

	for (size_t i = 0; i < V; i++) {
		graph->addEdge(Edge(i, (i + 1) % V, weightMin + rand() % (weightMax - weightMin)));
	}
}

bool GraphGeneratorInexact::insertEdges(Graph * graph, int weightMin, int weightMax, int edgeDensity) {
	int V = graph->getSize();
	int possibleEdges = V*V - V;
	int generatedEdges = 0;

	for (size_t i = 0; i < V; i++) {
		for (size_t j = 0; j < V; j++) {
			if (!(i + 1 == j) && !(i == V - 1 && j == 0) && rand() % 100 < edgeDensity) {
				graph->addEdge(Edge(i, j, weightMin + rand() % (weightMax - weightMin)));
				generatedEdges++;
			}
		}
	}

	std::cout << "RATIO: " << (double)generatedEdges / (double)possibleEdges << std::endl;

	if ((double)generatedEdges / (double)possibleEdges < edgeDensity - maxError || (double)generatedEdges / (double)possibleEdges > edgeDensity + maxError)
		return false;

	return true;
}

bool GraphGeneratorInexact::fillGraph(Graph * graph, int weightRange, int edgeDensity) {
	insertSkeleton(graph, weightRange*0.80, weightRange);
	return insertEdges(graph, 0, weightRange, edgeDensity);
}

void GraphGeneratorInexact::insertSkeletonUndirected(Graph * graph, int weightMin, int weightMax) {
	int V = graph->getSize();

	for (size_t i = 0; i < V - 1; i++) {
		graph->addEdge(Edge(i, i + 1, weightMin + rand() % (weightMax - weightMin)));
	}
}

bool GraphGeneratorInexact::insertEdgesUndirected(Graph * graph, int weightMin, int weightMax, int edgeDensity) {
	int V = graph->getSize();
	int possibleEdges = (V)*(V - 1) / 2;
	int generatedEdges = 0;

	for (size_t i = 0; i < V; i++) {
		for (size_t j = i + 2; j < V; j++) {
			if (rand() % 100 < edgeDensity) {
				graph->addEdge(Edge(i, j, weightMin + rand() % (weightMax - weightMin)));
				generatedEdges++;
			}
		}
	}

	if ((double)generatedEdges / (double)possibleEdges < edgeDensity - maxError || (double)generatedEdges / (double)possibleEdges > edgeDensity + maxError)
		return false;

	return true;
}

bool GraphGeneratorInexact::fillGraphUndirected(Graph * graph, int weightRange, int edgeDensity) {

	insertSkeletonUndirected(graph, weightRange*0.80, weightRange);
	return insertEdgesUndirected(graph, 0, weightRange, edgeDensity);
}
