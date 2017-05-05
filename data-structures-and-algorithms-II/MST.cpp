#include "MST.h"

MSTGraph * MST::getResult() {
	MSTGraph* result = this->result;
	this->result = nullptr;
	return result;
}

