#pragma once
#include "Graph.h"

class MatrixGraph : public Graph {
protected:
	int** adjacencyMatrix;
public:
	MatrixGraph(int n);
	virtual ~MatrixGraph();

	int degree(int verticle);
	Edge* getAdjacentEdges(int verticle);
	bool hasEdge(Edge edge);
	void clearEdges();
};