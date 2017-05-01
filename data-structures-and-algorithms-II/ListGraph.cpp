#include "ListGraph.h"

ListGraph::ListGraph(int n) : Graph(n), adjacencyLists(new AdjacencyList*[n]) {
	for (int i = 0; i < n; i++) {
		adjacencyLists[i] = new AdjacencyList();
	}
}

ListGraph::~ListGraph() {
	for (int i = 0; i < n; i++) {
		delete adjacencyLists[i];
	}

	delete[] adjacencyLists;
	adjacencyLists = nullptr;
}

void ListGraph::print(std::ostream & out) {
	for (int i = 0; i < n; i++) {
		out << i << ": " << adjacencyLists[i]->toString() << std::endl;
	}
}
