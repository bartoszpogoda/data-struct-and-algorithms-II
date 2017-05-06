#pragma once
#include "UndirectedMatrixGraph.h"
#include "UndirectedListGraph.h"
#include "MSTGraph.h"

/*
	MST executes an algorithms and keeps the result's reference
	The reference is forgoten on getResult() call so the MSTGraph
	must be dealocated outside

	MST dealocates result (if wasn't accessed) on obj destruction
*/
class MST {
protected:
	MSTGraph* result;
public:
	MST() : result(nullptr) {}
	~MST() { delete result; }
	
	MSTGraph* getResult();

	/* Finds the Minimum Spanning Tree of the graph */
	virtual void execute(Graph* graph) = 0;
};
