#pragma once
#include "Graph.h"
#include "Path.h"

class SPath {
protected:
	Path* result;

public:
	SPath() : result(nullptr) {}
	~SPath() { delete result; }

	Path* getResult();

	/* Finds the Shortest Path in the graph */
	virtual void execute(Graph* graph, int startVerticle) = 0;
};
