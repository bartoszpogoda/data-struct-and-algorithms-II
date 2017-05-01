#pragma once
#include "Infinity.h"

class AdjacencyListNode {
	AdjacencyListNode* prev;
	AdjacencyListNode* next;

	int adjacent;
	int weight;

public:
	AdjacencyListNode(int adjacent, int weight) : adjacent(adjacent), weight(weight), prev(nullptr), next(nullptr) {}

	AdjacencyListNode* getPrev() { return prev; }
	void setPrev(AdjacencyListNode* prev) { this->prev = prev; }

	AdjacencyListNode* getNext() { return next; }
	void setNext(AdjacencyListNode* next) { this->next = next; }

	int getAdjacent() { return adjacent; }
	void setAdjacent(int adjacent) { this->adjacent = adjacent; }

	int getWeight() { return weight; }
	void setWeight(int weight) { this->weight = weight; }

};