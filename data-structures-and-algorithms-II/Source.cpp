#include "CLInterface.h"
#include "PerformanceTester.h"

#include <iostream>

int main(int argc, char* argv[]) {

	if (argc == 2 && strcmp(argv[1],"p") == 0) {
		PerformanceTester pt = PerformanceTester();
		pt.run();

		std::cout << "Confirm exit." << std::endl;
		int x;
		std::cin >> x;
	} else if (argc >= 2) {
		std::cout << "Usage:\n -Run without arguments to enter CLI.\n -Run with 'p' argument to execute performance tests";
	} else {
		CLInterface::enter();
	}
}