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
#include "DisjointSet.h"
#include "AdjacencyList.h"

int main() {


	AdjacencyList* list = new AdjacencyList();
	
	list->add(2, 3);
	list->add(4, 2);
	list->add(1, 1);
	list->remove(1);
	
	std::cout << list->toString();
	

	

	int x;
	std::cin >> x;

	// CLInterface::enter();
}