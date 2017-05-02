#include "AdjacencyList.h"
#include <time.h>      
#include <string>
#include "Infinity.h"


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

/* no check for duplicate implementation
void AdjacencyList::add(int adjacent, int weight) {
	AdjacencyListNode* newNode = new AdjacencyListNode(adjacent, weight);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
}*/

void AdjacencyList::add(int adjacent, int weight) {

	AdjacencyListNode* node = find(adjacent);

	if (node != nullptr) {
		node->weight = weight;
		return;
	}

	node = new AdjacencyListNode(adjacent, weight);

	if (head == nullptr) {
		head = node;
		tail = node;
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void AdjacencyList::remove(int adjacent) {

	AdjacencyListNode* nodeToRemove = find(adjacent);
	
	if (nodeToRemove == nullptr)
		return;
	else if (nodeToRemove == head)
		deleteHead();
	else if (nodeToRemove == tail)
		deleteTail();
	else {
		
		nodeToRemove->next->prev = nodeToRemove->prev;
		nodeToRemove->prev->next = nodeToRemove->next;

		delete nodeToRemove;
	}
}

void AdjacencyList::deleteHead() {
	if (head == nullptr) {
		return;
	}
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
	} else {
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
}

void AdjacencyList::deleteTail() {

	if (head == nullptr) {
		return;
	}

	if (tail->prev == nullptr) {
		delete tail;
		tail = nullptr;
		head = nullptr;
	} else {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
}

int AdjacencyList::getEdgeWeight(int adjacent) {
	AdjacencyListNode* node = find(adjacent);

	if (node == nullptr)
		return INF;
	else
		return node->weight;

}

/**
format: [adj1 weigh1 adj2 weigh2 ...]
*/
std::string AdjacencyList::toString() {
	std::string result = "";

	if (head == nullptr) {
		result += "[empty]";
		return result;
	} else {
		result += "[" + std::to_string(head->adjacent);
		result += " " + std::to_string(head->weight) + "] ";
	}

	AdjacencyListNode* iterator = head;

	while (iterator->next != nullptr) {
		iterator = iterator->next;
		result += "[" + std::to_string(iterator->adjacent);
		result += " " + std::to_string(iterator->weight) + "] ";
	}

	return result;
}