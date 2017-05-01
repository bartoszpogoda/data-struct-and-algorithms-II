#include "GraphFileReader.h"

#include "Graph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

GraphFileData * GraphFileReader::read(std::string filename, GraphRepresentation representation, GraphType type)
{
	Graph* graph = nullptr;
	int firstVerticle = -1;

	// read graph size
	// read firstVerticle

	if (representation == MATRIX) {
		if (type = DIRECTED) {
			// obj creation logic
		}
		else {

		}
	}
	else {
		if (type = DIRECTED) {

		}
		else {

		}
	}

	// graph creation logic

	return new GraphFileData(graph, firstVerticle);
}
