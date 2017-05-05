#pragma once
#include "Infinity.h"

class Edge {
	int startV, endV, weight;
public:
	Edge(int startV, int endV, int weight) : startV(startV), endV(endV), weight(weight) {}
	Edge() : startV(-1), endV(-1), weight(INF) {}
	
	int getStartV() { return startV; }
	int getEndV() { return endV; }
	int getWeight() { return weight; }

	int getKey() { return 0; }
};
