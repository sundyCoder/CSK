/*
 * DLinkList.cc
 *
 *  Created on: 2012-9-5
 *      Author: root
 */

//双链表的操作

#include <iostream>
using namespace std;

template <class T>
class DLinkList{
	struct Node{
		T data;
		Node* pre;
		Node* next;
		Node(const T& data = T()):data(data),pre(NULL),next(NULL){}
	};
	Node* head;   //双链表头指针
	Node* tail;	  //双链表尾指针
public:
	DLinkList():head(NULL),tail(NULL){}
	void dlist_insert_front(T e);
	void dlist_insert_back(T e);
	void dlist_insert(int pos,T e);
  bool dlist_erase(T e);
	bool dlist_eraseAll(T e);
	void dlist_update(int pos,T e);
	void dlist_updateAll(T e1,T e2);
	int dlist_find(T e);
	T dlist_getHead();
	T dlist_getTail();
	Node* dlist_getPointer(int pos);
	bool dlist_empty();
	bool dlist_clear();
	void dlist_travel();
	int dlist_size();
};

template <class T>
	void DLinkList<T>::dlist_insert_front(T e){
	Node* p = new Node(e);
	if(head == NULL){
		head = p;
		tail = p;
		return;
	}
	head->pre = p;
	p->next = head;
	head = p;
	}

template <class T>
	void DLinkList<T>::dlist_insert_back(T e){
	Node* p = new Node(e);
	if(head==NULL){
		head = p;
		tail = p;
		return;
	}

	Node* q = head;
	while(q->next!=NULL){
		q = q->next;
	}
	tail = q;
	tail->next = p;
	p->pre = tail;
	tail = p;
	}

template <class T>
	void DLinkList<T>::dlist_insert(int pos,T e){
	Node* p = new Node(e);
	if(head == NULL){
		head = p;
		tail = p;
		return;
	}
	Node* q = head;
	int n = -1;
	while(q!=NULL){
		n++;
		if(n == pos){
			p->next = q->next;
			q->next->pre = p;
			p->pre = q;
			q->next =  p;
		}
		q = q->next;
	}
	}

template <class T>
  bool DLinkList<T>::dlist_erase(T e){
	 int pos = dlist_find(e);
	 if(pos == -1) return false;
	 if(pos == 0){
		 Node* p = head->next;
		 delete head;
		 head = p;
	 }else{
		 Node* prev = dlist_getPointer(pos-1);
		 Node* cur = prev->next;
		 //prev->next = cur->next;
		 //cur->next->pre = cur->pre;  //  ?????
		 cur->pre->next = cur->next;
		 //cur->next->pre = cur->pre;  // ???
		 delete cur;
	 }
	return true;
  }

template <class T>
	bool DLinkList<T>::dlist_eraseAll(T e){
	if(head == NULL)return false;
	Node* p = head;
	while(head!=NULL && head->data == e){
	  p = head->next;
		delete head;
		head = p;

	}
	if(head == NULL) return true;

	Node* q = NULL;
	while(p->next!=NULL){
		q = p->next;
		if(q->data == e){
			p->next = q->next;
			delete q;
			continue;
		}
		p = p->next;
	}
	return true;
	}

template <class T>
	void DLinkList<T>::dlist_update(int pos,T e){
	Node* cur = dlist_getPointer(pos);
	if(cur == NULL) return;
	cur->data = e;
	}

template <class T>
	void DLinkList<T>::dlist_updateAll(T e1,T e2){
	if(head == NULL) return;
	Node* p = head;
	while(p!=NULL){
		if(p->data == e1)
			p->data = e2;
		p = p->next;
	}
	}

template <class T>
	int DLinkList<T>::dlist_find(T e){
	 if(head == NULL) return -1;
	 int n = -1;
	 Node* p = head;
	 while(p!=NULL){
		 n++;
		 if(p->data == e){
			 break;
		 }
		 p = p->next;
	 }
	 return n;
	}

template <class T>
	T DLinkList<T>::dlist_getHead(){
	return head->data;
	}

template <class T>
	T DLinkList<T>::dlist_getTail(){
	return tail->data;
	}

template <class T>
	typename DLinkList<T>::Node* DLinkList<T>::dlist_getPointer(int pos){
	if(head == NULL) return NULL;
	if(pos<0 && pos> dlist_size()) return NULL;
	Node* p = head;
	int n = -1;
	while(p!=NULL){
		n++;
		if(pos == n)
			break;
		p = p->next;
	}
	return p;
	}

template <class T>
	bool DLinkList<T>::dlist_empty(){
	return head == NULL;
	}

template <class T>
	bool DLinkList<T>::dlist_clear(){
	if(head == NULL) return false;
	while(head!=NULL){
		Node* p = head->next;
		delete p;
		head = p;
	}
	return  true;
	}

template <class T>
void DLinkList<T>::dlist_travel(){
	if(head == NULL) return;
	Node* p = head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

template <class T>
int DLinkList<T>::dlist_size(){
	if(head == NULL) return 0;
	int n = 0;
	Node* p = head;
	while(p!=NULL){
		++n;
		p = p->next;
	}
	return n;
}

int main(){
	DLinkList<int> dl;
	dl.dlist_insert_front(1);
	dl.dlist_insert_front(2);
	dl.dlist_insert_front(3);
	dl.dlist_insert_front(4);
	dl.dlist_insert_back(-1);

	dl.dlist_insert(3,0);
	dl.dlist_travel();
	dl.dlist_insert_back(66);
		dl.dlist_insert_back(66);
	cout<<"======erase======"<<endl;
	dl.dlist_erase(-1);
	dl.dlist_travel();
	dl.dlist_insert_back(66);
	dl.dlist_insert_back(66);
	dl.dlist_travel();
	cout<<"getHead:"<<dl.dlist_getHead()<<endl;
	cout<<"getTail:"<<dl.dlist_getTail()<<endl;
	cout<<"find:"<<dl.dlist_find(-1)<<endl;
	cout<<"size:"<<dl.dlist_size()<<endl;
	dl.dlist_eraseAll(66);
	dl.dlist_travel();

	dl.dlist_update(4,-1);
	dl.dlist_travel();
	dl.dlist_insert_back(-1);
	dl.dlist_insert_back(-1);
	dl.dlist_insert_back(-1);
	dl.dlist_travel();
	dl.dlist_updateAll(-1,5);
	dl.dlist_travel();
	dl.dlist_clear();
	cout<<"after clear:";
	dl.dlist_travel();
	cout<<"size:"<<dl.dlist_size()<<endl;
	return 0;
}

/*
注意dlist_eraseAll()  dlist_updateAll()两个函数的操作思想
*/