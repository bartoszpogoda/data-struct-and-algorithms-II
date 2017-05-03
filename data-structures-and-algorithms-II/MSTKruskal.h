#pragma once
#include "MST.h"

class MSTKruskal : public MST {
public:
	void execute(IndirectedMatrixGraph* graph);
	void execute(IndirectedListGraph* graph);
};
