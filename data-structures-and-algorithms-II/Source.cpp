#include <iostream>
#include <string>
#include "CLInterface.h"
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
#include "GraphGenerator.h"
#include "Timer.h"

int main() {
	

	GraphGenerator* ptu = new GraphGenerator(5);

	Graph* graph = new DirectedListGraph(50);
	ptu->fillGraph(graph, 1000, 0.75);
	int counter = 0;
	int all = 0;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			if (graph->hasEdge(Edge(i,j,0)))
				counter++;
			all++;
		}

	std::cout << "Edges dens: " << (double)counter / (double)all;


	int c;
	std::cin >> c;

	/*CLInterface::enter();
	
	int densities[] = { 25, 50, 75, 99 };
	int iterations = 100;
	int weightRange = 1000;

	Timer* timer = new Timer();
	GraphGenerator* ptu = new GraphGenerator(5);
	
	// ========================================== MST ===========================================
	int mstVerticles[] = { 100, 200, 300, 400, 500 };

	// ====================================      KRUSKAL  ====================================
	MST* mstAlgorithm = new MSTKruskal();

	// ====================================  KRUSKAL MATRIX  ====================================
	std::cout << "MST Kruskal Matrix" << std::endl;
	for each (int vert in mstVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedMatrixGraph(vert);
				ptu->fillGraphUndirected(randomGraph, weightRange, dens);

				timer->startTimer();
				mstAlgorithm->execute(randomGraph);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	// ====================================  KRUSKAL LISTS   ====================================
	std::cout << "MST Kruskal Lists" << std::endl;
	for each (int vert in mstVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedListGraph(vert);
				ptu->fillGraphUndirected(randomGraph, weightRange, dens);

				timer->startTimer();
				mstAlgorithm->execute(randomGraph);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	// ====================================      PRIM     ====================================
	delete mstAlgorithm;
	mstAlgorithm = new MSTPrim();
	// ====================================  PRIM MATRIX  ====================================
	std::cout << "MST Prim Matrix" << std::endl;
	for each (int vert in mstVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedMatrixGraph(vert);
				ptu->fillGraphUndirected(randomGraph, weightRange, dens);

				timer->startTimer();
				mstAlgorithm->execute(randomGraph);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	// ====================================  PRIM LISTS   ====================================
	std::cout << "MST Prim Lists" << std::endl;
	for each (int vert in mstVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedListGraph(vert);
				ptu->fillGraphUndirected(randomGraph, weightRange, dens);

				timer->startTimer();
				mstAlgorithm->execute(randomGraph);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	} 

	delete mstAlgorithm;
	// ========================================== SPATH =========================================
	int spathVerticles[] = { 100 };//150, 200, 250, 300};
	// ====================================      DIJKSTRA    ====================================
	SPath* spathAlgorithm = new SPathDijkstra();

	// ====================================  DIJKSTRA MATRIX  ====================================
	std::cout << "SPath Dijkstra Matrix" << std::endl;
	for each (int vert in spathVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedMatrixGraph(vert);
				ptu->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = ptu->randomFirstVerticle(randomGraph);

				timer->startTimer();
				spathAlgorithm->execute(randomGraph, randomVerticle);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	// ====================================  DIJKSTRA LISTS  ====================================
	std::cout << "SPath Dijkstra Lists" << std::endl;
	for each (int vert in spathVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedListGraph(vert);
				ptu->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = ptu->randomFirstVerticle(randomGraph);

				timer->startTimer();
				spathAlgorithm->execute(randomGraph, randomVerticle);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	// ====================================   BELLMAN FORD    ====================================
	delete spathAlgorithm;
	spathAlgorithm = new SPathBellmanFord();

	// ==================================  BELLMAN FORD MATRIX  ====================================
	std::cout << "SPath Bellman-Ford Matrix" << std::endl;
	for each (int vert in spathVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedMatrixGraph(vert);
				ptu->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = ptu->randomFirstVerticle(randomGraph);

				timer->startTimer();
				spathAlgorithm->execute(randomGraph, randomVerticle);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	// ==================================  BELLMAN FORD LISTS  ====================================
	std::cout << "SPath Bellman-Ford Lists" << std::endl;
	for each (int vert in spathVerticles) {
		for each (int dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedListGraph(vert);
				ptu->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = ptu->randomFirstVerticle(randomGraph);

				timer->startTimer();
				spathAlgorithm->execute(randomGraph, randomVerticle);
				timer->endTimer();

				delete randomGraph;
			}
			timer->divideMemory(iterations);

			std::cout << timer->timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}


	delete spathAlgorithm;
	delete timer;
	delete ptu;

	int x;
	std::cin >> x; 
	*/
}