#include "MatrixGraph.h"

MatrixGraph::~MatrixGraph() {
	delete[] adjacencyMatrix;
	adjacencyMatrix = nullptr;
}
