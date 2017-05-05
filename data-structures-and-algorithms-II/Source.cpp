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

	Graph* graph = GraphFileReader("data4.txt").asDirectedListGraph();
	SPathDijkstra().execute(graph);

	int x;
	std::cin >> x;

	// CLInterface::enter();
}