/* ��׺���ʽת���ɺ�׺���ʽ������ */
#include "string"
#include "Calculator.h"
using namespace std;

int main() {
	string infix("2.1 + 1.1 * 3.1 + (1.2 * 1.3 + 1.4) * 1.5");
	Calculator calc(infix);
	string postfix = calc.postfix();
	double res = calc.calculator();
	cout << "��׺���ʽ: " << infix << endl;
	cout << "��׺���ʽ: " << postfix << endl;
	cout << "��������" << res << endl;
}