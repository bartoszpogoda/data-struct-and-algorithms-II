#pragma once

#include "Graph.h"

class GraphFileData {
	int startVerticle;
	bool errorFlag;
	std::string errorMessage;

public:
	GraphFileData(int startVerticle) : startVerticle(startVerticle), errorFlag(false) { }
	GraphFileData(std::string errorMessage) : errorFlag(true), errorMessage(errorMessage) { }

	int getFirstVerticle() { return startVerticle; }

	bool good() { return !errorFlag; }
	std::string getErrorMessage() { return errorMessage; }
};