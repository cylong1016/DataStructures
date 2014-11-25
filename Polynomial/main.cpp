/* 2014-10-30 1:43 PM */
#include "Polynomial.h"

int main() {
	float nodeA[][2] = { { -2, 2 }, { 3, 4 }, { -1, 1 }, { 10, 10 }, { 1, 8 }, { -3, 7 } };
	Polynomial polyA(nodeA, 6);
	polyA.print();

	float nodeB[][2] = { { -1, 2 }, { 3, 2 }, { 2, 3 }, { -1, 5 }, { 4, 7 } };
	Polynomial polyB(nodeB, 5);
	polyB.print();

	Polynomial res = polyA + polyB;
	res.print();
}