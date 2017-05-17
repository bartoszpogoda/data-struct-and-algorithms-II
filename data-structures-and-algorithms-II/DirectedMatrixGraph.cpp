#include "DirectedMatrixGraph.h"
#include "Infinity.h"

#include <iomanip>
#include <sstream>

void DirectedMatrixGraph::addEdge(Edge edge) {
	if (adjacencyMatrix[edge.getStartV()][edge.getEndV()] == INF)
		e++;

	adjacencyMatrix[edge.getStartV()][edge.getEndV()] = edge.getWeight();
}

void DirectedMatrixGraph::remEdge(Edge edge) {
	if (adjacencyMatrix[edge.getStartV()][edge.getEndV()] < INF)
		e--;

	adjacencyMatrix[edge.getStartV()][edge.getEndV()] = INF;
}

Edge * DirectedMatrixGraph::getAllEdges() {
	Edge* edges = new Edge[e];

	int foundEdges = 0;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (adjacencyMatrix[i][j] < INF) {
				edges[foundEdges++] = Edge(i, j, adjacencyMatrix[i][j]);
			}
		}
	}

	return edges;
}

std::string DirectedMatrixGraph::toString() {
	std::stringstream out;
	out << "Type: Directed Graph" << std::endl << "Representation: Adjacency Matrix" << std::endl << std::endl;

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
	return out.str();
}
