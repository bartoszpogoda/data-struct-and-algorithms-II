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
#include "MSTKruskal.h"
#include "IndirectedMatrixGraph.h"

int main() {
	// IndirectedMatrixGraph is bugged! TODO:
	/* should be like that rather
	oo oo oo 1 2
	   oo 3 oo oo
	      oo 7 5
	         oo 2
	            oo

	*/
	std::cout << "Graf dla kruskala: " << std::endl;
	MatrixGraph* graph = new DirectedMatrixGraph(5);
	graph->addEdge(1, 2, 3);
	graph->addEdge(0, 2, 1);
	graph->addEdge(2, 4, 5);
	graph->addEdge(0, 3, 1);
	graph->addEdge(3, 4, 2);
	graph->addEdge(2, 3, 7);
	graph->addEdge(0, 4, 2);

	graph->print(std::cout);

	MST* kruskals = new MSTKruskal();
	Graph* result = kruskals->execute(graph);

	std::cout << "MST: " << std::endl;
	result->print(std::cout);
	
	

	

	int x;
	std::cin >> x;

	// CLInterface::enter();
}