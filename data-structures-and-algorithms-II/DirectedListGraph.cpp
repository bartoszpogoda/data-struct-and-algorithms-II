#include "DirectedListGraph.h"

int DirectedListGraph::degree(int verticle) {
	return adjacencyLists[verticle]->getSize();
}

void DirectedListGraph::addEdge(Edge edge) {
	adjacencyLists[edge.getStartV()]->add(edge.getEndV(), edge.getWeight());
}

Edge * DirectedListGraph::getAdjacentEdges(int verticle) {
	return adjacencyLists[verticle]->getEdges();
}

Edge * DirectedListGraph::getAllEdges() {
	//TODO: implement
	return nullptr;
}
