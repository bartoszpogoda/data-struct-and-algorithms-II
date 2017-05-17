#pragma once

#include "Timer.h"
#include "GraphGenerator.h"
#include "MST.h"
#include "SPath.h"

class PerformanceTester {
	// hard coded parameters
	double densities[4] = { 0.25, 0.50, 0.75, 0.99};
	int mstVerticles[5] = { 100, 200, 300, 400, 500 };
	int spathVerticles[5] = { 50, 100, 150, 200, 250 };
	int iterations = 100;
	int weightRange = 5;

	Timer* timer;
	GraphGenerator* graphGenerator;

	MST* mstAlgorithm;
	SPath* spathAlgorithm;

	void runMSTKruskal();
	void runMSTPrim();
	void runSPathDijkstra();
	void runSPathBellmanFord();
public:
	PerformanceTester();
	~PerformanceTester();
	void run();
};
