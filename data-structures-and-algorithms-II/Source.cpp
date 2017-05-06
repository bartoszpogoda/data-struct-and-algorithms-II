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
#include "SPathBellmanFord.h"

int main() {
	GraphFileReader* gfr = new GraphFileReader("data5.txt");
	Graph* graph = gfr->asDirectedListGraph();

	SPath* spath = new SPathDijkstra();
	std::cout << graph->toString();
	spath->execute(graph, gfr->getFirstVerticle());
	Path* path = spath->getResult();
	std::cout << "Path toString:" << std::endl << path->toString();
	delete path;
	delete spath;

	SPathBellmanFord* spath2 = new SPathBellmanFord();
	spath2->execute(graph, gfr->getFirstVerticle());
	path = spath2->getResult();

	if (spath2->wasGood()) {
		std::cout << "Path toString:" << std::endl << path->toString();
	} else {
		std::cout << "Found negative cycles";
	}

	delete graph;
	delete gfr;
	delete path;
	delete spath2;


	int x;
	std::cin >> x;


	// CLInterface::enter();
}