#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int n) : Graph(n), adjacencyMatrix(new int*[n]) {

	for (size_t i = 0; i < n; i++) {
		adjacencyMatrix[i] = new int[n];

		for (size_t j = 0; j < n; j++) {
			adjacencyMatrix[i][j] = INF;
		}
	}
}

MatrixGraph::~MatrixGraph() {

	for (size_t i = 0; i < n; i++) {
		delete[] adjacencyMatrix[i];
	}

	delete[] adjacencyMatrix;
	adjacencyMatrix = nullptr;
}
