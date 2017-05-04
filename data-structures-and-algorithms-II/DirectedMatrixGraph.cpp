#include "DirectedMatrixGraph.h"
#include "Infinity.h"
#include <iomanip>
#include <string>


int DirectedMatrixGraph::degree(int verticle) {
	int degree = 0;

	for (size_t i = 0; i < n; i++) 
		if (adjacencyMatrix[verticle][i] < INF)
			degree++;

	return degree;
}

void DirectedMatrixGraph::addEdge(Edge edge) {
	adjacencyMatrix[edge.getStartV()][edge.getEndV()] = edge.getWeight();
}

Edge * DirectedMatrixGraph::getAdjacentEdges(int verticle) {
	Edge * adjacentEdges = new Edge[degree(verticle)];

	for (size_t i = 0, j = 0; i < n; i++)
		if (adjacencyMatrix[verticle][i] < INF)
			adjacentEdges[j++] = Edge(verticle, j, adjacencyMatrix[verticle][i]);

	return adjacentEdges;
}

Edge * DirectedMatrixGraph::getAllEdges() {
	return nullptr;
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
