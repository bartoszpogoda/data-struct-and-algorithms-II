#include "IndirectedListGraph.h"

int IndirectedListGraph::degree(int verticle) {
	return adjacencyLists[verticle]->getSize();
}

void IndirectedListGraph::addEdge(Edge edge) {
	adjacencyLists[edge.getStartV()]->add(edge.getEndV(), edge.getWeight());
	adjacencyLists[edge.getEndV()]->add(edge.getStartV(), edge.getWeight());
}

// TODO:  move common implementations to ListGraph class
Edge * IndirectedListGraph::getAdjacentEdges(int verticle) {
	return adjacencyLists[verticle]->getEdges();
}

Edge * IndirectedListGraph::getAllEdges() {
	//TODO: implement
	return nullptr;
}
