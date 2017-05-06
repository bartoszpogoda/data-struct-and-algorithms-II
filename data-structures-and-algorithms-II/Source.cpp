#include <iostream>
#include <string>
#include "DirectedListGraph.h"
#include "UndirectedListGraph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "GraphFileReader.h"
#include "MST.h"
#include "MSTKruskal.h"
#include "MinimumHeap.h"
#include "SPathDijkstra.h"

int main() {
	GraphFileReader* gfr = new GraphFileReader("data.txt");
	Graph* graph = gfr->asDirectedListGraph();

	SPath* spath = new SPathDijkstra();
	std::cout << graph->toString();
	spath->execute(graph, gfr->getFirstVerticle());
	Path* path = spath->getResult();
	std::cout << "Path toString:" << std::endl << path->toString();
	delete path;

	path = spath->getResult();

	if (path == nullptr)
		std::cout << "nptr";

	delete gfr;
	delete graph;
	delete spath;



	int x;
	std::cin >> x;


	// CLInterface::enter();
}