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
