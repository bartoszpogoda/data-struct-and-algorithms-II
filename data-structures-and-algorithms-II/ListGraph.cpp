#include "ListGraph.h"

#include <string>
#include <iomanip>

ListGraph::ListGraph(int n) : Graph(n), adjacencyLists(new AdjacencyList*[n]) {
	for (int i = 0; i < n; i++) {
		adjacencyLists[i] = new AdjacencyList(i);
	}
}

ListGraph::~ListGraph() {
	for (int i = 0; i < n; i++) {
		delete adjacencyLists[i];
	}

	delete[] adjacencyLists;
	adjacencyLists = nullptr;
}

int ListGraph::degree(int verticle) {
	return adjacencyLists[verticle]->getSize();
}

Edge * ListGraph::getAdjacentEdges(int verticle) {
	return adjacencyLists[verticle]->getEdges();
}

bool ListGraph::hasEdge(Edge edge) {
	Edge* adjacents = adjacencyLists[edge.getStartV()]->getEdges();
	
	for (size_t i = 0; i < adjacencyLists[edge.getStartV()]->getSize(); i++) {
		if (adjacents[i].getEndV() == edge.getEndV()) {
			delete[] adjacents;
			return true;
		}
	}

	delete[] adjacents;
	return false;
}

void ListGraph::clearEdges() {
	for (int i = 0; i < n; i++) {
		delete adjacencyLists[i];
		adjacencyLists[i] = new AdjacencyList(i);
	}
	e = 0;
}
