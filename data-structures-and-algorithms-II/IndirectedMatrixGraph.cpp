#include "IndirectedMatrixGraph.h"
#include "Infinity.h"

#include <iomanip>
#include <string>
#include <algorithm>

IndirectedMatrixGraph::IndirectedMatrixGraph(int n) : MatrixGraph(n) {

	for (size_t i = 0; i < n; i++) {
		adjacencyMatrix[i] = new int[n - i];

		for (size_t j = 0; j < n - i; j++) {
			adjacencyMatrix[i][j] = INF;
		}
	}
}

IndirectedMatrixGraph::~IndirectedMatrixGraph() {
	for (size_t i = 0; i < n; i++) {
		delete[] adjacencyMatrix[i];
	}
}

void IndirectedMatrixGraph::addEdge(int beginV, int endV, int weight) {

	adjacencyMatrix[std::min(beginV, endV)][std::max(beginV, endV) - std::min(beginV, endV)] = weight;
}

int IndirectedMatrixGraph::checkEdge(int beginV, int endV) {

	return adjacencyMatrix[std::min(beginV, endV)][std::max(beginV, endV) - std::min(beginV, endV)];
}

void IndirectedMatrixGraph::removeEdge(int beginV, int endV) {

	adjacencyMatrix[std::min(beginV, endV)][std::max(beginV, endV) - std::min(beginV, endV)] = INF;
}

int IndirectedMatrixGraph::degree() {
	return 0;
}
/*
   |  0|  1|  2|  3|  4|  5|
---+---+---+---+---+---+---|
  0|   |   |   |   |   |   |
  1|   |   |   |   |   |   |
  2|   |   |   |   |   |   |
  3|   |   |   |   |   |   |
  4|   |   |   |   |   |   |
  5|   |   |   |   |   |   |
*/
void IndirectedMatrixGraph::print(std::ostream &out) {
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

		for (size_t j = 0; j < i; j++)
			out << std::setw(argWidth) << " " << " ";

		for (size_t j = 0; j < n - i; j++)
			out << std::setw(argWidth) << (adjacencyMatrix[i][j] == INF ? INF_STRING : std::to_string(adjacencyMatrix[i][j])) << " ";

		out << std::endl;
	}

	out << std::endl;
}
