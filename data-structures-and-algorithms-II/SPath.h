#pragma once
#include "Graph.h"
#include "DistanceNode.h"

/* NOT YET IMPLEMENTED */
class SPath {
protected:
	DistanceNode* result;
	int resultSize;
	int startVerticle;

public:
	SPath() : result(nullptr) {}
	~SPath() { delete result; }

	DistanceNode* getResult();
	int getResultSize() { return resultSize; }
	int getStartVerticle() { return startVerticle; }

	void printResult(std::ostream& out);
	void printResult(std::ostream& out, DistanceNode* result, int resultSize);

	/* Returns Shortest Path in the graph */
	virtual void execute(Graph* graph, int startVerticle) = 0;
};
