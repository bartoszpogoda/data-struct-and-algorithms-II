#include "SPathDijkstra.h"
#include "MinimumHeap.h"
#include "DistanceNode.h"

#include <iostream> //temp

Path * SPathDijkstra::execute(Graph * graph) {

	MinimumHeap<DistanceNode>* unvisitedHeap = new MinimumHeap<DistanceNode>();
	
	unvisitedHeap->add(DistanceNode(0, 0, -1));
	for (size_t i = 1; i < graph->getSize(); i++) {
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

		std::cout << "Node: " << node.getPrevious() << "->" << node.getVerticle() << " distance " << node.getDistance() << std::endl;

	}

	//heap->update(start, DistanceNode(start))


	delete unvisitedHeap;

	return nullptr;
}
