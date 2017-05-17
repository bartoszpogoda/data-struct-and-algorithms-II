#include "MSTKruskal.h"
#include "UndirectedListGraph.h"
#include "Infinity.h"
#include "DisjointSet.h"
#include "MinimumHeap.h"

#include <iostream>

void MSTKruskal::execute(Graph * graph) {
	// clear previous result and create new one (empty)
	delete result;
	result = new MSTGraph(graph->getSize());

	// init helper structures (fill heap with all edges - sorting)
	MinimumHeap<Edge>* edgeHeap = new MinimumHeap<Edge>(graph->getAllEdges(), graph->getEdgeCount());
	DisjointSet* disjointSet = new DisjointSet(graph->getSize());

	// end after n-1 edges are added or when run out of edges
	size_t addedEdges = 0;
	while (addedEdges < graph->getSize() - 1 && !edgeHeap->isEmpty()) {
		// pop lowest-weight unused edge
		Edge edge = edgeHeap->popRoot();

		// check if edge would create cycle
		if (disjointSet->makeUnion(edge.getStartV(), edge.getEndV())) {
			result->addEdge(edge);
			addedEdges++;
		}
	}

	// dealocate helper structures
	delete edgeHeap;
	delete disjointSet;
}
