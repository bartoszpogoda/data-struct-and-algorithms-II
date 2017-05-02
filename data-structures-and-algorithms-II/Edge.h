#pragma once

class Edge {
	int startV, endV, weight;
public:
	Edge(int startV, int endV, int weight) : startV(startV), endV(endV), weight(weight) {}
	
	int getStartV() { return startV; }
	int getEndV() { return endV; }
	int getWeight() { return weight; }
};
