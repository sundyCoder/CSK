#include <iostream>
#include <vector>

using namespace std;

namespace bitree {
	/*
	* Definition for a binary tree node.
	*/
	template <typename Dtype>
	struct TreeNode {
		Dtype val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(Dtype x) : val(x), left(NULL), right(NULL) {}
	};


	template <typename Dtype>
	class BItree {
	public:
		BItree() :root(NULL) {}
		struct TreeNode* newNode(Dtype e);

		vector<int> preorderTraversalRe(TreeNode* root);
		vector<int> preorderTraversalIt(TreeNode* root);
	};

	template <typename Dtype>
	struct TreeNode* BItree<Dtype>::newNode(Dtype e) {
		struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
		node->val= e;
		node->left = NULL;
		node->right = NULL;

		return(node);
	}

	//1 preorder
	// 1.1 solution using recursive
	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::preorderTraversalRe(TreeNode* root) {
		if (root == NULL) {
			return vector<Dtype>();
		}

		vector<Dtype> vecTree;
		vecTree.push_back(root->val);
		preorderTraversalRe(root->left);
		preorderTraversalRe(root->right);
	}

	// 1.2 solution using stack 
	template <typename Dtype>
	vector<int> BItree<Dtype>::preorderTraversalIt(TreeNode* root) {

	}
}