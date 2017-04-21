#pragma once

class Graph {
	int n;			// number of verticles
	bool directed;
public:
	Graph(int n, bool directed) : n(n), directed(directed) {}

	virtual void addEdge(int, int, int) = 0;	
	virtual int checkEdge(int, int) = 0;		
	virtual void removeEdge(int, int) = 0;
	virtual int degree() = 0;
};