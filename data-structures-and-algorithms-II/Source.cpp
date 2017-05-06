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
#include "DistanceNode.h"
#include "SPathDijkstra.h"

int main() {

	GraphFileReader* gfr = new GraphFileReader("data4.txt");
	Graph* graph = gfr->asDirectedListGraph();
	SPath* spath = new SPathDijkstra();
	
	spath->execute(graph, gfr->getFirstVerticle());
	spath->printResult(std::cout);


	delete gfr;
	delete graph;
	delete spath;

	int x;
	std::cin >> x;


	// CLInterface::enter();
}