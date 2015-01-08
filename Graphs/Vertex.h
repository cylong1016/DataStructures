/* �ڽӱ���Ķ��� */
#pragma once
#include "Edge.h"

template<class NameType, class DistType>
struct Vertex {
	NameType name;	// ��������
	Edge<DistType> *adj;	// ���߱�ͷָ��

	Vertex() {}

	Vertex(NameType name, Edge<DistType> *adj = nullptr)
		:name(name), adj(adj) {}

	void insert(Edge<DistType> *edge) { // ���������
		Edge<DistType> *temp = adj;
		while (temp->link) {
			temp = temp->link;
		}
		temp->link = edge;
	}

};