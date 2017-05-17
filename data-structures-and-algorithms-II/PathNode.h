#pragma once
#include "Infinity.h"
#include "HeapElement.h"

/*
	Result node for SPath algorithms
	describes verticle, its distance
	and its previous verticle in path
*/
class PathNode : public HeapElement {
	int verticle, distance, previous;
public:
	PathNode(int verticle, int distance, int previous) : verticle(verticle), distance(distance), previous(previous) {}
	PathNode(int verticle) : verticle(verticle), distance(INF), previous(-1) {}
	PathNode() : verticle(-1), distance(INF), previous(-1) {}

	int getVerticle() { return verticle; }
	int getDistance() { return distance; }
	int getPrevious() { return previous; }

	int getKey() { return distance; }
	int getID() { return verticle; }
};
