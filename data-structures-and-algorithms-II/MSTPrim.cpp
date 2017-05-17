#include "MSTPrim.h"
#include "UndirectedListGraph.h"
#include "Infinity.h"
#include "DisjointSet.h"
#include "MinimumHeap.h"

void MSTPrim::execute(Graph * graph) {
	delete result;
	result = new MSTGraph(graph->getSize());

	// init helper structures
	bool* unvisited = new bool[graph->getSize()];
	unvisited[0] = false;
	for (size_t i = 1; i < graph->getSize(); i++)													// O(V)
		unvisited[i] = true;															

	MinimumHeap<Edge>* edgeHeap = new MinimumHeap<Edge>(graph->getEdgeCount());						
	Edge* edges = graph->getAdjacentEdges(0);

	for (size_t i = 0; i < graph->degree(0); i++) {
		if (unvisited[edges[i].getEndV()])	// to avoid loops in graph
			edgeHeap->add(edges[i]);
	}
																									// adding edge E times - E * logV
	
	delete[] edges;


	// end after n-1 edges are added or when run out of edges
	size_t addedEdges = 0;
	while (addedEdges < graph->getSize() - 1 && !edgeHeap->isEmpty()) {

		Edge edge = edgeHeap->popRoot();

		if (unvisited[edge.getEndV()]) {
			// unvisited case - add edge to the tree 
			result->addEdge(edge);
			// mark as visited
			unvisited[edge.getEndV()] = false;

			// add new adjacent edges that do not connect with visited nodes to the heap
			Edge* edges = graph->getAdjacentEdges(edge.getEndV());

			for (size_t i = 0; i < graph->degree(edge.getEndV()); i++) {
				if (unvisited[edges[i].getEndV()])
					edgeHeap->add(edges[i]);
			}

			delete[] edges;
		}
	}

	delete[] unvisited;
	delete edgeHeap;
}
