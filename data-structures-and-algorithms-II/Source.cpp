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
	GraphFileReader* gfr = new GraphFileReader();
	MatrixGraphFileData* mgfd = gfr->readMatrixGraph("data.txt", GraphFileReader::INDIRECTED);

	std::cout << mgfd->getErrorMessage();

	
	std::cout << "Before Kruskal's MST: " << std::endl;
	MatrixGraph* graph = mgfd->getGraph();


	graph->print(std::cout);

	MST* kruskals = new MSTKruskal();
	Graph* result = kruskals->execute(graph);

	std::cout << "Result: " << std::endl;
	result->print(std::cout);
	
	
	int x;
	std::cin >> x;

	// CLInterface::enter();
}