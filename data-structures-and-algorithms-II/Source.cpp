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
	std::cout << "Before Kruskal's MST: " << std::endl;
	MatrixGraph* graph = new IndirectedMatrixGraph(5);
	graph->addEdge(1, 2, 33);
	graph->addEdge(0, 2, 112);
	graph->addEdge(2, 4, 57);
	graph->addEdge(0, 3, 12);
	graph->addEdge(3, 4, 48);
	graph->addEdge(2, 3, 7);
	graph->addEdge(0, 4, 2);

	graph->print(std::cout);

	MST* kruskals = new MSTKruskal();
	Graph* result = kruskals->execute(graph);

	std::cout << "Result: " << std::endl;
	result->print(std::cout);
	
	

	

	int x;
	std::cin >> x;

	// CLInterface::enter();
}