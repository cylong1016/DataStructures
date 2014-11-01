/* Josephus �㷨����ʵ�� */
/* 2014-11-1 11:40 PM */
#include "string"
#include "CircList.h"
using namespace std;

template <class E>

/* ������Լɪ������ */
void josephus(CircList<E>* clist, int m) {
	Node<E>* head = clist->getHead();
	Node<E>* pre = head;
	Node<E>* p = pre->next;
	while (clist->size() > 1) {
		if (p == head) {	// ����ͷ�ڵ�
			pre = p;
			p = p->next;
		}
		// �� m - 1 ����
		for (int i = 0; i < m - 1; i++) {
			if (p->next == head) {
				i--;	// ����ͷ�ڵ�
			}
			pre = p;
			p = p->next;

		}
		cout << "�����ߣ� " << p->element << endl;
		pre->next = p->next;
		delete p;
		p = pre->next;
	}
	cout << "ʤ���ߣ� " << head->next->element << endl;
}

int main() {
	string names[] = { "cyl", "lsy", "lwp", "qq", "lcx"};
	CircList<string>* clist = new CircList<string>(names, 5);
	clist->print();
	josephus(clist, 3);
}