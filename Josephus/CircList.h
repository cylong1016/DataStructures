/* ѭ������Ķ��� */
/* 2014-11-2 12��38 AM */
#include "List.h"

template <class E>
class CircList: public List < E > {
public:
	CircList() {
		// headָ���Լ�
		Node<E>* head = getHead();
		head->next = head;
	}

	CircList(E elements[], int length) {
		new (this) CircList();
		Node<E>* p = getHead();
		for (int i = 0; i < length; i++) {
			p = p->insertAfter(elements[i]);
		}
	}

	/* ����ѭ������ĳ��� */
	int size() {
		Node<E>* n = getHead();
		int count = 0;
		while (n->next != getHead()) {
			n = n->next;
			count++;
		}
		return count;
	}
	/* ������i��Ԫ�صĵ�ַ */
	Node<E>* locate(int i) {
		if (i < 0)
			return NULL;
		Node<E>* current = getHead();
		int k = 0;
		while (current && k < i) {
			if (current == getHead()) {
				continue;
			}
			current = current->next;
			k++;
		}
		return current;
	}

	/* ���ѭ�������ֵ */
	void print() {
		Node<E>* p = getHead();
		while (p->next != getHead()) {
			p = p->next;
			cout << p->element << " ";
		}
		cout << endl;
	}

};