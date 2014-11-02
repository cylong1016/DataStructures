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

template <class E>
/* 数组解决约瑟夫问题 */
/* n个人 */
void josephus(E elements[], int n, int m) {
	int index = 0;
	while (n > 1) {
		index = (index + m - 1) % n;
		E element = remove(elements, n, index);
		cout << "出列者： " << element << endl;
	}
	cout << "胜出者： " << elements[0] << endl;
}

template <class E>
/* 删除数组中下标为index的一个元素 */
/* n存储数组的长度 */
/* 返回删除的元素 */
E remove(E elements[], int& n, int index) {
	E element = elements[index];
	for (int i = index; i < n - 1; i++) {
		elements[i] = elements[i + 1];
	}
	// 数组长度-1
	n--;
	return element;
}

int main() {
	string names[] = { "cyl", "lsy", "lwp", "qq", "lcx" };
	int size = 5;	// 人数
	int m = 7;
	CircList<string>* clist = new CircList<string>(names, size);
	cout << "参与者： "; clist->print();
	cout << endl;
	cout << "链表解决约瑟夫问题：" << endl;
	josephus(clist, m);

	cout << endl;
	cout << "数组解决约瑟夫问题： " << endl;
	josephus(names, size, m);
}