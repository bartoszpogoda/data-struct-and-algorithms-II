#pragma once
#include <iostream>

class AdjacencyList {
	class AdjacencyListNode;

	AdjacencyListNode* head;
	AdjacencyListNode* tail;

	AdjacencyListNode* find(int adjacent);
	void AdjacencyList::deleteHead();
	void AdjacencyList::deleteTail();

public:
	AdjacencyList() : head(nullptr), tail(nullptr) {}
	~AdjacencyList();

	void add(int adjacent, int weight);
	void remove(int adjacent);
	int getEdgeWeight(int adjacent);

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