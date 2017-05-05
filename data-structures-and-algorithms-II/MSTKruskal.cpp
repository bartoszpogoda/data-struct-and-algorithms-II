#include "MSTKruskal.h"
#include "UndirectedListGraph.h"
#include "Infinity.h"
#include "DisjointSet.h"
#include "MinimumEdgeHeap.h"

void MSTKruskal::execute(Graph * graph) {
	result = new MSTGraph(graph->getSize());

	// init helper structures
	MinimumEdgeHeap* edgeHeap = new MinimumEdgeHeap(graph->getAllEdges(), graph->getEdgeCount());
	DisjointSet* disjointSet = new DisjointSet(graph->getSize());

	// end after n-1 edges are added or when run out of edges
	size_t addedEdges = 0;
	while (addedEdges < graph->getSize() - 1 && !edgeHeap->isEmpty()) {
		Edge edge = edgeHeap->getRoot();

		if (disjointSet->makeUnion(edge.getStartV(), edge.getEndV())) {
			result->addEdge(edge);
			addedEdges++;
		}
	}

	// dealocate helper structures
	delete edgeHeap;
	delete disjointSet;
}
