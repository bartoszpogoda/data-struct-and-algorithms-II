#include "IndirectedListGraph.h"
#include <algorithm>

void IndirectedListGraph::addEdge(int beginV, int endV, int weight) {
	adjacencyLists[std::min(beginV, endV)]->add(std::max(beginV, endV), weight);
}

int IndirectedListGraph::checkEdge(int beginV, int endV) {
	return adjacencyLists[std::min(beginV, endV)]->getEdgeWeight(std::max(beginV, endV));
}

void IndirectedListGraph::removeEdge(int beginV, int endV) {
	adjacencyLists[std::min(beginV, endV)]->remove(std::max(beginV, endV));
}

int IndirectedListGraph::degree() {
	return 0;
}
