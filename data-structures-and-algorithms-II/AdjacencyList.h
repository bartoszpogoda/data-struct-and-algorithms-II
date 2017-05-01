#pragma once
#include "AdjacencyListNode.h"
#include <iostream>

class AdjacencyList {
	AdjacencyListNode* head;
	AdjacencyListNode* tail;

	AdjacencyListNode* find(int adjacent);
	void AdjacencyList::deleteHead();
	void AdjacencyList::deleteTail();

public:
	AdjacencyList() : head(nullptr), tail(nullptr) {}
	~AdjacencyList();

	void addEnd(int adjacent, int weight);
	void remove(int adjacent);
	int getEdgeWeight(int adjacent);

	std::string toString();
};