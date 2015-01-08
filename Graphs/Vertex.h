/* 邻接表顶点的定义 */
#pragma once
#include "Edge.h"

template<class NameType, class DistType>
struct Vertex {
	NameType name;	// 顶点名字
	Edge<DistType> *adj;	// 出边表头指针

	Vertex() {}

	Vertex(NameType name, Edge<DistType> *adj = nullptr)
		:name(name), adj(adj) {}

	void insert(Edge<DistType> *edge) { // 插入在最后
		Edge<DistType> *temp = adj;
		while (temp->link) {
			temp = temp->link;
		}
		temp->link = edge;
	}

};