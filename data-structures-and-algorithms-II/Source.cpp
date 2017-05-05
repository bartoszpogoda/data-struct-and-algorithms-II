#include <iostream>
#include <string>
#include "DirectedListGraph.h"
#include "UndirectedListGraph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "GraphFileReader.h"
#include "MST.h"
#include "MSTKruskal.h"

int main() {

	GraphFileReader* reader = new GraphFileReader("data3.txt");
	
	if (reader->success()) {
		// success

		Graph* graph = reader->asUndirectedMatrixGraph();
		int firstVerticle = reader->getFirstVerticle();

		graph->print(std::cout);

		MST* kruskal = new MSTKruskal();
		kruskal->execute(graph);

		Graph* result = kruskal->getResult();
		result->print(std::cout);

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