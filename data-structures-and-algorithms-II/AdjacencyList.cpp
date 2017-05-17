#include "AdjacencyList.h"
#include "Infinity.h"

#include <time.h>      
#include <string>
#include <sstream>   
#include <iomanip>   

AdjacencyList::AdjacencyListNode * AdjacencyList::find(int adjacent) {
	if (head == nullptr)
		return nullptr;

	AdjacencyListNode* iterator = head;
	while (iterator->next != nullptr && iterator->adjacent != adjacent) {
		iterator = iterator->next;
	}

	if (iterator->adjacent == adjacent)
		return iterator;
	else return nullptr;
}

AdjacencyList::~AdjacencyList() {
	if (head == nullptr)
		return;

	AdjacencyListNode* iterator = tail;

	while (iterator->prev != nullptr) {
		iterator = iterator->prev;
		delete iterator->next;
	}

	delete iterator;
}


bool AdjacencyList::add(int adjacent, int weight) {

	/*AdjacencyListNode* node = find(adjacent);		unsafe to comment that but helps performance

	if (node != nullptr) {
		node->weight = weight;
		return false;
	}*/		

	AdjacencyListNode* node = new AdjacencyListNode(adjacent, weight);

	if (head == nullptr) {
		head = node;
		tail = node;
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}

	size++;
	return true;
}

bool AdjacencyList::rem(int adjacent) {
	AdjacencyListNode* nodeToRemove = find(adjacent);

	if (nodeToRemove == nullptr) return false;

	if (nodeToRemove == head) {
		if (head->next == nullptr) {
			head = nullptr;
			tail = nullptr;
		} else {
			head = head->next;
			head->prev = nullptr;
		}
		// zmniejszyc size!
	}
	else if (nodeToRemove == tail) {
		if (tail->prev == nullptr) {
			tail = nullptr;
			head = nullptr;
		} else {
			tail = tail->prev;
			tail->next = nullptr;
		}
	}
	else {
		nodeToRemove->next->prev = nodeToRemove->prev;
		nodeToRemove->prev->next = nodeToRemove->next;
	}

	delete nodeToRemove;
	size--;
	return true;
}

Edge * AdjacencyList::getEdges() {
	if (size <= 0) return nullptr;

	Edge* edges = new Edge[size];

	AdjacencyListNode* iterator = head;
	for (size_t i = 0; i < size; i++) {
		edges[i] = Edge(verticle, iterator->adjacent, iterator->weight);

		iterator = iterator->next;
	}

	return edges;
}
