#include <iostream>
#include <string>
#include "DirectedListGraph.h"
#include "UndirectedListGraph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "GraphFileReader.h"
#include "MST.h"
#include "MSTKruskal.h"
#include "MinimumHeap.h"
#include "DistanceNode.h"

int main() {

	MinimumHeap<DistanceNode>* heap = new MinimumHeap<DistanceNode>();

	heap->add(DistanceNode(0, 5, 2));
	heap->add(DistanceNode(1, 35, 3));
	heap->add(DistanceNode(2, 66, 2));
	heap->add(DistanceNode(3, 12, 1));
	heap->add(DistanceNode(4, 33, 0));

	heap->update(3, DistanceNode(3,1,2));

	while (!heap->isEmpty()) {
		std::cout << " " << heap->getRoot().getDistance();
	}

	delete heap;

	int x;
	std::cin >> x;

	// CLInterface::enter();
}