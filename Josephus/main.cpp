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

template <class E>
/* ������Լɪ������ */
/* n���� */
void josephus(E elements[], int n, int m) {
	int index = 0;
	while (n > 1) {
		index = (index + m - 1) % n;
		E element = remove(elements, n, index);
		cout << "�����ߣ� " << element << endl;
	}
	cout << "ʤ���ߣ� " << elements[0] << endl;
}

template <class E>
/* ɾ���������±�Ϊindex��һ��Ԫ�� */
/* n�洢����ĳ��� */
/* ����ɾ����Ԫ�� */
E remove(E elements[], int& n, int index) {
	E element = elements[index];
	for (int i = index; i < n - 1; i++) {
		elements[i] = elements[i + 1];
	}
	// ���鳤��-1
	n--;
	return element;
}

int main() {
	string names[] = { "cyl", "lsy", "lwp", "qq", "lcx" };
	int size = 5;	// ����
	int m = 7;
	CircList<string>* clist = new CircList<string>(names, size);
	cout << "�����ߣ� "; clist->print();
	cout << endl;
	cout << "������Լɪ�����⣺" << endl;
	josephus(clist, m);

	cout << endl;
	cout << "������Լɪ�����⣺ " << endl;
	josephus(names, size, m);
}