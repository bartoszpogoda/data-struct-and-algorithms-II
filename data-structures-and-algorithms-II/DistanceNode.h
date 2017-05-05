#pragma once
#include "Infinity.h"
#include "HeapElement.h"

class DistanceNode : public HeapElement {
	int verticle, distance, previous;
public:
	DistanceNode(int verticle, int distance, int previous) : verticle(verticle), distance(distance), previous(previous) {}
	DistanceNode(int verticle) : verticle(verticle), distance(INF), previous(-1) {}
	DistanceNode() : verticle(-1), distance(INF), previous(-1) {}

	int getVerticle() { return verticle; }
	int getDistance() { return distance; }
	int getPrevious() { return previous; }

	int getKey() { return distance; }
	int getID() { return verticle; }
};
