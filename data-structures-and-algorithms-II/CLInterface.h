#pragma 
#include "GraphFileReader.h"
#include "Graph.h"

#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static enum GraphRep { MATRIX, LIST } graphRep;
	static enum GraphType { DIR, UNDIR };
	static GraphFileReader* graphFileReader;
	static Graph* graph;

	CLInterface() {};
public:

	static void enter();
	static int handleUserInput();

	static bool viewInputFilename();
	static void viewMainMenu();

	static void viewMSTMenu();
	static void viewSPathMenu();

	static void viewPrintedGraph();
	static void viewGraphRepresentationPick(GraphType type);

	static void viewMSTKruskal();
	static void viewMSTPrim();
	static void viewSPathDijkstra();
	static void viewSPathBellmanFord();

};