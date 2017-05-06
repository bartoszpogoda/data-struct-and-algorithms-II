#include "MSTGraph.h"

#include <sstream>
#include <iomanip>

std::string MSTGraph::toString() {
	std::stringstream out;

	int argWidth = 2;

	out << std::setw(argWidth * 2 + 3) << std::setfill(' ') << "Edge" << "  | ";
	out << std::setw(argWidth) << std::setfill(' ') << "Weight" << std::endl;

	Edge* edges = getAllEdges();
	for (size_t i = 0; i < e; i++) {
		out << "(" << std::setw(argWidth) << edges[i].getStartV() << ", " 
			<< std::setw(argWidth) << edges[i].getEndV() << ") | ";
		out << std::setw(argWidth) << edges[i].getWeight() << std::endl;
	}
	delete[] edges;

	out << std::endl << "MST = " << weight;

	return out.str();
}
