/* 2014-09-17 */
/* 找出从自然数 1, 2, …, n 中任取r个数的所有组合, 编一个递归算法. */
#include<iostream>
#define R 3	// 取r个数
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;


void printArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void combine(int numList[], int numListLen, int numIndex, int tempList[], int tempIndex, int r) {
	if (r == 0) {
		printArray(tempList, R);
	}
	else if (r == (numListLen - numIndex)) {
		for (int i = R - r; i < R; i++, numIndex++) {
			tempList[i] = numList[numIndex];
		}
		printArray(tempList, R);
	}
	else {
		tempList[tempIndex++] = numList[numIndex++];
		combine(numList, numListLen, numIndex, tempList, tempIndex, r - 1);
		combine(numList, numListLen, numIndex, tempList, --tempIndex, r);
	}

}

void combine(int numList[], int numListLen, int r) {
	int* tempList = new int[r];
	combine(numList, numListLen, 0, tempList, 0, r);
}

int main() {
	int numList[] = { 1, 2, 3, 4, 5, 6 };
	combine(numList, 6, R);
}