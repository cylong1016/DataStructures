#include "Node.h"
/* 多项式定义 */
/* 2014-10-30 10：43 AM */
class Polynomial {
public:
	/* 构造函数：建立空链表 */
	Polynomial();
	/* 构造函数，通过数组创建 */
	Polynomial(float node[][2], int num);
	/* 复制构造函数 */
	Polynomial(Polynomial& pol);
	~Polynomial();
	/* 获得头节点 */
	Node* getHead();
	/* 顺序插入多项式节点 */
	void insert(float coef, int exp);
	/* 多项式加法 */
	Polynomial operator + (Polynomial& pol);
	/* 打印多项式 */
	void print();
private:
	Node* head;
};
