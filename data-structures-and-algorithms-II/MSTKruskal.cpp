#include "MSTKruskal.h"
#include "IndirectedListGraph.h"
#include "Infinity.h"
#include "DisjointSet.h"
#include "MinimumEdgeHeap.h"

Graph * MSTKruskal::execute(MatrixGraph * graph) {
	// empty forest
	Graph * forest = new IndirectedListGraph(graph->getSize());

	// create edge heap
	Edge** edges = new Edge*[graph->getSize() * graph->getSize()]; // mb track number of edges in Graph?
	int e = 0;

	for (size_t i = 0; i < graph->getSize(); i++) {
		for (size_t j = 0; j < graph->getSize(); j++) {
			int weight = graph->checkEdge(i, j);

			if (weight != INF) {
				edges[e] = new Edge(i, j, weight);
				e++;
			}
		}
	}

	MinimumEdgeHeap* edgeHeap = new MinimumEdgeHeap(edges, e);
	delete[] edges;

	DisjointSet* dsSet = new DisjointSet(graph->getSize());

	Edge* edge = nullptr;
	// run loop n-1 times or when we run out of edges
	size_t addedEdges = 0;
	while(addedEdges < graph->getSize() - 1 && (edge = edgeHeap->getRoot()) != nullptr) {
		if (dsSet->makeUnion(edge->getStartV(), edge->getEndV())) {
			forest->addEdge(edge->getStartV(), edge->getEndV(), edge->getWeight());
			addedEdges++;
		}

		delete edge;
	}
	
	delete dsSet;
	return forest;
}

Graph * MSTKruskal::execute(ListGraph * graph) {
	// empty forest
	Graph * forest = new IndirectedListGraph(graph->getSize());

	// create edge heap
	Edge** edges = new Edge*[graph->getSize() * graph->getSize()]; // mb track number of edges in Graph?
	int e = 0;

	AdjacencyList** adjacencyLists = graph->getAdjacencyLists();

	for (size_t i = 0; i < graph->getSize(); i++) {
		if (adjacencyLists[i]->iterReset()) {
			edges[e] = new Edge(i, adjacencyLists[i]->iterGetAdjacent(), adjacencyLists[i]->iterGetWeight());
			e++;
		}

		while (adjacencyLists[i]->iterHasNext()) {
			adjacencyLists[i]->iterNext();

			edges[e] = new Edge(i, adjacencyLists[i]->iterGetAdjacent(), adjacencyLists[i]->iterGetWeight());
			e++;
		}


		for (size_t j = 0; j < graph->getSize(); j++) {
			int weight = graph->checkEdge(i, j);

			if (weight != INF) {
				edges[e] = new Edge(i, j, weight);
				e++;
			}
		}
	}

	MinimumEdgeHeap* edgeHeap = new MinimumEdgeHeap(edges, e);
	delete[] edges;

	DisjointSet* dsSet = new DisjointSet(graph->getSize());

	Edge* edge = nullptr;
	// run loop n-1 times or when we run out of edges
	size_t addedEdges = 0;
	while (addedEdges < graph->getSize() - 1 && (edge = edgeHeap->getRoot()) != nullptr) {
		if (dsSet->makeUnion(edge->getStartV(), edge->getEndV())) {
			forest->addEdge(edge->getStartV(), edge->getEndV(), edge->getWeight());
			addedEdges++;
		}

		delete edge;
	}

	delete dsSet;
	return forest;
}

/*Graph * MSTKruskal::execute(Graph * graph) {

	// trees 0,1, ..., n-1 in forest
	Graph * forest = new IndirectedMatrixGraph(graph->getSize());

	// create edge heap
	Edge** edges = new Edge*[graph->getSize() * graph->getSize()]; // mb track number of edges in Graph?
	int e = 0;

	for (size_t i = 0; i < graph->getSize(); i++) {
		for (size_t j = 0; j < graph->getSize(); j++) {
			int weight = graph->checkEdge(i, j);

			if (weight != INF) {
				edges[e] = new Edge(i, j, weight);
				e++;
			}
		}
	}

	MinimumEdgeHeap* edgeHeap = new MinimumEdgeHeap(edges, e);
	delete[] edges;

	// ...
	Edge* edge = nullptr;
	while ((edge = edgeHeap->getRoot()) != nullptr && isMST(forest)) {
		if (canAdd(forest, edge))
			;// ...
		else
			delete edge;
	}
	
	return forest;
}*/
