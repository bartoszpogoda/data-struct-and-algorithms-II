#include "SPathDijkstra.h"
#include "MinimumHeap.h"
#include "PathNode.h"

/* 
	Currently it is O(n^2 + n*(log n) + e*(log n)) = O(n^2), but the init of Heap will be reconstructed so the algorithm
	will be of O((n+e)logn) time complexity
*/
void SPathDijkstra::execute(Graph * graph, int startVerticle) {
	PathNode* resultNodes = new PathNode[graph->getSize()];							// O(1)

	MinimumHeap<PathNode>* unvisitedHeap = new MinimumHeap<PathNode>();				// O(1)

	unvisitedHeap->add(PathNode(startVerticle, 0, -1));								// add is O(n) operation in the worse case	
	for (size_t i = 0; i < startVerticle; i++) {									// since it realocates memory on each addition
		unvisitedHeap->add(PathNode(i));											// and copies elements 
	}																				
	for (size_t i = startVerticle+1; i < graph->getSize(); i++) {					// adding n elements - O(n*n);
		unvisitedHeap->add(PathNode(i));											
	}

	while (!unvisitedHeap->isEmpty()) {												// [ loop executes n- times
		PathNode node = unvisitedHeap->popRoot();									// O(logn)
		
		Edge* adjacentEdges = graph->getAdjacentEdges(node.getVerticle());
		for (size_t i = 0; i < graph->degree(node.getVerticle()); i++) {			//		[ will execute e-times in general	(sum of degrees)
			int nodeToRelax = adjacentEdges[i].getEndV();
			int distance = unvisitedHeap->get(nodeToRelax).getDistance();

			if (node.getDistance() != INF && distance > node.getDistance() + adjacentEdges[i].getWeight()) {
				PathNode newDistanceNode = PathNode(nodeToRelax, node.getDistance() + adjacentEdges[i].getWeight(), node.getVerticle());
				unvisitedHeap->update(nodeToRelax, newDistanceNode);				//			O(logn)
			}																		//		]
		}																			// ]

		resultNodes[node.getVerticle()] = node;
		delete[] adjacentEdges;
	}

	delete unvisitedHeap;

	delete result;
	result = new Path(startVerticle, graph->getSize(), resultNodes);
}
