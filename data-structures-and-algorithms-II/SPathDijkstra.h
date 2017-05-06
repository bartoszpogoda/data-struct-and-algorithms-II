#pragma once
#include "SPath.h"

class SPathDijkstra : public SPath {
public:
	void execute(Graph* graph, int startVerticle);
};
