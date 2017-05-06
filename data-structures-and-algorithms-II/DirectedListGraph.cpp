#include "DirectedListGraph.h"

#include <iomanip>
#include <sstream>

void DirectedListGraph::addEdge(Edge edge) {
	if(adjacencyLists[edge.getStartV()]->add(edge.getEndV(), edge.getWeight()))
		e++;
}

Edge * DirectedListGraph::getAllEdges() {
	Edge* edges = new Edge[e];

	int foundEdges = 0;

	for (size_t i = 0; i < n; i++) {
		Edge* adjacentEdges = adjacencyLists[i]->getEdges();
		int verticleDegree = adjacencyLists[i]->getSize();

		for (size_t j = 0; j < verticleDegree; j++) {
			edges[foundEdges++] = adjacentEdges[j];
		}
	}

	return edges;
}

std::string DirectedListGraph::toString() {
	std::stringstream out;
	out << "Type: Directed Graph" << std::endl << "Representation: Adjacency Lists" << std::endl << std::endl;

	int argWidth = 3;

	// main data loop
	for (size_t i = 0; i < n; i++) {
		out << std::setw(argWidth + 3) << std::setfill(' ') << i << " | ";

		// adjacents data loop
		Edge* adjacentEdges = adjacencyLists[i]->getEdges();
		for (size_t j = 0; j < adjacencyLists[i]->getSize(); j++) {
			out << "(" << std::setw(argWidth) << std::setfill(' ') << adjacentEdges[j].getEndV() << "v;"
				<< std::setw(argWidth) << std::setfill(' ') << adjacentEdges[j].getWeight() << "w) ";
		}

		delete[] adjacentEdges;
		out << std::endl;
	}

	out << std::endl;
	return out.str();
}
