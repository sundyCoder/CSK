

//单链表所有操作的实现

#include <iostream>
using namespace std;

template <class T>
class List{        //链表类
private:
	struct Node{   //每个节点类型
		T data;    //数据节点
		Node* next;//指向下一个节点的指针
		Node(T data):data(data),next(NULL){} //构造函数初始化
	};
Node* head;   //头指针
public:
	List():head(NULL){}
	~List(){cout<<"~List()"<<endl;}
	void list_insert_front(const T e);
	void list_insert_back(const T e);
	void list_insert(int pos,T data);
	bool list_erase(const T e);
	bool list_eraseAll(T t);
	void list_update(int n,const T e);
	void list_updateAll(T e1,T e2);
	int list_find(const T e);
	void list_travel();

	T list_getHead();
	T list_getTail();
    Node* list_getPointer(int pos);

	int list_size();
	int list_isEmpty();
	bool list_clear();
};


template <class T>
	void List<T>::list_insert_front(const T e){
	  Node* p = new Node(e);
	  p->next = head;
	  head = p;
}

template <class T>
	void List<T>::list_insert_back(const T e){
	Node* p = new Node(e);
	p->next = NULL;

	if(head == NULL){
		head = p;
		return;
	}

	Node* q = head;
	while(q->next != NULL){
		q = q->next;
	}
	q->next = p;
}

template <class T>
void List<T>::list_insert(int pos,T data){
	if(pos<0 || pos > list_size()) return;
	Node* q = new Node(data);
	if(head == NULL){
		head = q;
		return;
	}
	Node* p = head;
	int n = -1;
	while(p!=NULL){
		n++;
		if(pos == n){
			q->next = p->next;
			p->next = q;
		}
		p = p->next;
	}
}

template <class T>
	bool List<T>::list_erase(T e){
	int pos = list_find(e);
	cout<<"pos ="<<pos<<endl;
	if(pos == -1) return false;
	if(pos == 0){
		Node* p = head->next;
		delete head;
		head = p;
	}else{
		Node* pre = list_getPointer(pos-1);
		Node* cur = pre->next;
		pre->next = cur->next;
		delete cur;
	}
	return true;
}

template <class T>
 bool List<T>::list_eraseAll(T t){
	if(head==NULL)return false;
			Node *p = head;
			while(head!=NULL&&head->data==t){
				p = head->next;
				delete head;
				head = p;
			}  //如果第一个元素就是要删除的
			if(head==NULL)return true;

			Node *q = NULL;
			while(p->next!=NULL)
			{
				q = p->next;
				if(q->data==t)
				{
					p->next=q->next;
					delete q;
					continue;
				}
				p = p->next;
			}
			return true;
}

template <class T>
	void List<T>::list_update(int pos,T e){
	if(pos<0 && pos>list_size()) return;
	Node* cur = list_getPointer(pos);
	cur->data = e;
}

template <class T>
	void List<T>::list_updateAll(T e1,T e2){
	if(head == NULL) return;
	Node* p = head;
	while(p!=NULL){
		if(p->data == e1)
			p->data = e2;
		p = p->next;
	}
	return ;
}

template <class T>
	int List<T>::list_find(const T e){
	if(head == NULL) return -1;
	int n  =0;
	Node* p  = head;
	while(p!=NULL){
		if(p->data == e){
			break;
		}
		n++;
		p = p->next;
	}
	return n;
}

template <class T>
T List<T>::list_getHead(){
	if(head == NULL) throw "no head!";
		return (head->data);
}

template <class T>
T List<T>::list_getTail(){
	if(head == NULL) throw "no tail!";
	Node* p = head;
	while(p->next!=NULL)
		p = p->next;
	return p->data;
}

template <class T>
typename List<T>::Node* List<T>::list_getPointer(int pos){
	if(head==NULL)return NULL;
	if(pos<0||pos>=list_size())return NULL;
	Node *p = head;
	for(int i=0;i<pos;i++)
	{
		p = p->next;
	}
	return p;
}

template <class T>
void List<T>::list_travel(){
	Node* p = head;
	while(p!=NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

template <class T>
	int List<T>::list_size(){
	 if(head == NULL) return 0;
	 int count = 0;
	 Node* p = head;
	 while(p!=NULL){
		 count++;
		 p = p->next;
	 }
	 return count;
}

template <class T>
	int List<T>::list_isEmpty(){
	return head == NULL;
}

template <class T>
	bool List<T>::list_clear(){
	if(head == NULL) return false;
	while(head!=NULL){
		Node* p = head->next;
		delete head;
		head = p;
	}
	return true;
}

int main(){
	List<int> list;
	list.list_insert_back(1);
	list.list_insert_back(2);
	list.list_insert_back(3);
	list.list_insert_back(3);
	list.list_insert_back(0);
	list.list_insert_front(0);
	list.list_insert_front(-1);
  list.list_insert(0,-2);
	int size = list.list_size();
	cout<<"size:"<<size<<endl;
	int pos = list.list_find(0);
	cout<<"pos:"<<pos<<endl;

	cout<<"getHead:"<<list.list_getHead()<<endl;
	cout<<"getTail:"<<list.list_getTail()<<endl;
	list.list_travel();
	cout<<"=====erase======="<<endl;
	list.list_erase(-1);
	list.list_travel();
	cout<<"=====erase======="<<endl<<endl;
	cout<<"=====eraseAll======="<<endl;
	list.list_eraseAll(0);
	list.list_travel();
	cout<<"=====eraseAll======="<<endl;
	list.list_travel();
	cout<<"=====update========="<<endl;
	list.list_update(0,-1);
	list.list_travel();
	cout<<"=====updateAlll====="<<endl;
	list.list_updateAll(3,4);
	list.list_travel();
	cout<<"=====clear=========="<<endl;
	list.list_clear();
	list.list_travel();
	return 0;
}


/*
特别注意：
template <class T>
typename List<T>::Node* List<T>::list_getPointer(int pos){}

由于Node是List类中的一成员，此时应该像上述那样定义，否则出错。
*/