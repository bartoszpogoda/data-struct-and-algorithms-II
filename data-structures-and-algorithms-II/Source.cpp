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
	// new class Path containg results of SPath algorithm along with print methods? would be better!

	GraphFileReader* gfr = new GraphFileReader("data4.txt");
	Graph* graph = gfr->asUndirectedListGraph();
	/*SPath* spath = new SPathDijkstra();
	std::cout << graph->toString();
	spath->execute(graph, gfr->getFirstVerticle());
	std::cout << spath->resultToString();
	delete gfr;
	delete graph;
	delete spath;*/

	MST* mst = new MSTKruskal();
	mst->execute(graph);
	std::cout << mst->getResult()->toString();


	int x;
	std::cin >> x;


	// CLInterface::enter();
}