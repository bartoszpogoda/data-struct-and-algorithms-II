#pragma once

class Graph {
	int n;			// number of verticles
	bool directed;
public:
	Graph(int n, bool directed) : n(n), directed(directed) {}

	virtual void addEdge(int beginV, int endV, int weight) = 0;	
	virtual int checkEdge(int beginV, int endV) = 0;
	virtual void removeEdge(int beginV, int endV) = 0;
	virtual int degree() = 0;
};