#pragma once
#include "Graph.h"
#include "Path.h"

/* NOT YET IMPLEMENTED */
class SPath {
public:
	/* Returns Shortest Path in the graph */
	virtual Path* execute(Graph* graph) = 0;
};
