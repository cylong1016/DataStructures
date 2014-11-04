#include "string"
using namespace std;

class Operator {
private:
	static string ops;
public:
	int priority;
	/* ��ʼ��operator�����ȼ� */
	Operator(char op) {
		for (unsigned int i = 0; i < ops.length(); i++) {
			if (op == ops[i]) {
				priority = i / 2; // +- ��*/�������ֱ�����ͬ�����ȼ�
			}
		}
	}
	/* �ж��Ƿ��� + - * / ( ) ����� */
	static bool isOperator(char op) {
		for (unsigned int i = 0; i < ops.length(); i++) {
			if (op == ops[i]) {
				return true;
			}
		}
		return false;
	}

	/* ����������������ȼ��Ĳ� */
	static int cmpPriority(char op1, char op2) {
		Operator oper1(op1);
		Operator oper2(op2);
		return oper1.priority - oper2.priority;
	}

	/* ���ݴ�����������������������Ľ�� */
	static double calc(double num1, double num2, char op) {
		switch (op) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			return num1 / num2;
		default:
			break;
		}
	}
};

string Operator::ops = "+-*/()"; // ��ʼ��Operator����������ַ���