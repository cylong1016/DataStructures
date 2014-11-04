/* ����һ�Ŷ������������ǰ��������������� */
/* 2014-11-05 1��20 AM */
#include "BinaryTree.h"
#include "stack"
#include "iostream"
using namespace std;

/* ���ù�����ʾ����һ�Ŷ����� */
BinaryTree<char>* createBinaryTree(string gList) {
	stack<TreeNode<char> *> s;
	BinaryTree<char>* bt = nullptr;
	int k = 0; // ��Ϊ�������������ı�ǣ���Ϊ1����Ϊ2.
	TreeNode<char> *sub, *far;
	for (unsigned int i = 0; i < gList.length(); i++) {
		char ch = gList.at(i);
		switch (ch) {
		case '(':
			s.push(sub);
			k = 1;
			break;
		case ',':
			k = 2;
			break;
		case ')':
			//far = s.top();
			s.pop();
			break;
		default:
			sub = new TreeNode<char>(ch);
			if (!bt) {
				bt = new BinaryTree<char>(sub);
			}
			else {
				far = s.top();
				if (k == 1) {
					far->left = sub;
				}
				else {
					far->right = sub;
				}
			}
			break;
		}
	}

	return bt;
}

/* ���һ���ڵ��е�ֵ */
template<class T>
void visit(TreeNode<T>* p) {
	cout << p->data << " ";
}

int main() {
	string glist = "A(B(D,E(G,)),C(,F))";
	BinaryTree<char>* bt = createBinaryTree(glist);
	cout << "������ʾ�� " << glist.data() << endl;
	cout << "ǰ������� "; bt->preOrder(visit);
	cout << "��������� "; bt->inOrder(visit);
	cout << "��������� "; bt->postOrder(visit);
}