/* 循环链表的定义 */
/* 2014-11-2 12：38 AM */
#include "List.h"

template <class E>
class CircList: public List < E > {
public:
	CircList() {
		// head指向自己
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

	/* 计算循环链表的长度 */
	int size() {
		Node<E>* n = getHead();
		int count = 0;
		while (n->next != getHead()) {
			n = n->next;
			count++;
		}
		return count;
	}
	/* 搜索第i个元素的地址 */
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

	/* 输出循环链表的值 */
	void print() {
		Node<E>* p = getHead();
		while (p->next != getHead()) {
			p = p->next;
			cout << p->element << " ";
		}
		cout << endl;
	}

};