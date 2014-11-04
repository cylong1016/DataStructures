/* �����ʽ��׺ת��Ϊ��׺������������ʽ��ֵ */
/* �����ֻ���� +��-��*��/��(��)�� */
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

	/* ��ʼ����׺���ʽ */
	Calculator(string infix) {
		this->infix = infix;
	}

	/* ��׺ת���ɺ�׺���ʽ */
	string postfix() {
		string postfix; // ת����ĺ�׺���ʽ
		stack<char> s; // ����������ջ
		for (unsigned int i = 0; i < infix.length(); i++) {
			if (infix[i] == ' ') {
				continue; // �����ո�
			}
			if (Operator::isOperator(infix[i])) { // ����������
				postfix.append(" "); // ���������֮ǰ�������֣���֤��������֮���пո�����
				if (s.empty()) {
					s.push(infix[i]);
				}
				else if (infix[i] == ')') {
					while (s.top() != '(') {
						postfix.append(&s.top(), 1);
						postfix.append(" ");
						s.pop();
					}
					s.pop(); // ���� (
				}
				else {
					while (!s.empty() && (s.top() != '(')
						// ֱ���������ȼ����͵�Ԫ��
						&& Operator::cmpPriority(s.top(), infix[i]) >= 0) {
						postfix.append(&s.top(), 1);
						postfix.append(" ");
						s.pop();
					}
					s.push(infix[i]);
				}
			}
			else { // ��������������ֱ�Ӽ��뵽postfix��
				postfix.append(&infix[i], 1);
			}
		}
		// ��ջ�е������ȫ�������postfix��
		while (!s.empty()) {
			postfix.append(" ");
			postfix.append(&s.top(), 1);
			s.pop();
		}
		return postfix;
	}

	/* ��׺��ʾ������ʽ��ֵ */
	double calculator() {
		double res = 0.0; // ������
		string s_postfix = postfix(); // ��׺���ʽ
		stack<double> s; // ������ֵ�ջ
		string s_num; // ��������ַ���
		for (unsigned int i = 0; i < s_postfix.length(); i++) {
			if (s_postfix[i] == ' ' || Operator::isOperator(s_postfix[i])) { 
				// �����Կո�������������
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

	/* ���ַ���ת�������� */
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