/* ����ʽ�ڵ㶨�� */
/* 2014-10-30 10��32 AM */
struct Node {
	float coef;		// ϵ��
	int exp;		// ָ��
	Node* next;		// ��һ���ڵ�
	Node(float coef, int exp, Node *next = nullptr);
	/* �ڵ�ǰ�ڵ�����һ���ڵ㣬���ص�ǰ�ڵ����һ���ڵ� */
	Node* insertAfter(float coef, int exp);
};