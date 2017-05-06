#include "SPath.h"

Path * SPath::getResult() {
	Path* result = this->result;
	this->result = nullptr;
	return result;
}
