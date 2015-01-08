/* 邻接表边的定义 */
#pragma once
template <class DistType>
struct Edge {
	int dest;	// 边的另一顶点在顶点表中的位置 
	DistType cost;	// 边上的权
	Edge<DistType> *link;	// 下一条边的链指针
	
	Edge(int dest, DistType cost = 1, Edge<DistType> *link = nullptr)
		:dest(dest), cost(cost), link(link) {}
};