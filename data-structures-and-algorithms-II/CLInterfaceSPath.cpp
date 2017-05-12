#include "CLInterface.h"
#include "SPathDijkstra.h"
#include "SPathBellmanFord.h"

#include <conio.h>
using namespace std;

void CLInterface::viewSPathMenu() {
	int selected = 0, max = 4, selectedDelta = 0;

	viewGraphRepresentationPick(GraphType::DIR);

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
			cout << "Problem: Shortest Path" << endl;
			cout << "Representation: " << (graphRep == GraphRep::LIST ? "Adjacency Lists" : "Adjacency Matrix") << endl;
			cout << "First verticle: " << graphFileReader->getFirstVerticle() << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Change graph representation" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Print graph" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Execute Dijkstra's algorithm" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Execute BellmanFord's algorithm" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Exit" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			viewGraphRepresentationPick(GraphType::DIR);
		} else if (selected == 1) {
			viewPrintedGraph();
		} else if (selected == 2) {
			viewSPathDijkstra();
		} else if (selected == 3) {
			viewSPathBellmanFord();
		}
	}

	delete graph;
	graph = nullptr;
}

void CLInterface::viewSPathDijkstra() {
	system("CLS");
	cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
	cout << "Dijkstra's algorithm result: " << endl << endl;

	SPath* algorithm = new SPathDijkstra();
	algorithm->execute(graph, graphFileReader->getFirstVerticle());
	Path* result = algorithm->getResult();

	cout << result->toString() << endl;

	delete algorithm;
	delete result;

	handleUserInput();
}

void CLInterface::viewSPathBellmanFord() {
	system("CLS");
	cout << " ++ MST and Shortest Path algorithms demo ++ " << endl << endl;
	cout << "BellmanFord's algorithm result: " << endl << endl;

	SPath* algorithm = new SPathBellmanFord();
	algorithm->execute(graph, graphFileReader->getFirstVerticle());
	Path* result = algorithm->getResult();

	cout << result->toString() << endl;

	delete algorithm;
	delete result;

	handleUserInput();
}