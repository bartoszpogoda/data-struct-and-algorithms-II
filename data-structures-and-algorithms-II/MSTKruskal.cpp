#include "MSTKruskal.h"
#include "IndirectedMatrixGraph.h"
#include "Infinity.h"
#include "MinimumEdgeHeap.h"

Graph * MSTKruskal::execute(MatrixGraph * graph) {
	return nullptr;
}

Graph * MSTKruskal::execute(ListGraph * graph) {
	return nullptr;
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
