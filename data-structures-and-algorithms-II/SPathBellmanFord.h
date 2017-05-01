#pragma once
#include "SPath.h"

class SPathBellmanFord : public SPath {
public:
	Path* execute(Graph* graph);
};
