#include "MST.h"

Graph * MST::getResultMST() {
	Graph* resultMST = this->resultMST;
	this->resultMST = nullptr;
	return resultMST;
}

int MST::getResultWeight() {
	int resultWeight = this->resultWeight;
	this->resultWeight = INF;
	return resultWeight;
}
