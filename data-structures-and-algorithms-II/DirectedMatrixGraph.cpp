#include "DirectedMatrixGraph.h"
#include "Infinity.h"
#include <iomanip>
#include <string>

DirectedMatrixGraph::DirectedMatrixGraph(int n) : MatrixGraph(n) {

	for (size_t i = 0; i < n; i++) {
		adjacencyMatrix[i] = new int[n];

		for (size_t j = 0; j < n; j++) {
			adjacencyMatrix[i][j] = INF;
		}
	}
}

DirectedMatrixGraph::~DirectedMatrixGraph() {
	for (size_t i = 0; i < n; i++) {
		delete[] adjacencyMatrix[i];
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
	out << "Adjacency Matrix: " << std::endl;

	int argWidth = 4;

	// indexes row
	out << std::setw(argWidth) << std::setfill(' ') << "" << "|";
	for (size_t i = 0; i < n; i++)
		out << std::setw(argWidth) << i << "|";
	out << std::endl;

	// +---+.... row
	for (int i = -1; i < n; i++)
		out << std::setw(argWidth) << std::setfill('-') << "" << "+";
	out << std::endl;

	// main data loop
	for (size_t i = 0; i < n; i++) {
		out << std::setw(argWidth) << std::setfill(' ') << i << "|";

		for (size_t j = 0; j < n; j++)
			out << std::setw(argWidth) << (adjacencyMatrix[i][j] == INF ? INF_STRING : std::to_string(adjacencyMatrix[i][j])) << " ";

		out << std::endl;
	}

	out << std::endl;
}
