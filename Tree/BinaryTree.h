/* 二叉树的定义 */
/* 2014-11-05 12：14 AM */
#include "TreeNode.h"
#include "iostream"
using namespace std;

template<class T>
class BinaryTree {
private:
	TreeNode<T>* root;
public:

	/* 创建一颗有根节点的树 */
	BinaryTree(TreeNode<T>* root = nullptr) {
		this->root = root;
	}

	/* 返回根节点 */
	TreeNode<T>* getRoot() {
		return root;
	}

	/* 前序遍历 */
	void preOrder(void(*visit)(TreeNode<T>* p)) {
		preOrder(visit, root);
		cout << endl;
	}

	void preOrder(void(*visit)(TreeNode<T>* p), TreeNode<T>* subTree) {
		if (subTree) {
			visit(subTree);
			preOrder(visit, subTree->left);
			preOrder(visit, subTree->right);
		}
	}

	/* 中序遍历 */
	void inOrder(void(*visit)(TreeNode<T>* p)) {
		inOrder(visit, root);
		cout << endl;
	}

	void inOrder(void(*visit)(TreeNode<T>* p), TreeNode<T>* subTree) {
		if (subTree) {
			inOrder(visit, subTree->left);
			visit(subTree);
			inOrder(visit, subTree->right);
		}
	}

	/* 后序遍历 */
	void postOrder(void(*visit)(TreeNode<T>* p)) {
		postOrder(visit, root);
		cout << endl;
	}

	void postOrder(void(*visit)(TreeNode<T>* p), TreeNode<T>* subTree) {
		if (subTree) {
			postOrder(visit, subTree->left);
			postOrder(visit, subTree->right);
			visit(subTree);
		}
	}

};
