#include "GraphFileReader.h"

#include "Graph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "IndirectedMatrixGraph.h"
#include "DirectedListGraph.h"
#include "IndirectedListGraph.h"
#include <fstream>

void GraphFileReader::insertLoadedEdges(Graph * graph) {
	for (size_t i = 0; i < e; i++) {
		graph->addEdge(edges[i]);
	}
}

GraphFileReader::GraphFileReader(std::string filename) : startVerticle(-1), endVerticle(-1),
														errorFlag(false), e(0), n(0), edges(nullptr) {
	read(filename);
}

GraphFileReader::~GraphFileReader() {
	
	delete[] edges;
	edges = nullptr;
}

void GraphFileReader::read(std::string filename) {

	std::ifstream file = std::ifstream(filename);
	errorFlag = false;

	if (edges != nullptr) {
		return;
	}
	
	if (file.is_open()) {

		file >> e;
		if (file.fail()) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : num of edges";
			return;
		}
		
		file >> n;
		if (file.fail() || n <= 0) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : graph size";
			return;
		}

		file >> startVerticle;
		if (file.fail()) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : start verticle";
			return;
		}

		file >> endVerticle;
		if (file.fail()) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : end verticle";
			return;
		}

		edges = new Edge[e];

		int begin, end, weight;
		for (int i = 0; i < e; i++) {
			file >> begin >> end >> weight;
			if (file.fail()) {
				file.close();
				errorFlag = true;
				errorMessage = "File read error : edges data";

				delete[] edges;

				return;
			} else
				edges[i] = Edge(begin, end, weight);
		}

		file.close();
	} else {
		errorFlag = true;
		errorMessage = "File read error : file open";
	}
}

DirectedMatrixGraph * GraphFileReader::asDirectedMatrixGraph() {
	if(errorFlag) return nullptr;

	DirectedMatrixGraph* result = new DirectedMatrixGraph(n);
	insertLoadedEdges(result);
	return result;
}

IndirectedMatrixGraph * GraphFileReader::asIndirectedMatrixGraph() {
	if (errorFlag) return nullptr;

	IndirectedMatrixGraph* result = new IndirectedMatrixGraph(n);
	insertLoadedEdges(result);
	return result;
}

DirectedListGraph * GraphFileReader::asDirectedListGraph() {
	if (errorFlag) return nullptr;

	DirectedListGraph* result = new DirectedListGraph(n);
	insertLoadedEdges(result);
	return result;
}

IndirectedListGraph * GraphFileReader::asIndirectedListGraph() {
	if (errorFlag) return nullptr;

	IndirectedListGraph* result = new IndirectedListGraph(n);
	insertLoadedEdges(result);
	return result;
}
