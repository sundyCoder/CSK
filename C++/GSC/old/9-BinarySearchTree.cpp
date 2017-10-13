/*
 * BinarySearchTree.cc
 *
 *  Created on: 2012-9-6
 *      Author: root
 */
 //二叉搜索树(哈夫曼树)的操作
#include <iostream>
using namespace std;

template <class T>
class Bst{
private:
	struct Node{
	T data;
	Node* left;
	Node* right;
	Node(const T& data =T()):data(data),left(NULL),right(NULL){}

	};
	Node* root;

	void bst_insert(Node*& head,T e);
	void bst_insert(Node*& head,Node* n);
	void bst_erase(Node*& head,const T& e);
	Node*& bst_find(Node* head,T& e);
	bool bst_update(Node* head,T& o,T& n);
	void bst_travel(Node* head);
	int bst_size(Node* head);
	int bst_leapNum(Node* head);
	int bst_height(Node* head);
	bool bst_empty(Node* head);
	void bst_clear(Node*& head);

public:
	Bst():root(NULL){}
	void bst_insert(T t){bst_insert(root,t);}
	void bst_erase(T t){bst_erase(root,t);}
	bool bst_update(T o,T t){return bst_update(root,o,t);}
	void bst_travel(){bst_travel(root);}
	int bst_size(){return bst_size(root);}
	int bst_leapNum(){return bst_leapNum(root);}
	int bst_height(){return bst_height(root);}
	bool bst_empty(){return bst_empty(root);}
	void bst_clear(){bst_clear(root);}
};

template <class T>
void Bst<T>::bst_insert(Node*& head,T e){
	bst_insert(head,new Node(e));
}

template <class T>
void Bst<T>::bst_insert(Node*& tree,Node* n){
	if(tree == NULL) {
		tree = n;
		return;
	}
	if(n == NULL) return;

	if(tree->data > n->data){
		bst_insert(tree->left,n);
	}else{
		bst_insert(tree->right,n);
	}
}

template <class T>
	void Bst<T>::bst_erase(Node*& head,const T& e){
	if(head == NULL) return ;
	if(head->data == e){
		Node* p = head->right;
		bst_insert(head->left,head->right);
		delete head;
		head = p;
		return;
	}
	if(head->data > e){
		bst_erase(head->left,e);
	}
	if(head->data < e){
		bst_erase(head->right,e);
	}
	return;
}

template <class T>
typename Bst<T>::Node*& Bst<T>::bst_find(Node* head,T& e){
	if(head == NULL) return head;
	if(head->data == e) return head;
	else if(e>head->data) return bst_find(head->right,e);
	else return bst_find(head->left,e);

}

template <class T>
	bool Bst<T>::bst_update(Node* head,T& o,T& n){
	if(head==NULL) return false;
	Node* p = bst_find(head,o);
	if(p == NULL) return false;
	erase(head,o);
	insert(head,n);
	return true;
}

template <class T>
	void Bst<T>::bst_travel(Node* head){
	if(head == NULL) return;
	bst_travel(head->left);
	cout<<head->data<<endl;
	bst_travel(head->right);

}

template <class T>
	int Bst<T>::bst_size(Node* head){
	if(head == NULL) return 0;
	return bst_size(head->left)+1+bst_size(head->right);
}

template <class T>
	int Bst<T>::bst_leapNum(Node* head){
	if(head == NULL)return 0;
	if(head->left==NULL && head->right== NULL) return 1;
	return bst_leapNum(head->left)+bst_size(head->right);
}

template <class T>
int Bst<T>::bst_height(Node* head){
	if(head == NULL) return 0;
	int n1 = bst_height(head->left);
	int n2 = bst_height(head->right);
	return (n1>n2?n1:n2)+1;
}

template <class T>
	bool Bst<T>::bst_empty(Node* head){
	return root == NULL;
}

template <class T>
	void Bst<T>::bst_clear(Node*& head){
	if(head == NULL) return;
	bst_clear(head->left);
	bst_clear(head->right);
	delete head;
	head = NULL;
}

int main(){
	Bst<int> bst;
	bst.bst_insert(53);
	bst.bst_insert(30);
	bst.bst_insert(72);
	bst.bst_insert(14);
	bst.bst_insert(39);
	bst.bst_insert(61);
	bst.bst_insert(81);
	/*bst.bst_update("ccc","ddd");
	bst.bst_insert("eee");*/
	bst.bst_travel();
	cout<<"height:"<<bst.bst_height()<<endl;
	cout<<"size:"<<bst.bst_size()<<endl;
	cout<<"leapNum:"<<bst.bst_leapNum()<<endl; //还有问题
	bst.bst_erase(14);
	bst.bst_travel();
	cout<<"size:"<<bst.bst_size()<<endl;
	cout<<"leapNum:"<<bst.bst_leapNum()<<endl;
	cout<<"=====clear========"<<endl;
	bst.bst_clear();
	bst.bst_travel();
	cout<<"height:"<<bst.bst_height()<<endl;
	return 0;
}
/*
本例程为二叉搜索树的相关操作

存在的问题：求叶子节点的个数总是多一。。。。。。。
*/