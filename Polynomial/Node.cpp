#include "Node.h"

/* ����ʽ�ڵ�ʵ�� */
/* 2014-10-30 10��46 AM */

Node::Node(float coef, int exp, Node *next = nullptr) {
	this->coef = coef;
	this->exp = exp;
	this->next = next;
}

/* ��ǰ�ڵ�����һ���ڵ㣬���ص�ǰ�ڵ����һ���ڵ� */
Node* Node::insertAfter(float coef, int exp) {
	next = new Node(coef, exp, next);
	return next;
}