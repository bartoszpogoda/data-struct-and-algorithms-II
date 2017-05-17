#include "UndirectedListGraph.h"

#include <iomanip>
#include <sstream>

void UndirectedListGraph::addEdge(Edge edge) {
	if (adjacencyLists[edge.getStartV()]->add(edge.getEndV(), edge.getWeight()))
		e++;

	adjacencyLists[edge.getEndV()]->add(edge.getStartV(), edge.getWeight());
}

void UndirectedListGraph::remEdge(Edge edge) {
	if (adjacencyLists[edge.getStartV()]->rem(edge.getEndV()))
		e--;

	adjacencyLists[edge.getEndV()]->rem(edge.getStartV());
}

Edge * UndirectedListGraph::getAllEdges() {
	Edge* edges = new Edge[e];

	int foundEdges = 0;
	for (size_t i = 0; i < n; i++) {
		Edge* adjacentEdges = adjacencyLists[i]->getEdges();	// contains mirror edges
		int verticleDegree = adjacencyLists[i]->getSize();

		for (size_t j = 0; j < verticleDegree; j++) {
			// to get rid of mirror edges (1->2 and 2->1)
			if(adjacentEdges[j].getStartV() <= adjacentEdges[j].getEndV())
				edges[foundEdges++] = adjacentEdges[j];
		}

		delete[] adjacentEdges;
	}

	return edges;
}

std::string UndirectedListGraph::toString() {
	std::stringstream out;
	out << "Type: Undirected Graph" << std::endl << "Representation: Adjacency Lists" << std::endl << std::endl;

	int argWidth = 3;

	// main data loop
	for (size_t i = 0; i < n; i++) {
		out << std::setw(argWidth + 3) << std::setfill(' ') << i << " | ";

		// adjacents data loop
		Edge* adjacentEdges = adjacencyLists[i]->getEdges();
		for (size_t j = 0; j < adjacencyLists[i]->getSize(); j++) {

			if(adjacentEdges[j].getStartV() <= adjacentEdges[j].getEndV())	// to filter mirror duplicates
				out << "(" << std::setw(argWidth) << std::setfill(' ') << adjacentEdges[j].getEndV() << "v;"
					<< std::setw(argWidth) << std::setfill(' ') << adjacentEdges[j].getWeight() << "w) ";
		}

		delete[] adjacentEdges;
		out << std::endl;
	}
	out << std::endl;
	return out.str();
}
