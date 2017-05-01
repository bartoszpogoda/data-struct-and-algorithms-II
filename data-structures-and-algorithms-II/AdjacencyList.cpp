#include "AdjacencyList.h"
#include <time.h>      
#include <string>



AdjacencyListNode * AdjacencyList::find(int adjacent) {
	if (head == nullptr)
		return nullptr;

	AdjacencyListNode* iterator = head;
	while (iterator->getNext() != nullptr && iterator->getAdjacent() != adjacent) {
		iterator = iterator->getNext();
	}

	if (iterator->getAdjacent() == adjacent)
		return iterator;
	else return nullptr;
}

AdjacencyList::~AdjacencyList() {
	if (head == nullptr)
		return;

	AdjacencyListNode* iterator = tail;

	while (iterator->getPrev() != nullptr) {
		iterator = iterator->getPrev();
		delete iterator->getNext();
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
		node->setWeight(weight);
		return;
	}

	node = new AdjacencyListNode(adjacent, weight);

	if (head == nullptr) {
		head = node;
		tail = node;
	} else {
		tail->setNext(node);
		node->setPrev(tail);
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
		
		nodeToRemove->getNext()->setPrev(nodeToRemove->getPrev());
		nodeToRemove->getPrev()->setNext(nodeToRemove->getNext());

		delete nodeToRemove;
	}
}

void AdjacencyList::deleteHead() {
	if (head == nullptr) {
		return;
	}
	if (head->getNext() == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
	} else {
		head = head->getNext();
		delete head->getPrev();
		head->setPrev(nullptr);
	}
}

void AdjacencyList::deleteTail() {

	if (head == nullptr) {
		return;
	}

	if (tail->getPrev() == nullptr) {
		delete tail;
		tail = nullptr;
		head = nullptr;
	} else {
		tail = tail->getPrev();
		delete tail->getNext();
		tail->setNext(nullptr);
	}
}

int AdjacencyList::getEdgeWeight(int adjacent) {
	AdjacencyListNode* node = find(adjacent);

	if (node == nullptr)
		return INF;
	else
		return node->getWeight();

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
		result += "[" + std::to_string(head->getAdjacent());
		result += " " + std::to_string(head->getWeight()) + "] ";
	}

	AdjacencyListNode* iterator = head;

	while (iterator->getNext() != nullptr) {
		iterator = iterator->getNext();
		result += "[" + std::to_string(iterator->getAdjacent());
		result += " " + std::to_string(iterator->getWeight()) + "] ";
	}

	return result;
}