#include "GraphGenerator.h"


Edge GraphGenerator::randomEdge(int verticleRange, int weightRange) {
	return Edge(rand() % verticleRange, rand() % verticleRange, weightRange == 0 ? 0 : rand() % weightRange);
}

void GraphGenerator::fillGraph(Graph * graph, int weightRange, double edgeDensity) {
	int V = graph->getSize();

	if (edgeDensity < 0.50) {
		// add edges to empty graph
		int edgesToGenerate = V*V*edgeDensity;

		// cycle (with weights in top 20% range)
		for (size_t i = 0; i < V; i++) {
			graph->addEdge(Edge(i, (i + 1) % V, weightRange*0.8 + rand() % (int)(0.2*weightRange)));
			edgesToGenerate--;
		}

		// add regular edges
		while (edgesToGenerate > 0) {
			Edge edge;
			do {
				edge = randomEdge(V, weightRange);
			} while (graph->hasEdge(edge));

			graph->addEdge(edge);
			edgesToGenerate--;
		}
	} else {
		// remove edges from full graph
		int edgesToRemove = V*V*(1-edgeDensity);
		
		// fill graph (without cycle)
		for (size_t i = 0; i < V; i++) {
			for (size_t j = 0; j < V; j++) {
				if ((i + 1) % V != j) // omit the cycle
					graph->addEdge(Edge(i, j, rand() % weightRange));
			}
		}
		
		// remove regular edges
		while (edgesToRemove > 0) {
			Edge edge;
			do {
				edge = randomEdge(V, 0);
			} while (!graph->hasEdge(edge));

			graph->remEdge(edge);
			edgesToRemove--;
		}

		// add cycle (with weights in top 20% range)
		for (size_t i = 0; i < V; i++) {
			graph->addEdge(Edge(i, (i + 1) % V, weightRange*0.8 + rand() % (int)(0.2*weightRange)));
		}
	}
}
void GraphGenerator::fillGraphUndirected(Graph * graph, int weightRange, double edgeDensity) {
	int V = graph->getSize();

	if (edgeDensity < 0.50) {
		// add edges to empty graph
		int edgesToGenerate = (V*(V-1)/2 + V)*edgeDensity;

		// insert 0->1->...->n-1 path (with weights in top 20% range)
		for (size_t i = 0; i < V-1 ; i++) {
			graph->addEdge(Edge(i, i + 1, weightRange*0.8 + rand() % (int)(0.2*weightRange)));
			edgesToGenerate--;
		}

		// add regular edges
		while (edgesToGenerate > 0) {
			Edge edge;
			do {
				edge = randomEdge(V, weightRange);
			} while (graph->hasEdge(edge));

			graph->addEdge(edge);
			edgesToGenerate--;
		}
	} else {
		// remove edges from full graph
		int edgesToRemove = (V*(V - 1) / 2 + V)*(1 - edgeDensity);

		// fill graph (without 0->1->...->n-1 path)
		for (size_t i = 0; i < V; i++) {
			for (size_t j = i; j < V; j++) {
				if (i + 1 != j) // omit the skeleton path
					graph->addEdge(Edge(i, j, rand() % weightRange));
			}
		}

		// remove regular edges
		while (edgesToRemove > 0) {
			Edge edge;
			do {
				edge = randomEdge(V, 0);
			} while (!graph->hasEdge(edge));

			graph->remEdge(edge);
			edgesToRemove--;
		}

		// add 0->1->...->n-1 path (with weights in top 20% range)
		for (size_t i = 0; i < V - 1; i++) {
			graph->addEdge(Edge(i, i + 1, weightRange*0.8 + rand() % (int)(0.2*weightRange)));
		}
	}
}