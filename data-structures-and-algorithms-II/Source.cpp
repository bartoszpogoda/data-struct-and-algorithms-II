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
	GraphFileReader* gfr = new GraphFileReader("data6.txt");

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
		std::cout << input->toString() << std::endl;
		krusk.execute(input);
		graph = krusk.getResult();

		delete input;
		delete graph;
	}

	delete gfr;

	int x;
	std::cin >> x;


	// CLInterface::enter();
}