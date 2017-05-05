#include <iostream>
#include <string>
#include "DirectedListGraph.h"
#include "UndirectedListGraph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "GraphFileReader.h"
#include "MST.h"
#include "MSTKruskal.h"
#include "MSTPrim.h"

int main() {

	GraphFileReader* reader = new GraphFileReader("data.txt");
	
	if (reader->success()) {
		// success

		Graph* graph = reader->asUndirectedMatrixGraph();
		int firstVerticle = reader->getFirstVerticle();

		graph->print(std::cout);

		MST* prim = new MSTPrim();
		prim->execute(graph);

		Graph* result = prim->getResult();
		result->print(std::cout);

		delete result;
		delete prim;
		delete graph;

	} else { // failure
		std::cout << "ERROR: " << reader->getErrorMessage();
	}

	delete reader;

	int x;
	std::cin >> x;

	// CLInterface::enter();
}