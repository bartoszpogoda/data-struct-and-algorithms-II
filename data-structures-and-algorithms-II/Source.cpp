#include <iostream>
#include <string>
#include "DirectedListGraph.h"
#include "UndirectedListGraph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "GraphFileReader.h"
#include "MSTKruskal.h"
#include "MSTPrim.h"
#include "MinimumHeap.h"
#include "SPathDijkstra.h"
#include "SPathBellmanFord.h"

int main() {
	GraphFileReader* gfr = new GraphFileReader("data7.txt");

	{
		SPathDijkstra dijks = SPathDijkstra();
		Graph* input = gfr->asDirectedMatrixGraph();
		dijks.execute(input, gfr->getFirstVerticle());
		Path* graph = dijks.getResult();
		std::cout << "Dijks: " << std::endl << graph->toString();

		delete graph;
		delete input;

		SPathBellmanFord bford = SPathBellmanFord();
		input = gfr->asDirectedMatrixGraph();
		bford.execute(input, gfr->getFirstVerticle());
		graph = bford.getResult();
		std::cout << "BFord: " << std::endl << graph->toString();

		delete input;
		delete graph;
	}

	delete gfr;

	int x;
	std::cin >> x;


	// CLInterface::enter();
}