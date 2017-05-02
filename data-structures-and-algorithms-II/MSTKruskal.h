#pragma once
#include "MST.h"

class MSTKruskal : public MST {
private:
	//bool isSpanTree(Graph* graph);	// may be moved to MST depending on Prim's needs
public:
	Graph* execute(MatrixGraph* graph);
	Graph* execute(ListGraph* graph);
};
