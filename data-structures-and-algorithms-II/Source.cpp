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
#include "Timer.h"
#include <random>

int main() {
	Timer timer = Timer();

	
	int verticles = 1000;
	int edges = 5000;
	int weightRange = 1000;

	MST* kruskals = new MSTKruskal();

	for (int i = 0; i < 10; i++, verticles += 100, edges += 5000) {
		std::cout << "MATRIX: " << std::endl;
		MatrixGraph* graph = new IndirectedMatrixGraph(verticles);

		for (size_t i = 0; i < edges; i++) {
			graph->addEdge(rand() % verticles, rand() % verticles, rand() % weightRange);
		}


		timer.startTimer();

		Graph* result = kruskals->execute(graph);

		timer.endTimer();

		std::cout << "Result: " << timer.timeMiliSeconds() << "ms\n";

		delete graph;
		delete result;
	}

	delete kruskals;

	

	/*
	std::cout << "LIST: " << std::endl;
	ListGraph* listGraph = new IndirectedListGraph(verticles);

	for (size_t i = 0; i < edges; i++) {
		listGraph->addEdge(rand() % verticles, rand() % verticles, rand() % weightRange);
	}

	timer.startTimer();

	kruskals->execute(listGraph);

	timer.endTimer();

	std::cout << "Result: " << timer.timeMiliSeconds() << "ms";
	*/
	
	int x;
	std::cin >> x;

	// CLInterface::enter();
}