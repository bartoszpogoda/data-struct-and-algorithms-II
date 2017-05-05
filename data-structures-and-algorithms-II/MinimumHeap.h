#pragma once

#include <iostream> // temp

template <class Type>
class MinimumHeap {
	Type* elements;
	int currentSize;

	void fixUp(int nodeId);
	void fixDown(int nodeId);

	int parent(int nodeId) { return (nodeId - 1) / 2; }
	int leftChild(int nodeId) { return 2 * nodeId + 1; }
	int rightChild(int nodeId) { return 2 * nodeId + 2; }

	int find(int id);

public:
	MinimumHeap() : elements(nullptr), currentSize(0) {};
	MinimumHeap(Type* elements, int size);
	~MinimumHeap();

	int size() { return currentSize; }
	bool isEmpty() { return currentSize == 0; }

	void add(Type element);
	void update(int id, Type newElement);
	Type get(int id);

	Type popRoot();

	std::string toStringTable();
};