#include "Node.h"
/* ����ʽ���� */
/* 2014-10-30 10��43 AM */
class Polynomial {
public:
	Polynomial();
	Polynomial(Polynomial& pol); // ���ƹ��캯��
	~Polynomial();
	Node* getHead();
private:
	Node* head;
};
