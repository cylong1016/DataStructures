/* �ڵ���Ķ��� */
/* 2014-10-30 8��21 PM */
template <class E>
class Node {
public:
	E element;
	Node<E>* next;
	Node(Node<E> *next = nullptr) {
		this->next = next;
	}
	Node(E& element, Node<E> *next = nullptr) {
		this->element = element;
		this->next = next;
	}
	/* �ڵ�ǰ�ڵ�����һ���ڵ㣬���ص�ǰ�ڵ����һ���ڵ� */
	Node<E>* insertAfter(E element) {
		next = new Node<E>(element, next);
		return next;
	}
};