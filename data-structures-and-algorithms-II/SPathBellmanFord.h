#pragma once
#include "SPath.h"

class SPathBellmanFord : public SPath {
	bool negativeCycleFlag;
public:
	SPathBellmanFord() : negativeCycleFlag(false), SPath() {}
	bool wasGood() { return !negativeCycleFlag; }

	void execute(Graph* graph, int startVerticle);
};
