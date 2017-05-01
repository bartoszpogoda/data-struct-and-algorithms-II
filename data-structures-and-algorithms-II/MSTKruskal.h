#pragma once
#include "MST.h"

class MSTKruskal : public MST {
private:
	bool isMST(Graph* graph);	// may be moved to MST depending on Prim's needs
	bool canAdd(Graph* graph, Edge* edge);
public:
	Graph* execute(Graph* graph);
};
