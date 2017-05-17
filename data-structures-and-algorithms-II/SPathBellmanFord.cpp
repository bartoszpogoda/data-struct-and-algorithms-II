#include "SPathBellmanFord.h"

void SPathBellmanFord::execute(Graph * graph, int startVerticle) {
	// init algorithm
	negativeCycleFlag = false;

	// create result nodes
	PathNode* resultNodes = new PathNode[graph->getSize()];	

	// init results nodes
	for (size_t i = 0; i < startVerticle; i++)
		resultNodes[i] = PathNode(i);

	resultNodes[startVerticle] = PathNode(startVerticle, 0, -1);

	for (size_t i = startVerticle + 1; i < graph->getSize(); i++)
		resultNodes[i] = PathNode(i);

	// main algorithm loop - relax each edge V - 1 times
	for (size_t i = 0; i < graph->getSize() - 1; i++) {
		Edge* edges = graph->getAllEdges();
		
		for (size_t j = 0; j < graph->getEdgeCount(); j++) {
			int start = edges[j].getStartV();
			int end = edges[j].getEndV();
			int distance = edges[j].getWeight();

			// check for relaxation condition
			if (resultNodes[start].getDistance() != INF && resultNodes[end].getDistance() > resultNodes[start].getDistance() + distance) {
				resultNodes[end] = PathNode(end, resultNodes[start].getDistance() + distance, start);
			}
		}

		delete[] edges;
	};

	// check for negative cycles
	Edge* edges = graph->getAllEdges();

	for (size_t i = 0; i < graph->getEdgeCount() && !negativeCycleFlag; i++) {
		int start = edges[i].getStartV();
		int end = edges[i].getEndV();
		int distance = edges[i].getWeight();

		// if needs relaxation then that's negative cycle
		if (resultNodes[start].getDistance() != INF && resultNodes[end].getDistance() > resultNodes[start].getDistance() + distance) {
			negativeCycleFlag = true;
		}
	}

	delete[] edges;


	// clear previous result and create new one from path nodes
	delete result;
	result = new Path(startVerticle, graph->getSize(), resultNodes);
}
