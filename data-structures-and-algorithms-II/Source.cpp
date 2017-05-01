#include <iostream>
#include <string>
#include "CLInterface.h"
#include "AdjacencyList.h"
#include "DirectedListGraph.h"
#include "IndirectedListGraph.h"
#include "IndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"

int main() {

	//AdjacencyList* list = new AdjacencyList();

	//list->addEnd(2, 3);
	//list->addEnd(4, 2);
	//list->addEnd(1, 1);
	
	//std::cout << list->toString();

	Graph* graph = new DirectedListGraph(5);
	Graph* graph1 = new DirectedMatrixGraph(5);
	Graph* graph2 = new IndirectedListGraph(5);
	Graph* graph3 = new IndirectedMatrixGraph(5);

	graph->addEdge(1, 2, 3);
	graph->addEdge(2, 1, 2);
	graph1->addEdge(2, 1, 2);
	graph2->addEdge(2, 1, 2);
	graph3->addEdge(2, 1, 2);
	graph->print(std::cout);

	delete graph;
	delete graph1;
	delete graph2;
	delete graph3;

	int x;
	std::cin >> x;

	// CLInterface::enter();
}