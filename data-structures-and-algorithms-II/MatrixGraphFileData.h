#pragma once

#include "MatrixGraph.h"
#include "GraphFileData.h"

class MatrixGraphFileData : public GraphFileData {
	MatrixGraph* graph;
public:
	MatrixGraphFileData(MatrixGraph* graph, int firstVerticle) : graph(graph), GraphFileData(firstVerticle) {}
	MatrixGraphFileData(std::string errorMessage) : GraphFileData(errorMessage) {}

	MatrixGraph* getGraph() { return graph; }
};