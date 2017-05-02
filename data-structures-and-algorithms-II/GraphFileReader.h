#pragma once

#include <iostream>
#include "MatrixGraphFileData.h"
#include "ListGraphFileData.h"

class GraphFileReader {
public:
	enum GraphType {DIRECTED, INDIRECTED};

	MatrixGraphFileData* readMatrixGraph(std::string filename, GraphType type);
	ListGraphFileData* readListGraph(std::string filename, GraphType type);
};