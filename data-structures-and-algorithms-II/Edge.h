#pragma once
#include "Infinity.h"
#include "HeapElement.h"

/*
	Simple structure to represent edges
	in algorithms
*/
class Edge : public HeapElement{
	int startV, endV, weight;
public:
	Edge(int startV, int endV, int weight) : startV(startV), endV(endV), weight(weight) {}
	Edge() : startV(-1), endV(-1), weight(INF) {}
	
	int getStartV() { return startV; }
	int getEndV() { return endV; }
	int getWeight() { return weight; }

	int getKey() { return weight; }
	int getID() { return 13*startV + 23*endV; }	// it's not used
};
