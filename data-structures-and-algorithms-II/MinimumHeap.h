#pragma once
#include <string>

/*
	MinimumHeap is fixed size in memory after construction
	It allocates memory for (maxSize) specified in constructor
	It rejects any elements that don't fit 
	It dealocates memory on object destruction

	"Greedy" alocation to avoid O(n) additions and deletions
*/
template <class Type>
class MinimumHeap {
protected:
	Type* elements;

	int currentSize;
	int maxSize;

	void fixUp(int nodeId);
	void fixDown(int nodeId);

	int parent(int nodeId) { return (nodeId - 1) / 2; }
	int leftChild(int nodeId) { return 2 * nodeId + 1; }
	int rightChild(int nodeId) { return 2 * nodeId + 2; }

public:
	MinimumHeap(int maxSize) : elements(new Type[maxSize]), currentSize(0), maxSize(maxSize) {};
	MinimumHeap(Type* elements, int size);
	virtual ~MinimumHeap();

	int size() { return currentSize; }
	bool isEmpty() { return currentSize == 0; }

	void add(Type element);

	Type popRoot();

	std::string toString();
};