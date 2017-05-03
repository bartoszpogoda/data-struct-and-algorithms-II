#pragma once
#include "IndirectedListGraph.h"
#include "IndirectedMatrixGraph.h"
#include "Infinity.h"

class MST {
protected:
	Graph* resultMST;
	int resultWeight;
public:
	MST() : resultMST(nullptr), resultWeight(INF) {}
	virtual ~MST() { delete resultMST; }
	
	Graph* getResultMST();
	int getResultWeight();

	/* Finds Minimum Spanning Tree of the graph */
	virtual void execute(IndirectedMatrixGraph* graph) = 0;
	virtual void execute(IndirectedListGraph* graph) = 0;
};
