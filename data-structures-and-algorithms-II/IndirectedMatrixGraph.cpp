#include "IndirectedMatrixGraph.h"
#include "Infinity.h"

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

void IndirectedMatrixGraph::addEdge(int beginV, int endV, int weight) {

	adjacencyMatrix[std::max(beginV, endV)][std::min(beginV, endV)] = weight;
}

int IndirectedMatrixGraph::checkEdge(int beginV, int endV) {

	return adjacencyMatrix[std::max(beginV, endV)][std::min(beginV, endV)];
}

void IndirectedMatrixGraph::removeEdge(int beginV, int endV) {

	adjacencyMatrix[std::max(beginV, endV)][std::min(beginV, endV)] = INF;
}

int IndirectedMatrixGraph::degree() {
	return 0;
}

void IndirectedMatrixGraph::print(std::ostream &out) {
	for (size_t i = 0; i < n; i++) {
		
		for (size_t j = 0; j < n - i; j++)
			out << (adjacencyMatrix[i][j] == INF ? INF_STRING : std::to_string(adjacencyMatrix[i][j])) << " ";

		out << std::endl;
	}
}
