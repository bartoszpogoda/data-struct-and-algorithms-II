#include "CLInterface.h"

#include <conio.h>

using namespace std;

GraphFileReader* CLInterface::graphFileReader = nullptr;
CLInterface::GraphRep CLInterface::graphRep = CLInterface::GraphRep::LIST;
Graph* CLInterface::graph = nullptr;

void CLInterface::enter() {
	while (!viewInputFilename());

	// data is read at this point
	viewMainMenu();

	delete graphFileReader;
	graphFileReader = nullptr;
}

bool CLInterface::viewInputFilename() {
	system("CLS");
	cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
	
	cout << " > Enter filename: ";

	string readFilename;
	cin >> readFilename;

	delete graphFileReader;
	graphFileReader = new GraphFileReader(readFilename);

	if (graphFileReader->success()) {
		cout << " > Read success";
		handleUserInput();
		return true;
	} else {
		cout << " > Read failure";
		delete graphFileReader;
		graphFileReader = nullptr;
		handleUserInput();
		return false;
	}
}

void CLInterface::viewMainMenu() {
	int selected = 0, max = 2, selectedDelta = 0;

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
			cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Minimum Spanning Tree" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Shortest Path" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Exit" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewMSTMenu();
		}
		else if (selected == 1) {
			viewSPathMenu();
		}
	}
}

void CLInterface::viewPrintedGraph() {
	system("CLS");
	cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
	cout << graph->toString() << endl;
	handleUserInput();
}

void CLInterface::viewGraphRepresentationPick(GraphType type) {
	delete graph;
	int selected = 0, max = 1, selectedDelta = 0;

	system("CLS");
	do {
		if (selected + selectedDelta < 0)
			selected = max;
		else if (selected + selectedDelta > max)
			selected = 0;
		else
			selected += selectedDelta;

		system("CLS");
		cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
		cout << ((selected == 0) ? " > " : "   ") << "Adjacency Lists" << endl;
		cout << ((selected == 1) ? " > " : "   ") << "Adjacency Matrix" << endl;
	} while ((selectedDelta = handleUserInput()) != 0);

	if (selected == 0) {
		graphRep = GraphRep::LIST;
		if (type == GraphType::DIR) {
			graph = graphFileReader->asDirectedListGraph();
		} else {
			graph = graphFileReader->asUndirectedListGraph();
		}
	} else if (selected == 1) {
		graphRep = GraphRep::MATRIX;
		if (type == GraphType::DIR) {
			graph = graphFileReader->asDirectedMatrixGraph();
		} else {
			graph = graphFileReader->asUndirectedMatrixGraph();
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