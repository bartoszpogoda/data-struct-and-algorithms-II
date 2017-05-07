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

// TODO: Heap must be repaired, cause its time complex. is bad
int main() {
	GraphFileReader* gfr = new GraphFileReader("data.txt");

	{
		MSTPrim prim = MSTPrim();
		Graph* input = gfr->asUndirectedMatrixGraph();
		prim.execute(input);
		Graph* graph = prim.getResult();
		std::cout << "Prim: " << std::endl << graph->toString();

		delete graph;
		delete input;

		MSTKruskal krusk = MSTKruskal();
		input = gfr->asUndirectedListGraph();
		krusk.execute(input);
		graph = krusk.getResult();
		std::cout << "Kruskal: " << std::endl << graph->toString();

		delete input;
		delete graph;
	}

	delete gfr;

	int x;
	std::cin >> x;


	// CLInterface::enter();
}