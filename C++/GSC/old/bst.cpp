#include <iostream>
using namespace std;

template <class T>
class BST {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(const T& data) :data(data), left(NULL), right(NULL) {};
	};

	Node* root;

private:
	void bstBuildTree(Node*& root, T pre[], T in[], int inStart, int inEnd);
	int search(T in[], int inStart, int inEnd, T data);
	void printPreorder(Node*& root);
	void printInorder(Node*& root);
	void printPostorder(Node*& root);

public:
	BST() :root(NULL) {};
	~BST() { cout << "~BST()" << endl; };

	void bstBuildTree(T pre[], T in[], int inStart, int inEnd) {
		bstBuildTree(root, pre, in, inStart, inEnd); };
	void printPreorder() { printPreorder(root); };
	void printInorder() { printInorder(root); };
	void printPostorder() { printPostorder(root); };
};

template <class T>
void BST<T>::bstBuildTree(Node*& root, T pre[], T in[], int inStart, int inEnd) {
	static int preIndex = 0;
	if (inStart > inEnd)
		return;

	root = new Node(pre[preIndex++]);
	if (inStart == inEnd)
		return;
	int index = search(in,inStart,inEnd,root->data);
	bstBuildTree(root->left, pre, in, inStart, index - 1);
	bstBuildTree(root->right,pre, in, index + 1, inEnd);
}

template <class T>
int BST<T>::search(T in[], int inStart, int inEnd, T data) {
	int i = 0;
	for (i = inStart; i < inEnd; i++) {
		if (in[i] == data) {
			break;
		}
	}
	return i;
}

template <class T>
void BST<T>::printPreorder(Node*& root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

template <class T>
void BST<T>::printInorder(Node*& root) {
	if (root == NULL)
		return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

template <class T>
void BST<T>::printPostorder(Node*& root) {
	if (root == NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";
}

int main_bst(int argc, char** argv) {
	int pre[] = { 5,4,2,3,6,7,8 };
	int in[] = { 2,4,3,5,7,6,8 };;
	int len = sizeof(in) / sizeof(in[0]);
	BST<int> bst;
	bst.bstBuildTree(pre, in, 0, len - 1);
	bst.printPreorder();
	cout << endl;
	bst.printInorder();
	cout << endl;
	bst.printPostorder();
	cout << endl;
	system("pause");
	return 0;
}

