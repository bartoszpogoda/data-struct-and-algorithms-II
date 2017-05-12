#pragma once
#include "MinimumHeap.h"

/*

*/
template <class Type>
class SearchableMinimumHeap : public MinimumHeap<Type> {
	int* IDPositionMap;

	void fixUp(int nodeId);
	void fixDown(int nodeId);

public:
	SearchableMinimumHeap(int maxSize);
	~SearchableMinimumHeap();

	void add(Type element);
	void update(int id, Type newElement);
	Type get(int id);

	Type popRoot();
};
