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

int main() {

	DisjointSet* djSet = new DisjointSet(5);
	std::cout << djSet->makeUnion(1, 2);
	std::cout << djSet->makeUnion(2, 1);
	std::cout << djSet->makeUnion(3, 4);
	std::cout << djSet->makeUnion(1, 0);
	std::cout << djSet->makeUnion(3, 0);
	std::cout << djSet->makeUnion(3, 2);

	

	int x;
	std::cin >> x;

	// CLInterface::enter();
}