#include "SPath.h"

#include <iomanip>
#include <sstream>

/* may cause stackoverflow
	void SPath::printPath(DistanceNode * node, std::ostream & out) {
	if (node->getPrevious() == -1) {
		out << node->getVerticle() << " ";
	} else {
		printPath(&result[node->getPrevious()], out);
		out << node->getVerticle() << " ";
	}
} */

DistanceNode * SPath::getResult() {
	DistanceNode* result = this->result;
	this->result = nullptr;
	return result;
}

std::string SPath::resultToString() {
	return resultToString(result, resultSize);
}

std::string SPath::resultToString(DistanceNode * result, int resultSize) {
	std::stringstream out;

	out << "Start = " << startVerticle << std::endl;
	int argWidth = 4;

	out << std::setw(argWidth) << std::setfill(' ') << "End" << " | ";
	out << std::setw(argWidth) << std::setfill(' ') << "Dist" << " | ";
	out << std::setw(argWidth) << std::setfill(' ') << "Path" << std::endl;

	for (size_t i = 0; i < resultSize; i++) {
		out << std::setw(argWidth) << std::setfill(' ') << result[i].getVerticle() << " | ";
		out << std::setw(argWidth) << std::setfill(' ') << result[i].getDistance() << " | ";

		std::string path = std::to_string(result[i].getVerticle());

		int iter = i;
		while ((iter = result[iter].getPrevious()) != -1) {
			path.insert(0, std::to_string(result[iter].getVerticle()) + " ");
		}

		out << path << std::endl;
	}

	return out.str();
}
