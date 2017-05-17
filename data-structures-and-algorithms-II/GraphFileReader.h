#pragma once
#include "Edge.h"
#include "Graph.h"
#include "DirectedMatrixGraph.h"
#include "UndirectedMatrixGraph.h"
#include "DirectedListGraph.h"
#include "UndirectedListGraph.h"


/*
	GraphFileReader reads data from file (filename) given in constructor.
	Graphs are accessible in various representations through
		asDirectedMatrixGraph().. etc functions
	Data is preserved through any as.......Graph() calls
	and is dealocated on object destruction.
*/
class GraphFileReader {
	int startVerticle, endVerticle, n, e;
	Edge* edges;

	bool errorFlag;
	std::string errorMessage;

	void read(std::string filename);
	void insertLoadedEdges(Graph* graph);

public:
	GraphFileReader(std::string filename);
	~GraphFileReader();

	// read status
	bool success() { return !errorFlag; }
	std::string getErrorMessage() { return errorMessage; }

	// data accessors
	DirectedMatrixGraph* asDirectedMatrixGraph();
	UndirectedMatrixGraph* asUndirectedMatrixGraph();
	DirectedListGraph* asDirectedListGraph();
	UndirectedListGraph* asUndirectedListGraph();
	int getFirstVerticle() { return startVerticle; }
	int getEndVerticle() { return endVerticle; }
};