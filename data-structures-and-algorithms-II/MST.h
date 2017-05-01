#pragma once
#include "Graph.h"

class MST {
public:
	/* Returns Minimum Spanning Tree of the graph */
	virtual Graph* execute(Graph* graph) = 0;
};
