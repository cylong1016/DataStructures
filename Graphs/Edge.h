/* �ڽӱ�ߵĶ��� */
#pragma once
template <class DistType>
struct Edge {
	int dest;	// �ߵ���һ�����ڶ�����е�λ�� 
	DistType cost;	// ���ϵ�Ȩ
	Edge<DistType> *link;	// ��һ���ߵ���ָ��
	
	Edge(int dest, DistType cost = 1, Edge<DistType> *link = nullptr)
		:dest(dest), cost(cost), link(link) {}
};