/* 中缀表达式转换成后缀表达式并计算 */
#include "string"
#include "Calculator.h"
using namespace std;

int main() {
	string infix("2.1 + 1.1 * 3.1 + (1.2 * 1.3 + 1.4) * 1.5");
	Calculator calc(infix);
	string postfix = calc.postfix();
	double res = calc.calculator();
	cout << "中缀表达式: " << infix << endl;
	cout << "后缀表达式: " << postfix << endl;
	cout << "计算结果：" << res << endl;
}