#include "Node.h"
/* 多项式定义 */
/* 2014-10-30 10：43 AM */
class Polynomial {
public:
	Polynomial();
	Polynomial(Polynomial& pol); // 复制构造函数
	~Polynomial();
	Node* getHead();
private:
	Node* head;
};
