#pragma once
#include "ListGraph.h"
#include "MatrixGraph.h"

class MST {
public:
	/* Returns Minimum Spanning Tree of the graph */
	virtual Graph* execute(MatrixGraph* graph) = 0;
	virtual Graph* execute(ListGraph* graph) = 0;
};
