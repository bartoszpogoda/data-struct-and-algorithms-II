#include "SPathDijkstra.h"
#include "MinimumHeap.h"
#include "PathNode.h"

void SPathDijkstra::execute(Graph * graph, int startVerticle) {
	PathNode* resultNodes = new PathNode[graph->getSize()];

	MinimumHeap<PathNode>* unvisitedHeap = new MinimumHeap<PathNode>();

	unvisitedHeap->add(PathNode(startVerticle, 0, -1));
	for (size_t i = 0; i < startVerticle; i++) {
		unvisitedHeap->add(PathNode(i));
	}
	for (size_t i = startVerticle+1; i < graph->getSize(); i++) {
		unvisitedHeap->add(PathNode(i));
	}

	while (!unvisitedHeap->isEmpty()) {
		PathNode node = unvisitedHeap->popRoot();
		
		Edge* adjacentEdges = graph->getAdjacentEdges(node.getVerticle());
		for (size_t i = 0; i < graph->degree(node.getVerticle()); i++) {
			int nodeToRelax = adjacentEdges[i].getEndV();
			int distance = unvisitedHeap->get(nodeToRelax).getDistance();

			if (distance > node.getDistance() + adjacentEdges[i].getWeight()) {
				PathNode newDistanceNode = PathNode(nodeToRelax, node.getDistance() + adjacentEdges[i].getWeight(), node.getVerticle());
				unvisitedHeap->update(nodeToRelax, newDistanceNode);

			}
		}

		resultNodes[node.getVerticle()] = node;
		delete[] adjacentEdges;
	}

	delete unvisitedHeap;

	delete result;
	result = new Path(startVerticle, graph->getSize(), resultNodes);
}
