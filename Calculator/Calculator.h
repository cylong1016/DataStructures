/* 将表达式中缀转化为后缀，并计算出表达式的值 */
/* 运算符只包含 +、-、*、/、(、)、 */
/* 2014-11-03 */
#include "stack"
#include "string"
#include "Operator.h"
#include "iostream"
#include <sstream>
using namespace std;

class Calculator {

private:
	string infix;
public:

	/* 初始化中缀表达式 */
	Calculator(string infix) {
		this->infix = infix;
	}

	/* 中缀转化成后缀表达式 */
	string postfix() {
		string postfix; // 转化后的后缀表达式
		stack<char> s; // 存放运算符的栈
		for (unsigned int i = 0; i < infix.length(); i++) {
			if (infix[i] == ' ') {
				continue; // 跳过空格
			}
			if (Operator::isOperator(infix[i])) { // 如果是运算符
				postfix.append(" "); // 遇到运算符之前的是数字，保证两个数组之间有空格区分
				if (s.empty()) {
					s.push(infix[i]);
				}
				else if (infix[i] == ')') {
					while (s.top() != '(') {
						postfix.append(&s.top(), 1);
						postfix.append(" ");
						s.pop();
					}
					s.pop(); // 弹出 (
				}
				else {
					while (!s.empty() && (s.top() != '(')
						// 直到发现优先级更低的元素
						&& Operator::cmpPriority(s.top(), infix[i]) >= 0) {
						postfix.append(&s.top(), 1);
						postfix.append(" ");
						s.pop();
					}
					s.push(infix[i]);
				}
			}
			else { // 如果不是运算符就直接加入到postfix中
				postfix.append(&infix[i], 1);
			}
		}
		// 将栈中的运算符全部输出到postfix中
		while (!s.empty()) {
			postfix.append(" ");
			postfix.append(&s.top(), 1);
			s.pop();
		}
		return postfix;
	}

	/* 后缀表示计算表达式的值 */
	double calculator() {
		double res = 0.0; // 计算结果
		string s_postfix = postfix(); // 后缀表达式
		stack<double> s; // 存放数字的栈
		string s_num; // 存放数字字符串
		for (unsigned int i = 0; i < s_postfix.length(); i++) {
			if (s_postfix[i] == ' ' || Operator::isOperator(s_postfix[i])) { 
				// 数字以空格或者运算符结束
				if (!s_num.empty()) {
					s.push(strToNum(s_num));
					s_num.clear();
				}
				if (Operator::isOperator(s_postfix[i])) {
					double num2 = s.top();
					s.pop();
					double num1 = s.top();
					s.pop();
					res = Operator::calc(num1, num2, s_postfix[i]);
					s.push(res);
				}
			}
			else {
				s_num.append(&s_postfix[i], 1);
			}
		}
		return res;
	}

	/* 将字符串转化成数字 */
	double strToNum(string s) {
		double num;
		stringstream ss(s);
		ss >> num;
		return num;
	}

	string getInfix() {
		return infix;
	}

};