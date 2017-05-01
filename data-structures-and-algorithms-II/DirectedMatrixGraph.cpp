#include "DirectedMatrixGraph.h"
#include "Infinity.h"

#include <string>

DirectedMatrixGraph::DirectedMatrixGraph(int n) : MatrixGraph(n) {

	for (size_t i = 0; i < n; i++) {
		adjacencyMatrix[i] = new int[n];

		for (size_t j = 0; j < n; j++) {
			adjacencyMatrix[i][j] = INF;
		}
	}
}

void DirectedMatrixGraph::addEdge(int beginV, int endV, int weight) {

	adjacencyMatrix[beginV][endV] = weight;
}

int DirectedMatrixGraph::checkEdge(int beginV, int endV) {

	return adjacencyMatrix[beginV][endV];
}

void DirectedMatrixGraph::removeEdge(int beginV, int endV) {

	adjacencyMatrix[beginV][endV] = INF;
}

int DirectedMatrixGraph::degree() {
	return 0;
}

void DirectedMatrixGraph::print(std::ostream &out) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++)
			out << (adjacencyMatrix[i][j] == INF ? INF_STRING : std::to_string(adjacencyMatrix[i][j])) << " ";
		
		out << std::endl;
	}
}
