#pragma once
#include "SPath.h"

class SPathDjikstra : public SPath {
public:
	Path* execute(Graph* graph);
};
