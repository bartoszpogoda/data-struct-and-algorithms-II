#include "SPathDijkstra.h"
#include "SearchableMinimumHeap.h"
#include "PathNode.h"


void SPathDijkstra::execute(Graph * graph, int startVerticle) {
	// create result nodes
	PathNode* resultNodes = new PathNode[graph->getSize()];							

	// init helper structures
	SearchableMinimumHeap<PathNode>* unvisitedHeap = new SearchableMinimumHeap<PathNode>(graph->getSize());				

	// init results nodes (adding in order that doesnt require any heap fixing)
	unvisitedHeap->add(PathNode(startVerticle, 0, -1));								
	for (size_t i = 0; i < startVerticle; i++) {									
		unvisitedHeap->add(PathNode(i));											
	}																				
	for (size_t i = startVerticle+1; i < graph->getSize(); i++) {					
		unvisitedHeap->add(PathNode(i));											
	}

	// main algorithm loop
	while (!unvisitedHeap->isEmpty()) {
		// pop node with shortest path						
		PathNode node = unvisitedHeap->popRoot();								
		
		// find adjacent edges and relax them
		Edge* adjacentEdges = graph->getAdjacentEdges(node.getVerticle());			
		for (size_t i = 0; i < graph->degree(node.getVerticle()); i++) {			
			int nodeToRelax = adjacentEdges[i].getEndV();
			int distance = unvisitedHeap->get(nodeToRelax).getDistance();

			// check for relaxation condition
			if (node.getDistance() != INF && distance > node.getDistance() + adjacentEdges[i].getWeight()) {
				PathNode newDistanceNode = PathNode(nodeToRelax, node.getDistance() + adjacentEdges[i].getWeight(), node.getVerticle());
				unvisitedHeap->update(nodeToRelax, newDistanceNode);				
			}																		
		}																		
		delete[] adjacentEdges;

		// add node to result
		resultNodes[node.getVerticle()] = node;
	}

	// dealocate helper structures
	delete unvisitedHeap;

	// clear previous result and create new one from path nodes
	delete result;
	result = new Path(startVerticle, graph->getSize(), resultNodes);
}
