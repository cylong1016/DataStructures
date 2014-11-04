/* �������Ķ��� */
/* 2014-11-05 12��14 AM */
#include "TreeNode.h"
#include "iostream"
using namespace std;

template<class T>
class BinaryTree {
private:
	TreeNode<T>* root;
public:

	/* ����һ���и��ڵ���� */
	BinaryTree(TreeNode<T>* root = nullptr) {
		this->root = root;
	}

	/* ���ظ��ڵ� */
	TreeNode<T>* getRoot() {
		return root;
	}

	/* ǰ����� */
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

	/* ������� */
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

	/* ������� */
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
