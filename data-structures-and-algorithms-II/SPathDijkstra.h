#pragma once
#include "SPath.h"

class SPathDijkstra : public SPath {
public:
	Path* execute(Graph* graph);
};
