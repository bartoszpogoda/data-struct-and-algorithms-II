#pragma once

class DisjointSet {
	class Node;

	Node** nodes;
	int n;

	Node* find(int elem);
	void makeSet(int elem);

public:
	DisjointSet(int n);
	~DisjointSet();

	bool makeUnion(int elemA, int elemB);
};

class DisjointSet::Node {
public:
	Node* parent;
	int elem;

	Node(int elem) : elem(elem), parent(nullptr) {}
};