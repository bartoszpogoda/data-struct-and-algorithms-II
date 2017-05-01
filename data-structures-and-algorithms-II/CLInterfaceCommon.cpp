#include "CLInterface.h"
#include <conio.h>

using namespace std;

void CLInterface::enter() {
	viewMainMenu();
}

void CLInterface::viewMainMenu() {
	int selected = 0, max = 3, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta < 0)
				selected = max;
			else if (selected + selectedDelta > max)
				selected = 0;
			else
				selected += selectedDelta;

			system("CLS");
			cout << "-- Welcome to CLI: --" << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "a" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "b" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "c" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Exit" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			// stuff
		}
		else if (selected == 1) {
			// stuff
		}
		else if (selected == 2) {
			// stuff
		}
	}
}


int CLInterface::handleUserInput() {
	int c = 0;

	while ((c = getch())) {
		if (c == KEY_UP) {
			return -1;
		}
		else if (c == KEY_DOWN) {
			return 1;
		}
		else if (c == ENTER) {
			return 0;
		}

		c = 0;
	}
}