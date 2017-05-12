#include "SPathDijkstra.h"
#include "SearchableMinimumHeap.h"
#include "PathNode.h"

//dbg
#include <iostream>

/* 
	O(n + n*(log n) + e*(log n)) = O((n+e)logn)
*/
void SPathDijkstra::execute(Graph * graph, int startVerticle) {
	PathNode* resultNodes = new PathNode[graph->getSize()];							// O(1)

	SearchableMinimumHeap<PathNode>* unvisitedHeap = new SearchableMinimumHeap<PathNode>(graph->getSize());				// O(1)

	unvisitedHeap->add(PathNode(startVerticle, 0, -1));								// add is O(1) operation cause we're adding in order that doesnt require any fixing	
	for (size_t i = 0; i < startVerticle; i++) {									
		unvisitedHeap->add(PathNode(i));											
	}																				
	for (size_t i = startVerticle+1; i < graph->getSize(); i++) {					// adding n elements - O(n);
		unvisitedHeap->add(PathNode(i));											
	}

	//dbg
	std::cout << unvisitedHeap->toString() << std::endl;
	while (!unvisitedHeap->isEmpty()) {												// [ loop executes n- times
		PathNode node = unvisitedHeap->popRoot();									// O(logn)
		
		Edge* adjacentEdges = graph->getAdjacentEdges(node.getVerticle());			// 
		for (size_t i = 0; i < graph->degree(node.getVerticle()); i++) {			//		[ will execute e-times in general	(sum of degrees)
			int nodeToRelax = adjacentEdges[i].getEndV();
			int distance = unvisitedHeap->get(nodeToRelax).getDistance();

			if (node.getDistance() != INF && distance > node.getDistance() + adjacentEdges[i].getWeight()) {
				PathNode newDistanceNode = PathNode(nodeToRelax, node.getDistance() + adjacentEdges[i].getWeight(), node.getVerticle());
				unvisitedHeap->update(nodeToRelax, newDistanceNode);				//			O(logn)
			}																		//		]	find inside of update() may be O(n) !!!!!!!!1
		}																			// ]

		//dbg
		std::cout << unvisitedHeap->toString() << std::endl;

		resultNodes[node.getVerticle()] = node;
		delete[] adjacentEdges;
	}

	delete unvisitedHeap;

	delete result;
	result = new Path(startVerticle, graph->getSize(), resultNodes);
}
