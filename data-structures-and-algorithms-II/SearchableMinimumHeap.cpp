#include "SearchableMinimumHeap.h"
#include "PathNode.h"

template<class Type>
void SearchableMinimumHeap<Type>::fixUp(int nodeId) {
	while (parent(nodeId) >= 0) {
		// if parent has bigger weight
		if (elements[parent(nodeId)].getKey() > elements[nodeId].getKey()) {

			// update ID to position mapping
			IDPositionMap[elements[nodeId].getID()] = parent(nodeId);
			IDPositionMap[elements[parent(nodeId)].getID()] = nodeId;

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
void SearchableMinimumHeap<Type>::fixDown(int nodeId) {
	while (leftChild(nodeId) < currentSize) {
		// if left child has less value
		if (elements[leftChild(nodeId)].getKey() < elements[nodeId].getKey()) {
			// if right child exists and has less value than left
			if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)].getKey() < elements[leftChild(nodeId)].getKey()) {
				
				// update ID to position mapping
				IDPositionMap[elements[nodeId].getID()] = rightChild(nodeId);
				IDPositionMap[elements[rightChild(nodeId)].getID()] = nodeId;

				// swap with right child
				Type dataHolder = elements[nodeId];
				elements[nodeId] = elements[rightChild(nodeId)];
				elements[rightChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = rightChild(nodeId);
			} else {

				// update ID to position mapping
				IDPositionMap[elements[nodeId].getID()] = leftChild(nodeId);
				IDPositionMap[elements[leftChild(nodeId)].getID()] = nodeId;

				// swap with left child
				Type dataHolder = elements[nodeId];
				elements[nodeId] = elements[leftChild(nodeId)];
				elements[leftChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = leftChild(nodeId);
			}

		} // if right child exists and has less value
		else if (rightChild(nodeId) < currentSize && elements[rightChild(nodeId)].getKey() < elements[nodeId].getKey()) {
			
			// update ID to position mapping
			IDPositionMap[elements[nodeId].getID()] = rightChild(nodeId);
			IDPositionMap[elements[rightChild(nodeId)].getID()] = nodeId;

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
SearchableMinimumHeap<Type>::SearchableMinimumHeap(int maxSize) : MinimumHeap(maxSize), IDPositionMap(new int[maxSize]) {
	for (size_t i = 0; i < maxSize; i++) {
		IDPositionMap[i] = -1;
	}
}

template<class Type>
SearchableMinimumHeap<Type>::~SearchableMinimumHeap() {
	delete[] IDPositionMap;
}

template<class Type>
void SearchableMinimumHeap<Type>::add(Type element) {
	if (currentSize == maxSize)
		return;

	elements[currentSize] = element;

	// update ID to position mapping
	IDPositionMap[element.getID()] = currentSize;

	fixUp(currentSize);
	currentSize++;
}

template<class Type>
void SearchableMinimumHeap<Type>::update(int id, Type newElement) {
	int nodeId = IDPositionMap[id];

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
Type SearchableMinimumHeap<Type>::get(int id) {
	if (id < 0 || id > maxSize || IDPositionMap[id] == -1) {
		return Type();
	}
	return elements[IDPositionMap[id]];
}

template<class Type>
Type SearchableMinimumHeap<Type>::popRoot() {
	if (currentSize == 0)
		return Type();

	Type edge = elements[0];

	if (currentSize - 1 == 0) {
		currentSize = 0;
		IDPositionMap[edge.getID()] = -1;
		return edge;
	}

	// last node becomes root
	elements[0] = elements[currentSize - 1];

	IDPositionMap[edge.getID()] = -1;
	IDPositionMap[elements[0].getID()] = 0;

	// currentSize must be decreased before fixDown
	currentSize--;
	fixDown(0);

	return edge;
}


// explicit instantiations
template class SearchableMinimumHeap<PathNode>;