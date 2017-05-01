#pragma once
#include <ostream>

class Graph {
protected:
	int n;			// number of verticles
public:
	Graph(int n) : n(n) {}

	virtual void addEdge(int beginV, int endV, int weight) = 0;	
	virtual int checkEdge(int beginV, int endV) = 0;
	virtual void removeEdge(int beginV, int endV) = 0;
	virtual int degree() = 0;

	virtual void print(std::ostream &out) = 0;

	// TODO: virtual ~Graph() = 0;
};