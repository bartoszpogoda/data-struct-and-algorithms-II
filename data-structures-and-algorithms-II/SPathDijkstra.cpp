#include "SPathDijkstra.h"
#include "MinimumHeap.h"
#include "DistanceNode.h"

void SPathDijkstra::execute(Graph * graph, int startVerticle) {
	delete result;
	this->startVerticle = startVerticle;
	resultSize = graph->getSize();
	result = new DistanceNode[resultSize];

	MinimumHeap<DistanceNode>* unvisitedHeap = new MinimumHeap<DistanceNode>();

	unvisitedHeap->add(DistanceNode(startVerticle, 0, -1));
	for (size_t i = 0; i < startVerticle; i++) {
		unvisitedHeap->add(DistanceNode(i));
	}
	for (size_t i = startVerticle+1; i < graph->getSize(); i++) {
		unvisitedHeap->add(DistanceNode(i));
	}

	while (!unvisitedHeap->isEmpty()) {
		DistanceNode node = unvisitedHeap->popRoot();
		
		Edge* adjacentEdges = graph->getAdjacentEdges(node.getVerticle());
		for (size_t i = 0; i < graph->degree(node.getVerticle()); i++) {
			int nodeToRelax = adjacentEdges[i].getEndV();
			int distance = unvisitedHeap->get(nodeToRelax).getDistance();

			if (distance > node.getDistance() + adjacentEdges[i].getWeight()) {
				DistanceNode newDistanceNode = DistanceNode(nodeToRelax, node.getDistance() + adjacentEdges[i].getWeight(), node.getVerticle());
				unvisitedHeap->update(nodeToRelax, newDistanceNode);

			}
		}

		result[node.getVerticle()] = node;
		delete[] adjacentEdges;
	}

	delete unvisitedHeap;
}
