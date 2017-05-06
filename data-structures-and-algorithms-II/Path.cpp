#include "Path.h"

#include <sstream>
#include <iomanip>

std::string Path::toString() {

	std::stringstream out;

	out << "Start = " << startVerticle << std::endl;
	int argWidth = 4;

	out << std::setw(argWidth) << std::setfill(' ') << "End" << " | ";
	out << std::setw(argWidth) << std::setfill(' ') << "Dist" << " | ";
	out << std::setw(argWidth) << std::setfill(' ') << "Path" << std::endl;

	for (size_t i = 0; i < numberOfVerticles; i++) {
		out << std::setw(argWidth) << std::setfill(' ') << verticles[i].getVerticle() << " | ";
		out << std::setw(argWidth) << std::setfill(' ') << verticles[i].getDistance() << " | ";

		std::string path = std::to_string(verticles[i].getVerticle());

		int iter = i;
		while ((iter = verticles[iter].getPrevious()) != -1) {
			path.insert(0, std::to_string(verticles[iter].getVerticle()) + " ");
		}

		out << path << std::endl;
	}

	return out.str();
}
