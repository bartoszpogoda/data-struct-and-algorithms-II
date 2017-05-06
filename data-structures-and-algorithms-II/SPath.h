#pragma once
#include "Graph.h"
#include "Path.h"

/*
	SPath executes an algorithms and keeps the result's reference
	The reference is forgoten on getResult() call so the Path
	must be dealocated outside

	SPath dealocates result (if wasn't accessed) on obj destruction
*/
class SPath {
protected:
	Path* result;

public:
	SPath() : result(nullptr) {}
	~SPath() { delete result; result = nullptr; }

	Path* getResult();

	/* Finds the Shortest Path in the graph */
	virtual void execute(Graph* graph, int startVerticle) = 0;
};
