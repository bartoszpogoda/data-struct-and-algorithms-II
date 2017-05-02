#pragma once
#include "MST.h"

class MSTPrim : public MST{
public:
	Graph* execute(MatrixGraph* graph);
	Graph* execute(ListGraph* graph);
};
