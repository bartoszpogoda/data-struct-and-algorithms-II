#include "CLInterface.h"
#include "MSTKruskal.h"
#include "MSTPrim.h"

#include <conio.h>

using namespace std;

void CLInterface::viewMSTMenu() {
	int selected = 0, max = 4, selectedDelta = 0;

	viewGraphRepresentationPick(GraphType::UNDIR);

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
			cout << "Problem: Minimum Spanning Tree" << endl;
			cout << "Representation: " << (graphRep == GraphRep::LIST ? "Adjacency Lists" : "Adjacency Matrix") << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Change graph representation" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Print graph" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Execute Kruskal's algorithm" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Execute Prim's algorithm" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Exit" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewGraphRepresentationPick(GraphType::UNDIR);
		} else if (selected == 1) {
			viewPrintedGraph();
		} else if (selected == 2) {
			viewMSTKruskal();
		} else if (selected == 3) {
			viewMSTPrim();
		}
	}

	delete graph;
	graph = nullptr;
}

void CLInterface::viewMSTKruskal() {
	system("CLS");
	cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
	cout << "Kruskal's algorithm result: " << endl << endl;

	MST* algorithm = new MSTKruskal();
	algorithm->execute(graph);
	Graph* result = algorithm->getResult();

	cout << result->toString() << endl;

	delete algorithm;
	delete result;

	handleUserInput();
}

void CLInterface::viewMSTPrim() {
	system("CLS");
	cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
	cout << "Prims's algorithm result: " << endl << endl;

	MST* algorithm = new MSTPrim();
	algorithm->execute(graph);
	Graph* result = algorithm->getResult();

	cout << result->toString() << endl;

	delete algorithm;
	delete result;
	handleUserInput();
}