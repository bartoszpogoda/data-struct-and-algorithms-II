#pragma once
#include "Edge.h"

#include <string>

class Graph {
protected:
	int n;			// number of verticles
	int e;			// number of edges
public:
	Graph(int n) : n(n), e(0) {}
	virtual ~Graph() {};

	int getSize() { return n; }
	int getEdgeCount() { return e; }
	virtual int degree(int verticle) = 0;

	virtual void addEdge(Edge edge) = 0;
	virtual bool hasEdge(Edge edge) = 0;
	virtual void remEdge(Edge edge) = 0;
	virtual void clearEdges() = 0;
	virtual Edge* getAdjacentEdges(int verticle) = 0;	// degree is number of adjacent edges
	virtual Edge* getAllEdges() = 0;

	virtual std::string toString() = 0;

};