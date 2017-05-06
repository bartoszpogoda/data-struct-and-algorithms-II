#include "MinimumHeap.h"
#include "PathNode.h"
#include "Edge.h"

#include <string>
#include <iostream>

template<class Type>
void MinimumHeap<Type>::fixUp(int nodeId) {
	while (parent(nodeId) >= 0) {
		// if parent has bigger weight
		if (elements[parent(nodeId)].getKey() > elements[nodeId].getKey()) {
			// swap with parent
			Type dataHolder = elements[nodeId];
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

template<class Type>
void MinimumHeap<Type>::fixDown(int nodeId) {
	while (leftChild(nodeId) < currentSize) {
		// if left child has less value
		if (elements[leftChild(nodeId)].getKey() < elements[nodeId].getKey()) {
			// if right child exists and has less value than left
			if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)].getKey() < elements[leftChild(nodeId)].getKey()) {
				// swap with right child
				Type dataHolder = elements[nodeId];
				elements[nodeId] = elements[rightChild(nodeId)];
				elements[rightChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = rightChild(nodeId);
			} else {
				// swap with left child
				Type dataHolder = elements[nodeId];
				elements[nodeId] = elements[leftChild(nodeId)];
				elements[leftChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = leftChild(nodeId);
			}

		} // if right child exists and has less value
		else if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)].getKey() < elements[nodeId].getKey()) {
			// swap with right child
			Type dataHolder = elements[nodeId];
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

template<class Type>
int MinimumHeap<Type>::find(int id) {

	for (int i = 0; i < currentSize; i++) {
		if (elements[i].getID() == id)
			return i;
	}

	return -1;
}

template<class Type>
MinimumHeap<Type>::MinimumHeap(Type * elements, int size) {
	currentSize = size;
	this->elements = elements;

	// fix heap - start from last parent
	int parentIteration = parent(currentSize - 1);
	do {
		fixDown(parentIteration);
	} while (--parentIteration >= 0);
}

template<class Type>
MinimumHeap<Type>::~MinimumHeap() {
	delete[] elements;
}

template<class Type>
void MinimumHeap<Type>::add(Type element) {
	if (elements == nullptr) {
		elements = new Type[1];
		elements[0] = element;
	} else {
		Type* newElements = new Type[currentSize + 1];

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

template<class Type>
void MinimumHeap<Type>::update(int id, Type newElement) {
	int nodeId = find(id);

	if (nodeId == -1)
		return;

	if (newElement.getKey() > elements[nodeId].getKey()) {
		elements[nodeId] = newElement;
		fixDown(nodeId);
	} else {
		elements[nodeId] = newElement;
		fixUp(nodeId);
	}

}

template<class Type>
Type MinimumHeap<Type>::get(int id) {
	int nodeId = find(id);

	if (nodeId == -1)
		return Type();

	return elements[nodeId];
}

template<class Type>
Type MinimumHeap<Type>::popRoot() {
	if (elements == nullptr)
		return Type();

	Type edge = elements[0];

	if (currentSize - 1 == 0) {
		delete[] elements;
		elements = nullptr;
		currentSize = 0;
		return edge;
	}

	Type* newElements = new Type[currentSize - 1];

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

template<class Type>
std::string MinimumHeap<Type>::toString() {
	std::string result = "[";

	if (currentSize == 0) {
		result += "empty]";
		return result;
	}

	for (int i = 0; i < currentSize; i++) {
		result += std::to_string(elements[i].getID()) + " "
			+ std::to_string(elements[i].getKey()) + " ";
	}

	result.pop_back(); // deletes extra whitespace
	result += "]";

	return result;
}


// explicit instantiations
template class MinimumHeap<Edge>;
template class MinimumHeap<PathNode>;