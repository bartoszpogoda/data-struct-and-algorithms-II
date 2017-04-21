#pragma once

#include <iostream>
#include "Graph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

class GraphFileReader {

public:
	enum GraphRepresentation {LIST, MATRIX};
	enum GraphType {DIRECTED, UNDIRECTED};

	Graph* read(std::string filename, GraphRepresentation representation, GraphType type);
};