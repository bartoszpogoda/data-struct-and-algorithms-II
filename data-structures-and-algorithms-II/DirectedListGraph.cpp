#include "DirectedListGraph.h"

void DirectedListGraph::addEdge(int beginV, int endV, int weight) {

	adjacencyLists[beginV]->add(endV, weight);
}

int DirectedListGraph::checkEdge(int beginV, int endV) {
	return adjacencyLists[beginV]->getEdgeWeight(endV);
}

void DirectedListGraph::removeEdge(int beginV, int endV) {
	adjacencyLists[beginV]->remove(endV);
}

int DirectedListGraph::degree() {
	return 0;
}
