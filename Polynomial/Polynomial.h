#include "Node.h"
/* ����ʽ���� */
/* 2014-10-30 10��43 AM */
class Polynomial {
public:
	/* ���캯�������������� */
	Polynomial();
	/* ���캯����ͨ�����鴴�� */
	Polynomial(float node[][2], int num);
	/* ���ƹ��캯�� */
	Polynomial(Polynomial& pol);
	~Polynomial();
	/* ���ͷ�ڵ� */
	Node* getHead();
	/* ˳��������ʽ�ڵ� */
	void insert(float coef, int exp);
	/* ����ʽ�ӷ� */
	Polynomial operator + (Polynomial& pol);
	/* ��ӡ����ʽ */
	void print();
private:
	Node* head;
};
