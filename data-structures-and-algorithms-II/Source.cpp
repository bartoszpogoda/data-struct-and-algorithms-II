#include <iostream>

#include "CLInterface.h"
#include "PerformanceTester.h"

#include "MSTKruskal.h"
#include "UndirectedListGraph.h"
#include "GraphGeneratorExact.h"

int main() {

	
	PerformanceTester pt = PerformanceTester();
	pt.run();


	int c;
	std::cin >> c;

	CLInterface::enter();
	
	

	int x;
	std::cin >> x; 
}