/* 节点类的定义 */
/* 2014-10-30 8：21 PM */
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
	/* 在当前节点后插入一个节点，返回当前节点的下一个节点 */
	Node<E>* insertAfter(E element) {
		next = new Node<E>(element, next);
		return next;
	}
};