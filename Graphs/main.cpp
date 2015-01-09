/*2015-01-07*/
/* 判别一个有向图中是否有环路，并把所有环路打印出来 */
#include<iostream>
#include<vector>
using namespace std;
#define MAX_NUM_VERTEX 9

vector<int> vertices;	// 保存环路的定点
void findCycle(int matrix[][MAX_NUM_VERTEX], int firstVertex, int tempVertex) {
	vector<int>::iterator itr;
	for (itr = vertices.begin(); itr != vertices.end(); itr++) {	// 顶点是否被走过
		if ((*itr) == (tempVertex + 1)) {
			return;
		}
	}
	vertices.push_back(tempVertex + 1);
	if (firstVertex == tempVertex) {
		cout << (firstVertex + 1) << " ";
		vector<int>::iterator itr;
		for (itr = vertices.begin(); itr != vertices.end(); itr++) {
			cout << *itr << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < MAX_NUM_VERTEX; i++) {
		if (matrix[tempVertex][i] == 1) {
			tempVertex = i;
			findCycle(matrix, firstVertex, tempVertex);
		}
	}
}

int main(int argc, char* argv[]) {
	int matrix[MAX_NUM_VERTEX][MAX_NUM_VERTEX] = {
			{ 0, 1, 1, 0, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 0, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 1, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 1, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 1, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 0, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 0, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 0, 1, 1, 0, 0, 0 },
			{ 1, 0, 1, 0, 1, 1, 0, 0, 0 },
	};

	for (int i = 0; i < MAX_NUM_VERTEX; i++) {
		int firstVertex = i;
		for (int j = 0; j < MAX_NUM_VERTEX; j++) {
			vertices.clear();
			if (matrix[i][j] == 1) {
				int tempVertex = j;
				findCycle(matrix, firstVertex, tempVertex);
			}
		}
	}
}