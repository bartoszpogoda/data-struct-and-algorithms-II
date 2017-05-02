#include "IndirectedListGraph.h"
#include <algorithm>

void IndirectedListGraph::addEdge(int beginV, int endV, int weight) {
	adjacencyLists[std::max(beginV, endV)]->add(std::min(beginV, endV), weight);
}

int IndirectedListGraph::checkEdge(int beginV, int endV) {
	return adjacencyLists[std::max(beginV, endV)]->getEdgeWeight(std::min(beginV, endV));
}

void IndirectedListGraph::removeEdge(int beginV, int endV) {
	adjacencyLists[std::max(beginV, endV)]->remove(std::min(beginV, endV));
}

int IndirectedListGraph::degree() {
	return 0;
}
