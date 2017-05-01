#pragma once

#include <iostream>
#include "GraphFileData.h"

class GraphFileReader {

public:
	enum GraphRepresentation {LIST, MATRIX};
	enum GraphType {DIRECTED, UNDIRECTED};

	GraphFileData* read(std::string filename, GraphRepresentation representation, GraphType type);
};