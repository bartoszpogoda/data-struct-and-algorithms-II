#pragma once
#include <iostream>
#include "Edge.h"

class AdjacencyList {
	class AdjacencyListNode;

	AdjacencyListNode* head;
	AdjacencyListNode* tail;
	int verticle;				// a verticle that adjacents the list describes
	int size;

	AdjacencyListNode* find(int adjacent);

public:
	AdjacencyList(int verticle) : head(nullptr), tail(nullptr), size(0), verticle(verticle) {}
	~AdjacencyList();

	int getSize() { return size; }
	void add(int adjacent, int weight);
	Edge* getEdges();

	std::string toString(int width);
};


class AdjacencyList::AdjacencyListNode {
public:
	AdjacencyListNode* prev;
	AdjacencyListNode* next;

	int adjacent;
	int weight;

	AdjacencyListNode(int adjacent, int weight) : adjacent(adjacent), weight(weight), prev(nullptr), next(nullptr) {}
};
