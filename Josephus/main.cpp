/* Josephus 算法链表实现 */
/* 2014-11-1 11:40 PM */
#include "string"
#include "CircList.h"
using namespace std;

template <class E>

/* 链表解决约瑟夫问题 */
void josephus(CircList<E>* clist, int m) {
	Node<E>* head = clist->getHead();
	Node<E>* pre = head;
	Node<E>* p = pre->next;
	while (clist->size() > 1) {
		if (p == head) {	// 跳过头节点
			pre = p;
			p = p->next;
		}
		// 数 m - 1 个人
		for (int i = 0; i < m - 1; i++) {
			if (p->next == head) {
				i--;	// 跳过头节点
			}
			pre = p;
			p = p->next;

		}
		cout << "出列者： " << p->element << endl;
		pre->next = p->next;
		delete p;
		p = pre->next;
	}
	cout << "胜出者： " << head->next->element << endl;
}

int main() {
	string names[] = { "cyl", "lsy", "lwp", "qq", "lcx"};
	CircList<string>* clist = new CircList<string>(names, 5);
	clist->print();
	josephus(clist, 3);
}