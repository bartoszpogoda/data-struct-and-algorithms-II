#include "MinimumEdgeHeap.h"
#include <string>

void MinimumEdgeHeap::fixUp(int nodeId) {
	while (parent(nodeId) >= 0) {
		// if parent has bigger weight
		if (elements[parent(nodeId)]->getWeight() > elements[nodeId]->getWeight()) {
			// swap with parent
			Edge* dataHolder = elements[nodeId];
			elements[nodeId] = elements[parent(nodeId)];
			elements[parent(nodeId)] = dataHolder;

			// for next iteration
			nodeId = parent(nodeId);
		} else {
			// heap fixed
			return;
		}
	}
}

void MinimumEdgeHeap::fixDown(int nodeId) {
	while (leftChild(nodeId) < currentSize) {
		// if left child has less value
		if (elements[leftChild(nodeId)]->getWeight() < elements[nodeId]->getWeight()) {
			// if right child exists and has less value than left
			if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)]->getWeight() < elements[leftChild(nodeId)]->getWeight()) {
				// swap with right child
				Edge* dataHolder = elements[nodeId];
				elements[nodeId] = elements[rightChild(nodeId)];
				elements[rightChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = rightChild(nodeId);
			} else {
				// swap with left child
				Edge* dataHolder = elements[nodeId];
				elements[nodeId] = elements[leftChild(nodeId)];
				elements[leftChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = leftChild(nodeId);
			}

		} // if right child exists and has less value
		else if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)]->getWeight() < elements[nodeId]->getWeight()) {
			// swap with right child
			Edge* dataHolder = elements[nodeId];
			elements[nodeId] = elements[rightChild(nodeId)];
			elements[rightChild(nodeId)] = dataHolder;

			// for next iteration
			nodeId = rightChild(nodeId);
		} else {
			// heap fixed
			return;
		}
	}
}

MinimumEdgeHeap::MinimumEdgeHeap(Edge ** elements, int size) {
	currentSize = size;
	this->elements = new Edge*[currentSize];

	for (int i = 0; i < currentSize; i++) {
		this->elements[i] = elements[i];
	}

	// fix heap - start from last parent
	int parentIteration = parent(currentSize - 1);
	do {
		fixDown(parentIteration);
	} while (--parentIteration >= 0);
}

MinimumEdgeHeap::~MinimumEdgeHeap() {
	if (elements == nullptr)
		return;

	for (size_t i = 0; i < currentSize; i++) {
		delete elements[i];
	}

	delete[] elements;
}

void MinimumEdgeHeap::add(Edge* element) {
	if (elements == nullptr) {
		elements = new Edge*[1];
		elements[0] = element;
	} else {
		Edge** newElements = new Edge*[currentSize + 1];

		for (int i = 0; i < currentSize; i++) {
			newElements[i] = elements[i];
		}

		newElements[currentSize] = element;

		delete[] elements;
		elements = newElements;

		fixUp(currentSize);
	}

	currentSize++;
}

Edge* MinimumEdgeHeap::getRoot() {
	if (elements == nullptr)
		return nullptr;

	Edge* edge = elements[0];

	if (currentSize - 1 == 0) {
		delete[] elements;
		elements = nullptr;
		currentSize = 0;
		return edge;
	}

	Edge** newElements = new Edge*[currentSize - 1];

	// last node becomes root
	newElements[0] = elements[currentSize - 1];

	for (int i = 1; i < currentSize - 1; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;

	// currentSize must be decreased before fixDown
	currentSize--;
	fixDown(0);

	return edge;
}

std::string MinimumEdgeHeap::toStringTable() {
	std::string result = "[";

	if (currentSize == 0) {
		result += "empty]";
		return result;
	}

	for (int i = 0; i < currentSize; i++) {
		result += std::to_string(elements[i]->getStartV()) + " "
			+ std::to_string(elements[i]->getEndV()) + " "
			+ std::to_string(elements[i]->getWeight()) + "  ";
	}

	result.pop_back(); // deletes extra whitespace
	result += "]";

	return result;
}
