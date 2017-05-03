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
#include "Timer.h"
#include <random>

int main() {

	GraphFileReader* reader = new GraphFileReader("data.txt");
	
	if (reader->success()) {
		// success

		IndirectedListGraph* graph = reader->asIndirectedListGraph();
		int firstVerticle = reader->getFirstVerticle();

		graph->print(std::cout);
		std::cout << "FV: " << firstVerticle;

		MST* kruskal = new MSTKruskal();
		kruskal->execute(graph);
		Graph* result = kruskal->getResultMST();
		result->print(std::cout);
		std::cout << "Weight sum: " << kruskal->getResultWeight();

		delete result;
		delete kruskal;
		delete graph;

	} else { // failure
		std::cout << "ERROR: " << reader->getErrorMessage();
	}
	
	delete reader;


	int x;
	std::cin >> x;

	// CLInterface::enter();
}