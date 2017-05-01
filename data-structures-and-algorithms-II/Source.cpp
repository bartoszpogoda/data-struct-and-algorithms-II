#include <iostream>
#include <string>
#include "CLInterface.h"
#include "AdjacencyList.h"
#include "DirectedListGraph.h"
#include "IndirectedListGraph.h"
#include "IndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "Edge.h"
#include "MinimumEdgeHeap.h"

int main() {

	Edge** edges = new Edge*[5];
	edges[0] = new Edge(1, 2, 0);
	edges[1] = new Edge(3, 1, 4);
	edges[2] = new Edge(1, 4, 12);
	edges[3] = new Edge(0, 2, 3);
	edges[4] = new Edge(0, 3, 1);

	MinimumEdgeHeap* heap = new MinimumEdgeHeap(edges, 5);
	std::cout << heap->toStringTable();
	delete[] edges;

	for (size_t i = 0; i < 5; i++) {
		Edge* edge = heap->getRoot();
		std::cout << edge->getWeight() << " ";
		delete edge;
	}

	delete heap;

	int x;
	std::cin >> x;

	// CLInterface::enter();
}