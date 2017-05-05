#pragma once
#include "Edge.h"

#include <iostream>

class AdjacencyList {
	class AdjacencyListNode;

	AdjacencyListNode* head;
	AdjacencyListNode* tail;
	int verticle;				// a verticle that adjacents the list describes
	int size;					// verticle's degree

	AdjacencyListNode* find(int adjacent);
public:
	AdjacencyList(int verticle) : head(nullptr), tail(nullptr), size(0), verticle(verticle) {}
	~AdjacencyList();

	int getSize() { return size; }
	bool add(int adjacent, int weight);	// true if added, false if modified
	Edge* getEdges();
};


class AdjacencyList::AdjacencyListNode {
public:
	AdjacencyListNode* prev;
	AdjacencyListNode* next;

	int adjacent;
	int weight;

	AdjacencyListNode(int adjacent, int weight) : adjacent(adjacent), weight(weight), prev(nullptr), next(nullptr) {}
};
