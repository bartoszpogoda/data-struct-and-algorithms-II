#pragma once
#include "Edge.h"
#include <string>

class MinimumEdgeHeap {

private:
	Edge** elements;
	int currentSize;

	void fixUp(int nodeId);
	void fixDown(int nodeId);

	int parent(int nodeId) { return (nodeId - 1) / 2; }
	int leftChild(int nodeId) { return 2 * nodeId + 1; }
	int rightChild(int nodeId) { return 2 * nodeId + 2; }

public:
	MinimumEdgeHeap() : elements(nullptr), currentSize(0) {};
	MinimumEdgeHeap(Edge** elements, int size);
	~MinimumEdgeHeap();

	int size() { return currentSize; }

	void add(Edge* element);
	Edge* getRoot();


	std::string toStringTable();
};