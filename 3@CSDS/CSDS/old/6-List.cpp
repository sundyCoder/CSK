/*
 * List.cc
 *
 *  Created on: 2012-9-6
 *      Author: root
 */

 //山寨版STL中的list 
#include <iostream>
using namespace std;

template <class T>
class CLink{
private:
	struct Node{
		T data;
		Node* prev;
		Node* next;
		Node(const T& data = T()):data(data),prev(0),next(0){}
	};
	Node* head;
	Node* tail;
public:
	class Iterator{
	public:
		Node* pt;

		Iterator(Node* pt = NULL):pt(pt){}

		bool operator!=(const Iterator& it) {
			return pt->data != it.pt->data;
		}

		friend ostream& operator<<(ostream& os,Iterator& it){
			os<<it.pt->data;
			return os;
		}

		Node& operator*() {
			return pt;
		}

		Iterator& operator++() {
			this->pt = this->pt->prev;
			return *this;
		}

		Iterator& operator--() {
			this->pt = this->pt->next;
			return *this;
		}
	};
	CLink():head(0),tail(0){}

	void link_insert_back(const T& e);
	void link_insert_front(const T& e);
	void link_reverse();
	void link_sort();
	void link_swap();
	void link_merge();
	int link_size();

	Iterator link_begin();
	Iterator link_end();
	Iterator link_rbegin();
	Iterator link_rend();
};

template <class T>
void CLink<T>::link_insert_front(const T& e){
	Node* p = new Node(e);
		if(head == NULL){
			head = p;
			tail = p;
			return;
		}
		head->prev = p;
		p->next = head;
		head = p;
}

template <class T>
void CLink<T>::link_insert_back(const T& e){
	Node* p = new Node(e);
	if(head == NULL){
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
	p->prev = tail;
	tail = p;
}

template <class T>
	void CLink<T>::link_reverse(){
	/*Node* phead = head->next;
	head->next = NULL;

	Node* p = phead;
	while(p!=NULL){
		link_insert_front(p->data);
		p = p->next;
	}*/

	Node*& temp = head;
	head = tail;
	tail = temp;
}

template <class T>
	void CLink<T>::link_sort(){

}

template <class T>
	void CLink<T>::link_swap(){

}

template <class T>
	void CLink<T>::link_merge(){

}

template <class T>
	int CLink<T>::link_size(){
	return tail-head;
}

template <class T>
typename CLink<T>::Iterator CLink<T>::link_begin(){
	return Iterator(head);
	}

template <class T>
typename CLink<T>::Iterator CLink<T>::link_end(){
	return Iterator(tail);
}


template <class T>
typename CLink<T>::Iterator CLink<T>::link_rbegin(){
	return Iterator(tail);
	}

template <class T>
typename CLink<T>::Iterator CLink<T>::link_rend(){
	return Iterator(head);
}

int main(){
	CLink<int> cl;
	CLink<int>::Iterator itb;
	CLink<int>::Iterator ite;

	CLink<int> cl2;
	CLink<int>::Iterator itb2;
	CLink<int>::Iterator ite2;
	cl2.link_insert_back(6);
	cl2.link_insert_back(7);
	cl2.link_insert_back(8);
	cl2.link_insert_back(9);
	cl.link_insert_back(1);
	cl.link_insert_back(2);
	cl.link_insert_back(3);
	cl.link_insert_back(4);
	cout<<"size:"<<cl.link_size()<<endl;
	//cl.link_reverse();  //has some problem
	itb = cl.link_rbegin();
	ite = CLink<int>::Iterator(cl.link_rend());
	while(itb != ite){
		cout<<" "<<itb;
		++itb;
	}
	cout<<endl;
	cout<<"=========cl2========="<<endl;
	itb2 = cl2.link_begin();
	ite2 = CLink<int>::Iterator(cl2.link_end());
		while(itb2 != ite2){
			cout<<" "<<itb2;
			--itb2;
		}
		cout<<endl;
	return 0;
}

/*
由于无法让list_end()返回指向最后一个元素的下一个，因此上面的方法还有很多没有实现
能力有限，等有能力了在继续实现。
*/