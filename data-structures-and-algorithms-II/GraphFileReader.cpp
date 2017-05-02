#include "GraphFileReader.h"

#include "Graph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "DirectedMatrixGraph.h"
#include "IndirectedMatrixGraph.h"
#include "DirectedListGraph.h"
#include "IndirectedListGraph.h"
#include <fstream>

MatrixGraphFileData * GraphFileReader::readMatrixGraph(std::string filename, GraphType type)
{
	MatrixGraph* graph = nullptr;
	int size = 0, startVerticle = -1, endVerticle, e;

	std::ifstream file = std::ifstream(filename);

	if (file.is_open()) {

		file >> e;	
		if (file.fail()) {
			delete graph;
			file.close();
			return new MatrixGraphFileData("File read error : num of edges");
		}

		file >> size;
		if (file.fail() || size <= 0)
			return new MatrixGraphFileData("File read error : graph size");

		if (type == DIRECTED) {
			graph = new DirectedMatrixGraph(size);
		} else {
			graph = new IndirectedMatrixGraph(size);
		}

		file >> startVerticle;
		if (file.fail()) {
			delete graph;
			file.close();
			return new MatrixGraphFileData("File read error : start verticle");
		}

		file >> endVerticle;
		if (file.fail()){
			delete graph;
			file.close();
			return new MatrixGraphFileData("File read error : end verticle");
		}

		int begin, end, weight;
		for (int i = 0; i < e; i++) {
			file >> begin >> end >> weight;
			if (file.fail()) {
				delete graph;
				file.close();
				return new MatrixGraphFileData("File read error : data");
			} else
				graph->addEdge(begin, end, weight);
		}

		file.close();
		return new MatrixGraphFileData(graph, startVerticle);
	} 
	else
		return new MatrixGraphFileData("File read error : open");


}

ListGraphFileData * GraphFileReader::readListGraph(std::string filename, GraphType type) {
	ListGraph* graph = nullptr;
	int size = 0, startVerticle = -1, endVerticle, e;

	std::ifstream file = std::ifstream(filename);

	if (file.is_open()) {

		file >> e;
		if (file.fail()) {
			delete graph;
			file.close();
			return new ListGraphFileData("File read error : num of edges");
		}

		file >> size;
		if (file.fail() || size <= 0)
			return new ListGraphFileData("File read error : graph size");

		if (type == DIRECTED) {
			graph = new DirectedListGraph(size);
		} else {
			graph = new IndirectedListGraph(size);
		}

		file >> startVerticle;
		if (file.fail()) {
			delete graph;
			file.close();
			return new ListGraphFileData("File read error : start verticle");
		}

		file >> endVerticle;
		if (file.fail()) {
			delete graph;
			file.close();
			return new ListGraphFileData("File read error : end verticle");
		}

		int begin, end, weight;
		for (int i = 0; i < e; i++) {
			file >> begin >> end >> weight;
			if (file.fail()) {
				delete graph;
				file.close();
				return new ListGraphFileData("File read error : data");
			} else
				graph->addEdge(begin, end, weight);
		}

		file.close();
		return new ListGraphFileData(graph, startVerticle);
	} else
		return new ListGraphFileData("File read error : open");


}
