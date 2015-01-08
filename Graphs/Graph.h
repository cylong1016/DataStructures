/* 图的定义 */
#pragma once
#include "Edge.h"
#include "Vertex.h"

template<class NameType, class DistType>
class Graph {

private:
	const static int defaultSize = 20;
	Vertex<NameType, DistType> *nodeTable;	// 顶点表
	int numVertices;	// 当前顶点个数
	int maxNumVertices;	// 最大顶点个数
	int numEdges;	// 当前边数
	int getVertexpos(const NameType &name) {
		for (int i = 0; i < numVertices; i++)
			if (nodeTable[i].name == name)
				return i;
		return -1;
	}

public:
	Graph(NameType name[], int numVertices, NameType edges[][2], int numEdges, int size = 20)
		:numVertices(numVertices), maxNumVertices(size), numEdges(numEdges) {
		nodeTable = new Vertex<NameType, DistType>[defaultSize];
		for (int i = 0; i < numVertices; i++) {
			// Vertex<NameType, DistType> vertex(name[i]);
			insertVertex(name[i]);
		}

		for (int i = 0; i < numEdges; i++) {
			int v1 = getVertexpos(edges[i][0]);
			int v2 = getVertexpos(edges[i][1]);
			insertEdge(v1, v2, 1);
		}

	}

	int Empty() const {
		return numVertices == 0;
	}

	int Full() const {
		return numVertices == maxNumVertices;
	}

	int numberOfVertices() {
		return numVertices;
	}

	int numberOfEdges() {
		return numEdges;
	}

	Vertex<NameType, DistType>& getVertex(const int i) {
		return i >= 0 && i < numVertices ? nodeTable[i] : nullptr;
	}

	void insertVertex(const NameType &name) {
		Vertex<NameType, DistType> vertex(name);
		nodeTable[numVertices++] = vertex;
	}

	void removeVertex(int v) {

	}

	void insertEdge(int v1, int v2, DistType weight) {
		Edge<DistType> *edge = new Edge<DistType>(v2);
		nodeTable[v1].insert(edge);
	}

	void removeEdge(int v1, int v2) {

	}

	DistType getweight(int v1, int v2) {

	}

	int getFristNeighbor(int v) {

	}

	int getNextNeighbor(int v1, int v2) {

	}

};