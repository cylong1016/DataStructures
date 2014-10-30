/* 多项式节点定义 */
/* 2014-10-30 10：32 AM */
struct Node {
	float coef;		// 系数
	int exp;		// 指数
	Node* next;		// 下一个节点
	Node(float coef, int exp, Node *next = nullptr);
	/* 在当前节点后插入一个节点，返回当前节点的下一个节点 */
	Node* insertAfter(float coef, int exp);
};