#include "MSTPrim.h"
#include "UndirectedListGraph.h"
#include "Infinity.h"
#include "DisjointSet.h"
#include "MinimumHeap.h"

void MSTPrim::execute(Graph * graph) {
	// clear previous result and create new one (empty)
	delete result;
	result = new MSTGraph(graph->getSize());

	// init helper structures
	bool* unvisited = new bool[graph->getSize()];
	MinimumHeap<Edge>* edgeHeap = new MinimumHeap<Edge>(graph->getEdgeCount());

	// starting from 0 verticle
	unvisited[0] = false;
	for (size_t i = 1; i < graph->getSize(); i++)												
		unvisited[i] = true;			

	// insert 0's adjacents onto heap
	Edge* edges = graph->getAdjacentEdges(0);
	for (size_t i = 0; i < graph->degree(0); i++) {
		if (unvisited[edges[i].getEndV()])
			edgeHeap->add(edges[i]);
	}	
	delete[] edges;

	// end after n-1 edges are added or when run out of edges
	size_t addedEdges = 0;
	while (addedEdges < graph->getSize() - 1 && !edgeHeap->isEmpty()) {
		// pop lowest-weight edge
		Edge edge = edgeHeap->popRoot();

		// check if edge connects to unvisited verticle
		if (unvisited[edge.getEndV()]) {

			result->addEdge(edge);
			// mark destination verticle as visited
			unvisited[edge.getEndV()] = false;

			// add new adjacent edges that do not connect with visited verticles to the heap
			Edge* edges = graph->getAdjacentEdges(edge.getEndV());
			for (size_t i = 0; i < graph->degree(edge.getEndV()); i++) {
				if (unvisited[edges[i].getEndV()])
					edgeHeap->add(edges[i]);
			}
			delete[] edges;
		}
	}

	// dealocate helper structures
	delete[] unvisited;
	delete edgeHeap;
}
