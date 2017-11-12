#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
	// 二叉树的插入
	void bt_insert(TreeNode*& root, TreeNode* n);
	void bt_insert(TreeNode*& root, Dtype e);
	// 二叉树的前序遍历 (preorder)
	vector<Dtype> bt_PreOrderRe(TreeNode*& root);
	vector<Dtype> bt_PreOrderIt(TreeNode*& root);
	vector<Dtype> bt_PreOrderMorris(TreeNode*& root);

	// 二叉树的层次遍历 (levelorder)
	int bt_height(TreeNode*& root);
	vector<Dtype> bt_getLevel(TreeNode*& root, int level);
	vector<Dtype> bt_LevelOrderRe(TreeNode*& root);
	vector<Dtype> bt_LevelOrderIt(TreeNode*& root);

	public:
		BItree() :root(NULL) {};
		void btTreeInsert(Dtype e) { bt_insert(root, e); };
		vector<Dtype> btPreOrderRe() { return bt_PreOrderRe(root); };
		vector<Dtype> btPreOrderIt() { return bt_PreOrderIt(root); };
		vector<Dtype> btPreOrderMorris() { return bt_PreOrderMorris(root); };
		// 二叉树的层次遍历 (levelorder)
		vector<Dtype> btLevelOrderRe() { return bt_LevelOrderRe(root); };
		vector<Dtype> btLevelOrderIt() { return bt_LevelOrderIt(root); };
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
	// 1.1  recursive solution
	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_PreOrderRe(TreeNode*& root) {
		if (root == NULL) {
			return vector<Dtype>();
		}

		vector<Dtype> resultTree, leftTree, rightTree;

		resultTree.push_back(root->val);
		leftTree = bt_travelRe(root->left);
		rightTree = bt_travelRe(root->right);

		if (leftTree.size() != 0) {
			resultTree.insert(resultTree.end(),leftTree.begin(),leftTree.end());
		}
		if (rightTree.size() != 0) {
			resultTree.insert(resultTree.end(),rightTree.begin(),rightTree.end());
		}
		return resultTree;
	}

	// 1.2 stack + iterative solution
	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_PreOrderIt(TreeNode*& root) {
		vector<Dtype> result;
		stack<const TreeNode*> s;
		if (root != nullptr) {
			s.push(root);
		}

		while (!s.empty()) {
			const TreeNode *p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != nullptr) {
				s.push(p->right);
			}
			if (p->left != nullptr) {
				s.push(p->left);
			}
		}
		return result;
	}

	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_PreOrderMorris(TreeNode*& root) {
		vector<Dtype> result;
		TreeNode* cur = root, *prev = nullptr;

		while (cur != nullptr) {
			if (cur->left == nullptr) {
				result.push_back(cur->val);
				prev = cur;
				cur = cur->right;
			}
			else {
				TreeNode* node = cur->left;
				while(node->right != nullptr && node->right != cur)
					node = node->right;

				if (node->right == nullptr) {
					result.push_back(cur->val);
					node->right = cur;
					prev = cur;
					cur = cur->left;
				}
				else {
					node->right = nullptr;
					cur = cur->right;
				}
			}
		}
		return result;
	}

	// 二叉树的层次遍历
	template <typename Dtype>
	int BItree<Dtype>::bt_height(TreeNode*& root) {
		if (root == nullptr) {
			return 0;
		} else {
			int lheight = bt_height(root->left);
			int rheight = bt_height(root->right);
			if (lheight > rheight) {
				return (lheight + 1);
			} else {
				return (rheight + 1);
			}
		}
	}
	
	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_getLevel(TreeNode*& root, int level) {
		if(root == nullptr){
			return vector<Dtype>();
		}

		vector<Dtype> result, leftTree, rightTree;
		if (level == 1) {
			result.push_back(root->val);
		}else if(level > 1) {
			leftTree = bt_getLevel(root->left, level - 1);
			rightTree = bt_getLevel(root->right, level - 1);
		}

		if (leftTree.size() > 0) {
			result.insert(result.end(), leftTree.begin(), leftTree.end());
		}

		if (rightTree.size() > 0) {
			result.insert(result.end(), rightTree.begin(), rightTree.end());
		}
		return result;
	}

	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_LevelOrderRe(TreeNode*& root) {
		int height = bt_height(root);
		vector<Dtype> result;
		for (int i = 1; i <= height; i++) { // 遍历每一层
			vector<Dtype> ret = bt_getLevel(root, i);
			if (ret.size() > 0) {
				result.insert(result.end(), ret.begin(), ret.end());
			}
		}
		return result;
	}

	template <typename Dtype>
	vector<Dtype> BItree<Dtype>::bt_LevelOrderIt(TreeNode*& root) {
		if (root == nullptr) {
			return vector<Dtype>();
		}

		vector<Dtype> result;
		queue<TreeNode*> bt_queue;
		bt_queue.push(root);
		while (bt_queue.empty() == false) {
			TreeNode* node = bt_queue.front();
			result.push_back(node->val);
			bt_queue.pop();

			if (node->left != NULL) {
				bt_queue.push(node->left);
			}

			if (node->right != NULL) {
				bt_queue.push(node->right);
			}
		}
		return result;
	}
}
