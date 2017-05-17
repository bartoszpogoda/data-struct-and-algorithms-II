#include "PerformanceTester.h"
#include "Timer.h"
#include "MSTKruskal.h"
#include "MSTPrim.h"
#include "SPathBellmanFord.h"
#include "SPathDijkstra.h"
#include "DirectedMatrixGraph.h"
#include "DirectedListGraph.h"

#include <iostream>


void PerformanceTester::runMSTKruskal() {
	mstAlgorithm = new MSTKruskal();

	// ====================================  KRUSKAL MATRIX  ====================================
	std::cout << "MST Kruskal Matrix" << std::endl;
	for each (int vert in mstVerticles) {
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedMatrixGraph(vert);

				graphGenerator->fillGraphUndirected(randomGraph, weightRange, dens);

				timer->startTimer();
				mstAlgorithm->execute(randomGraph);
				timer->endTimer();

				//delete mstAlgorithm->getResult();

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
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedListGraph(vert);

				graphGenerator->fillGraphUndirected(randomGraph, weightRange, dens);

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
}

void PerformanceTester::runMSTPrim() {
	mstAlgorithm = new MSTPrim();
	// ====================================  PRIM MATRIX  ====================================
	std::cout << "MST Prim Matrix" << std::endl;
	for each (int vert in mstVerticles) {
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedMatrixGraph(vert);
				graphGenerator->fillGraphUndirected(randomGraph, weightRange, dens);

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
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new UndirectedListGraph(vert);
				graphGenerator->fillGraphUndirected(randomGraph, weightRange, dens);

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
}

void PerformanceTester::runSPathDijkstra() {
	spathAlgorithm = new SPathDijkstra();

	// ====================================  DIJKSTRA MATRIX  ====================================
	std::cout << "SPath Dijkstra Matrix" << std::endl;
	for each (int vert in spathVerticles) {
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedMatrixGraph(vert);
				graphGenerator->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = graphGenerator->randomFirstVerticle(randomGraph);

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
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedListGraph(vert);
				graphGenerator->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = graphGenerator->randomFirstVerticle(randomGraph);

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
}

void PerformanceTester::runSPathBellmanFord() {
	spathAlgorithm = new SPathBellmanFord();

	// ==================================  BELLMAN FORD MATRIX  ====================================
	std::cout << "SPath Bellman-Ford Matrix" << std::endl;
	for each (int vert in spathVerticles) {
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedMatrixGraph(vert);
				graphGenerator->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = graphGenerator->randomFirstVerticle(randomGraph);

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
		for each (double dens in densities) {
			timer->resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				Graph* randomGraph = new DirectedListGraph(vert);
				graphGenerator->fillGraph(randomGraph, weightRange, dens);
				int randomVerticle = graphGenerator->randomFirstVerticle(randomGraph);

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
}

PerformanceTester::PerformanceTester() {
	timer = new Timer();
	graphGenerator = new GraphGenerator();
}

PerformanceTester::~PerformanceTester() {
	delete timer;
	delete graphGenerator;
}

void PerformanceTester::run() {
	runMSTKruskal();
	runMSTPrim();
	runSPathDijkstra();
	runSPathBellmanFord();
}
