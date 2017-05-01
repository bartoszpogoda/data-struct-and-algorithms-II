#include <iostream>
#include <string>
#include "CLInterface.h"
#include "AdjacencyList.h"
#include "DirectedListGraph.h"
#include "IndirectedListGraph.h"
#include "DirectedMatrixGraph.h"

int main() {

	//AdjacencyList* list = new AdjacencyList();

	//list->addEnd(2, 3);
	//list->addEnd(4, 2);
	//list->addEnd(1, 1);
	
	//std::cout << list->toString();

	Graph* graph = new DirectedListGraph(5);
	graph->addEdge(1, 2, 3);
	graph->addEdge(2, 1, 2);
	graph->print(std::cout);

	int x;
	std::cin >> x;

	// CLInterface::enter();
}