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

int MatrixGraph::degree(int verticle) {
	int degree = 0;

	for (size_t i = 0; i < n; i++)
		if (adjacencyMatrix[verticle][i] < INF)
			degree++;

	return degree;
}

Edge* MatrixGraph::getAdjacentEdges(int verticle) {
	Edge * adjacentEdges = new Edge[degree(verticle)];

	for (size_t i = 0, j = 0; i < n; i++)
		if (adjacencyMatrix[verticle][i] < INF)
			adjacentEdges[j++] = Edge(verticle, i, adjacencyMatrix[verticle][i]);

	return adjacentEdges;
}

bool MatrixGraph::hasEdge(Edge edge) {
	if (adjacencyMatrix[edge.getStartV()][edge.getEndV()] < INF)
		return true;
	return false;
}

void MatrixGraph::clearEdges() {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			adjacencyMatrix[i][j] = INF;
		}
	}
	e = 0;
}
