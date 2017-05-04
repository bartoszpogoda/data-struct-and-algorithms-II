#include "AdjacencyList.h"
#include <time.h>      
#include <string>
#include <sstream>   
#include <iomanip>   
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

	size++;
}

Edge * AdjacencyList::getEdges() {
	if (size <= 0) return nullptr;

	Edge* edges = new Edge[size];

	AdjacencyListNode* iterator = head;
	for (size_t i = 0; i < size; i++) {
		edges[i] = Edge(verticle, iterator->adjacent, iterator->weight);

		iterator = iterator->next;
	}
}


/**
format: [adj1 weigh1 adj2 weigh2 ...]
*/
std::string AdjacencyList::toString(int width) {
	std::stringstream result;
	result << "";

	if (head == nullptr) {
		return result.str();
	} else {
		result << "(" << std::setw(width-1) << std::setfill(' ') << head->adjacent << "v;"
			<< std::setw(width-1) << std::setfill(' ') << head->weight << "w) ";
	}

	AdjacencyListNode* iterator = head;

	while (iterator->next != nullptr) {
		iterator = iterator->next;
		result << "(" << std::setw(width-1) << std::setfill(' ') << iterator->adjacent << "v;"
			<< std::setw(width-1) << std::setfill(' ') << iterator->weight << "w) ";
	}

	return result.str();
}