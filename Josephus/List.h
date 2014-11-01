/* 链表 */
/* 2014-10-31 12：30 PM */

#include "Node.h"
#include "iostream"
using namespace std;

template <class E>
class List {
protected:
	Node<E> *head;
public:
	/* 初始化空的头节点 */
	List()	 {
		head = new Node<E>();
	}
	/* 以数组方式创建链表 */
	List(E elements[], int length) {
		new (this) List();
		Node<E>* p = head;
		for (int i = 0; i < length; i++) {
			p = p->insertAfter(elements[i]);
		}
	}
	/* 复制构造函数 */
	List(List<E> &list) {
		E element;
		Node<E>* srcptr = list.getHead();
		Node<E>* destptr = head = new Node<E>();
		while (srcptr->next) {
			value = srcptr->next->element;
			destptr->next = new Node<E>(element);
			destptr = destptr->next;
			srcptr = srcptr->next;
		}
	}
	/* 析构函数，将链表置空 */
	~List() {
		makeEmpty();
	}
	/* 将链表置为空表 */
	void makeEmpty() {
		Node<E> *p;
		while (head->next) {
			p = head->next;
			head->next = p->next;
			delete p;
		}
	}
	/* 获得头节点地址 */
	Node<E>* getHead() {
		return head;
	}
	/* 计算链表的长度 */
	int size() {
		Node<E>* n = head->next;
		int count = 0;
		while (n) {
			n = n->next;
			count++;
		}
		return count;
	}
	/* 搜索第i个元素的地址 */
	Node<E>* locate(int i) {
		if (i < 0)
			return NULL;
		Node<E>* current = head;
		int k = 0;
		while (current && k < i) {
			current = current->next;
			k++;
		}
		return current;
	}
	/* 在第i个元素后面插入x */
	bool insert(int i, E& x) {
		Node<E>* current = locate(i);
		if (!current) {
			return false; // 插入不成功
		}
		Node<E>* newNode = current->insertAfter(x);
		return true;
	}
	/* 将链表的第i个元素删除，通过引用型参数x返回删除的元素的值 */
	bool remove(int i, E& x) {
		Node<E>* current = locate(i - 1);
		if (!current || !current->next) {
			return false;
		}
		Node<E>* del = current->next;
		current->next = del->next;
		x = del->element;
		delete del;
		return true;
	}
	/* 输出链表中的值 */
	void print() {
		Node<E>* p = head;
		while (p->next) {
			p = p->next;
			cout << p->element << " ";
		}
		cout << endl;
	}
};
