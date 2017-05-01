#include <iostream>
#include <string>
#include "CLInterface.h"
#include "AdjacencyList.h"

int main() {

	AdjacencyList* list = new AdjacencyList();

	list->addEnd(2, 3);
	list->addEnd(4, 2);
	list->addEnd(1, 1);
	list->remove(1);
	list->remove(4);
	list->remove(2);
	
	std::cout << list->toString();


	int x;
	std::cin >> x;

	// CLInterface::enter();
}