#include "GraphGenerator.h"
#include "DisjointSet.h"

//dbg
#include <iostream>

Edge GraphGenerator::randomEdge(int verticleRange, int weightRange) {
	int start = rand() % verticleRange, end;
	while ((end = rand() % verticleRange) == start);

	return Edge(start, end, rand() % weightRange);
}

/*void GraphGenerator::fillGraphWithRandomData(Graph * graph, double edgeDensity, int weightRange) {
	int V = graph->getSize();
	int edgesToGenerate = (V / 2)*(V - 1);

	// Generate spanning tree first
	DisjointSet* dsSet = new DisjointSet(V);

	// end after n-1 edges are added 
	size_t addedEdges = 0;
	while (addedEdges < V - 1) {
		Edge edge = generateRandomEdge(V, weightRange);

		if (dsSet->makeUnion(edge.getStartV(), edge.getEndV())) {
			graph->addEdge(edge);
			addedEdges++;
		}
	}

	delete dsSet;
}*/

/*void GraphGenerator::insertSkeleton(Graph * graph, int weightMin, int weightMax) {
	int V = graph->getSize();

	for (size_t i = 0; i < V; i++) {
		graph->addEdge(Edge(i, (i + 1) % V, weightMin + rand() % (weightMax - weightMin)));
	}
}

void GraphGenerator::insertEdges(Graph * graph, int weightMin, int weightMax, int edgeDensity) {
	int V = graph->getSize();
	int possibleEdges = (V)*(V - 1);	
	//int generatedEdges = 0; // V;		// V edges were  added as a skeleton

	for (size_t i = 0; i < V; i++) {
		for (size_t j = 0; j < V; j++) {
			if (i + 1 != j && i != j && rand() % 100 < edgeDensity) {
				graph->addEdge(Edge(i, j, weightMin + rand() % (weightMax - weightMin)));
				//generatedEdges++;
			}
		}
	}

}
*/
void GraphGenerator::fillGraph(Graph * graph, int weightRange, double edgeDensity) {

	int V = graph->getSize();
	int edgesToGenerate = V*V*edgeDensity;

	// cycle of weights in top 20% range
	for (size_t i = 0; i < V; i++) {
		graph->addEdge(Edge(i, (i + 1) % V, weightRange*0.8 + rand() % (int)(0.2*weightRange)));
		edgesToGenerate--;
	}

	while (edgesToGenerate > 0) {
		Edge edge;
		do {
			edge = randomEdge(V, weightRange);
		} while (graph->hasEdge(edge));

		graph->addEdge(edge);
		edgesToGenerate--;
	}
}
/*
void GraphGenerator::insertSkeletonUndirected(Graph * graph, int weightMin, int weightMax) {
	int V = graph->getSize();

	for (size_t i = 0; i < V-1; i++) {
		graph->addEdge(Edge(i, i + 1, weightMin + rand() % (weightMax - weightMin)));
	}
}

void GraphGenerator::insertEdgesUndirected(Graph * graph, int weightMin, int weightMax, int edgeDensity) {
	int V = graph->getSize();
	int possibleEdges = (V)*(V - 1)/2;
	//int generatedEdges = 0; // V;		// V edges were  added as a skeleton

	for (size_t i = 0; i < V; i++) {
		for (size_t j = i+2; j < V; j++) {
			if (rand() % 100 < edgeDensity) {
				graph->addEdge(Edge(i, j, weightMin + rand() % (weightMax - weightMin)));
				//generatedEdges++;
			}
		}
	}

	//std::cout << "Generated: " << (double)generatedEdges / (double)possibleEdges << std::endl;
}

void GraphGenerator::fillGraphUndirected(Graph * graph, int weightRange, int edgeDensity) {

	insertSkeletonUndirected(graph, weightRange*0.80, weightRange);
	insertEdgesUndirected(graph, 0, weightRange, edgeDensity);
}
*/