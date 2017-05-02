#include "DisjointSet.h"


DisjointSet::Node* DisjointSet::find(int elem) {
	Node *iterator = nodes[elem];

	while (iterator->parent != nullptr)
		iterator = iterator->parent;

	return iterator;
}

void DisjointSet::makeSet(int elem) {
	nodes[elem] = new Node(elem);
}

DisjointSet::DisjointSet(int n) : n(n) {
	nodes = new Node*[n];
	for (int i = 0; i < n; i++)
		makeSet(i);
}

DisjointSet::~DisjointSet() {
	for (int i = 0; i < n; i++)
		delete nodes[i];
	delete[] nodes;
}

bool DisjointSet::makeUnion(int elemA, int elemB) {
	Node* aRoot = find(elemA);
	Node* bRoot = find(elemB);
	
	if (aRoot != bRoot) {
		aRoot->parent = bRoot;
		return true;
	}
	return false;
}
