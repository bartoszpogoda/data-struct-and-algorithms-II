#include "ListGraph.h"
#include <string>
#include <iomanip>

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
	
	out << "Adjacency Lists: " << std::endl;

	int argWidth = 13;

	/*// title row
	out << std::setw(argWidth/2) << std::setfill(' ') << "v" << "|";
	out << std::setw(((argWidth+1)*n) / 2 + 2) << "Edges";
	out << std::endl;

	// +---+.... row
	out << std::setw(argWidth/2) << std::setfill('-') << "" << "+";
	for (size_t i = 0; i < n; i++)
		out << std::setw(argWidth) << std::setfill('-') << "" << "+";
	out << std::endl;*/

	// main data loop
	for (size_t i = 0; i < n; i++) {
		out << std::setw(argWidth/2) << std::setfill(' ') << i << "|" << adjacencyLists[i]->toString((argWidth-2)/2) << std::endl;
	}

	out << std::endl;
}
