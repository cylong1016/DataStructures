/* 创建一颗二叉树，并输出前序中序后序遍历结果 */
/* 2014-11-05 1：20 AM */
#include "BinaryTree.h"
#include "stack"
#include "iostream"
using namespace std;

/* 采用广义表表示创建一颗二叉树 */
BinaryTree<char>* createBinaryTree(string gList) {
	stack<TreeNode<char> *> s;
	BinaryTree<char>* bt = nullptr;
	int k = 0; // 作为处理左右子树的标记，左为1、右为2.
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

/* 输出一个节点中的值 */
template<class T>
void visit(TreeNode<T>* p) {
	cout << p->data << " ";
}

int main() {
	string glist = "A(B(D,E(G,)),C(,F))";
	BinaryTree<char>* bt = createBinaryTree(glist);
	cout << "广义表表示： " << glist.data() << endl;
	cout << "前序遍历： "; bt->preOrder(visit);
	cout << "中序遍历： "; bt->inOrder(visit);
	cout << "后序遍历： "; bt->postOrder(visit);
}