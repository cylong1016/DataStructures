/* ���� */
/* 2014-10-31 12��30 PM */

#include "Node.h"
#include "iostream"
using namespace std;

template <class E>
class List {
protected:
	Node<E> *head;
public:
	/* ��ʼ���յ�ͷ�ڵ� */
	List()	 {
		head = new Node<E>();
	}
	/* �����鷽ʽ�������� */
	List(E elements[], int length) {
		new (this) List();
		Node<E>* p = head;
		for (int i = 0; i < length; i++) {
			p = p->insertAfter(elements[i]);
		}
	}
	/* ���ƹ��캯�� */
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
	/* �����������������ÿ� */
	~List() {
		makeEmpty();
	}
	/* ��������Ϊ�ձ� */
	void makeEmpty() {
		Node<E> *p;
		while (head->next) {
			p = head->next;
			head->next = p->next;
			delete p;
		}
	}
	/* ���ͷ�ڵ��ַ */
	Node<E>* getHead() {
		return head;
	}
	/* ��������ĳ��� */
	int size() {
		Node<E>* n = head->next;
		int count = 0;
		while (n) {
			n = n->next;
			count++;
		}
		return count;
	}
	/* ������i��Ԫ�صĵ�ַ */
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
	/* �ڵ�i��Ԫ�غ������x */
	bool insert(int i, E& x) {
		Node<E>* current = locate(i);
		if (!current) {
			return false; // ���벻�ɹ�
		}
		Node<E>* newNode = current->insertAfter(x);
		return true;
	}
	/* ������ĵ�i��Ԫ��ɾ����ͨ�������Ͳ���x����ɾ����Ԫ�ص�ֵ */
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
	/* ��������е�ֵ */
	void print() {
		Node<E>* p = head;
		while (p->next) {
			p = p->next;
			cout << p->element << " ";
		}
		cout << endl;
	}
};
