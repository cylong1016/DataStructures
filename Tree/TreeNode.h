/* 二叉树的节点 */
/* 2014-11-05 12:11 AM */
template<class T>
struct TreeNode {
	T data;
	TreeNode<T>* left, *right;
	TreeNode(T data, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	TreeNode() {
		this->left = nullptr;
		this->right = nullptr;
	}
};