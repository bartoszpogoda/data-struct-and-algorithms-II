#pragma once

#include <iostream>
#include "Edge.h"
#include "Graph.h"
#include "DirectedMatrixGraph.h"
#include "IndirectedMatrixGraph.h"
#include "DirectedListGraph.h"
#include "IndirectedListGraph.h"

// reads data from a file given in constructor, allocates memory
class GraphFileReader {
	int startVerticle, endVerticle, n, e;
	Edge** edges;

	bool errorFlag;
	std::string errorMessage;

	void read(std::string filename);
	void insertLoadedEdges(Graph* graph);

public:
	GraphFileReader(std::string filename);
	~GraphFileReader();

	// assert success
	bool success() { return !errorFlag; }

	// get data
	DirectedMatrixGraph* asDirectedMatrixGraph();
	IndirectedMatrixGraph* asIndirectedMatrixGraph();
	DirectedListGraph* asDirectedListGraph();
	IndirectedListGraph* asIndirectedListGraph();
	int getFirstVerticle() { return startVerticle; }
	int getEndVerticle() { return endVerticle; }
	std::string getErrorMessage() { return errorMessage; }
};