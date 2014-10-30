#include "Node.h"

/* 多项式节点实现 */
/* 2014-10-30 10：46 AM */

Node::Node(float coef, int exp, Node *next = nullptr) {
	this->coef = coef;
	this->exp = exp;
	this->next = next;
}

/* 向当前节点后添加一个节点，返回当前节点的下一个节点 */
Node* Node::insertAfter(float coef, int exp) {
	next = new Node(coef, exp, next);
	return next;
}