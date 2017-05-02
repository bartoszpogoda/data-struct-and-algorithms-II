#pragma once
#include "MST.h"

class MSTKruskal : public MST {
public:
	Graph* execute(MatrixGraph* graph);
	Graph* execute(ListGraph* graph);
};
