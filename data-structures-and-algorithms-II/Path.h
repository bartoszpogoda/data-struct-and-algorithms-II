#pragma once
#include "PathNode.h"

class Path{
	int startVerticle;
	int numberOfVerticles;
	PathNode* verticles;
public:
	Path(int startVerticle, int numberOfVerticles, PathNode* verticles) : startVerticle(startVerticle), numberOfVerticles(numberOfVerticles), 
		verticles(verticles) { }
	~Path() { delete[] verticles; }

	PathNode* getPathNodes() { return verticles; }
	int getStartVerticle() { return startVerticle; }
	int getNumberOfVerticles() { return numberOfVerticles; }

	std::string toString();
};

