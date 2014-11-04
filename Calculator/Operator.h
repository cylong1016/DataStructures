#include "string"
using namespace std;

class Operator {
private:
	static string ops;
public:
	int priority;
	/* 初始化operator的优先级 */
	Operator(char op) {
		for (unsigned int i = 0; i < ops.length(); i++) {
			if (op == ops[i]) {
				priority = i / 2; // +- 、*/、（）分别有相同的优先级
			}
		}
	}
	/* 判断是否是 + - * / ( ) 运算符 */
	static bool isOperator(char op) {
		for (unsigned int i = 0; i < ops.length(); i++) {
			if (op == ops[i]) {
				return true;
			}
		}
		return false;
	}

	/* 返回两个运算符优先级的差 */
	static int cmpPriority(char op1, char op2) {
		Operator oper1(op1);
		Operator oper2(op2);
		return oper1.priority - oper2.priority;
	}

	/* 根据传的运算符计算两个操作数的结果 */
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

string Operator::ops = "+-*/()"; // 初始化Operator中运算符的字符串