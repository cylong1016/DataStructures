/* 多项式实现 */
/* 2014-10-30 10：43 AM */

#include "Polynomial.h"
#include "iostream"
using namespace std;

Polynomial::Polynomial() {
	head = new Node(0, -1);
}

Polynomial::Polynomial(float node[][2], int num) {
	// head = new Node(0, -1);
	new (this) Polynomial();
	for (int i = 0; i < num; i++) {
		insert(node[i][0], node[i][1]);
	}
}

Polynomial::Polynomial(Polynomial& pol) {
	head = new Node(0, -1);
	Node* dest = head;
	Node* src = pol.getHead()->next;
	while (src != nullptr) {
		dest = dest->insertAfter(src->coef, src->exp);
		src = src->next;
	}
}

Node* Polynomial::getHead() {
	return head;
}

void Polynomial::insert(float coef, int exp) {
	Node* tmp = head;
	while (tmp->next && tmp->next->exp <= exp) {
		if (tmp->next->exp == exp) {
			tmp->next->coef += coef;
			return;
		}
		tmp = tmp->next;
	}
	
	tmp->insertAfter(coef, exp);
	
}

Polynomial Polynomial::operator + (Polynomial& pol) {
	Polynomial res;
	Node* nodeA = head;
	Node* nodeB = pol.getHead();
	while (nodeA->next && nodeB->next) {
		if (nodeA->next->exp > nodeB->next->exp) {
			nodeB = nodeB->next;
			res.insert(nodeB->coef, nodeB->exp);
		}
		else if (nodeA->next->exp < nodeB->next->exp) {
			nodeA = nodeA->next;
			res.insert(nodeA->coef, nodeA->exp);
		}
		else {
			nodeA = nodeA->next;
			nodeB = nodeB->next;
			float coefRes = nodeA->coef + nodeB->coef;
			if (coefRes) {
				res.insert(coefRes, nodeA->exp);
			}
		}
	}
	while (nodeA->next) {
		nodeA = nodeA->next;
		res.insert(nodeA->coef, nodeA->exp);
	}
	while (nodeB->next) {
		nodeB = nodeB->next;
		res.insert(nodeB->coef, nodeB->exp);
	}

	return res;
}

void Polynomial::print() {
	Node* n = head->next;
	if (n) {
		cout << (n->coef < 0 ? "(" : "");
		cout << n->coef;
		cout << (n->coef < 0 ? ")" : "");
		cout << "^" << n->exp;
	}
	while (n->next) {
		n = n->next;
		cout << " + ";
		cout << (n->coef < 0 ? "(" : "");
		cout << n->coef;
		cout << (n->coef < 0 ? ")" : "");
		cout << "^" << n->exp;
	}
	cout << endl;
}

Polynomial::~Polynomial() {}