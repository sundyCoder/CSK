#include <iostream>
#include <vector>

using namespace std;

namespace bitree {
	template <typename Dtype>
	class BItree {
	/*
	* Definition for a binary tree node.
	*/
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	TreeNode* root;

	void bt_insert(TreeNode*& root, TreeNode* n);
	void bt_insert(TreeNode*& root, Dtype e);
	vector<Dtype> bt_travelRe(TreeNode*& root);
	vector<Dtype> bt_travelIt(TreeNode*& root);

	public:
		BItree() :root(NULL) {};
		void btTreeInsert(Dtype e) { bt_insert(root, e); };
		vector<Dtype> btTreeTravelRe() { return bt_travelRe(root); };
		vector<Dtype> btTreeTravelIt() { return bt_travelIt(root); };

	};

	template <typename Dtype>
	void BItree<Dtype>::bt_insert(TreeNode*& root, TreeNode* n) {
		if (root == NULL) {
			root = n;
			return;
		}

		if (n->val < root->val) {
			bt_insert(root->left, n);
		} else {
			bt_insert(root->right, n);
		}
	}

	template <typename Dtype>
	void BItree<Dtype>::bt_insert(TreeNode*& root, Dtype e) {
		bt_insert(root, new TreeNode(e));
	}

	//1 preorder
	// 1.1 solution using recursive
	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_travelRe(TreeNode*& root) {
		if (root == NULL) {
			return vector<Dtype>();
		}

		vector<Dtype> vecTree;
		vecTree.push_back(root->val);
		bt_travelRe(root->left);
		bt_travelRe(root->right);
	}

	// 1.2 solution using stack 
	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_travelIt(TreeNode*& root) {
		return vector<Dtype>();
	}
}