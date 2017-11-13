//#include <iostream>
//
//using namespace std;
//
//template <class T>
//class DList {
//private:
//	struct Node{
//		T data;
//		Node* next;
//		Node* pre;
//		Node(const T data) :data(data), next(NULL), pre(NULL) {};
//	};
//
//	Node* head;
//	Node* tail;
//
//public:
//	DList() :head(NULL), tail(NULL) {};
//	~DList() { cout << "~DList()" << endl; };
//	void dinsert_front(const T e);
//	void dinsert_back(const T e);
//	void dinsert_insert(int pos,const T e);
//	int dlist_size();
//	int dlist_find(const T e);
//	Node* dlist_getPointer(int pos);
//	bool dlist_erase(const T e);
//	void dlist_update(int pos, const T e);
//	void dlist_travel();
//};
//
//template <class T>
//void DList<T>::dinsert_front(const T e) {
//	Node* p = new Node(e);
//	if (head == NULL) {
//		head = p;
//		tail = p;
//		return;
//	}
//	head->pre = p;
//	p->next = head;
//	head = p;
//}
//
//template <class T>
//void DList<T>::dinsert_back(const T e) {
//	Node* p = new Node(e);
//	if (head == NULL) {
//		head = p;
//		tail = p;
//		return;
//	}
//	Node* q = tail;
//	while (q->next != NULL) {
//		q = q->next;
//	}
//	tail = q;
//	q->next = p;
//	p->pre = tail;
//	tail = p;
//}
//
//template <class T>
//int DList<T>::dlist_size() {
//	if (head == NULL)
//		return 0;
//	Node* p = head;
//	int n = 0;
//	while (p != NULL) {
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//
//template <class T>
//void DList<T>::dinsert_insert(int pos, const T e) {
//	Node* p = new Node(e);
//	if (head == NULL) {
//		tail = p;
//		head = p;
//		return;
//	}
//	Node* q = head;
//	int n = -1;
//	while (q != NULL) {
//		n++;
//		if (n == pos) {
//			p->next = q->next;
//			q->next->pre = p;
//			p->pre = q;
//			q->next = p;
//		}
//		q = q->next;
//	}
//}
//
//
//template <class T>
//typename DList<T>::Node* DList<T>::dlist_getPointer(int pos) {
//	if (head == NULL) return NULL;
//	if (pos<0 && pos> dlist_size()) return NULL;
//	Node* p = head;
//	int n = -1;
//	while (p != NULL) {
//		n++;
//		if (pos == n)
//			break;
//		p = p->next;
//	}
//	return p;
//}
//
//template <class T>
//int DList<T>::dlist_find(const T e) {
//	int n = -1;
//	if (head == NULL)
//		return -1;
//	Node* p = head;
//	while (p != NULL) {
//		n++;
//		if (p->data == e) {
//			break;
//		}
//		p = p->next;
//	}
//	return n;
//}
//
//template <class T>
//bool DList<T>::dlist_erase(const T e) {
//	int pos = dlist_find(e);
//	if (pos == -1) return false;
//	if (pos == 0) {
//		Node* p = head->next;
//		delete head;
//		head = p;
//	}
//	else {
//		Node* prev = dlist_getPointer(pos - 1);
//		Node* cur = prev->next;
//		cur->pre->next = cur->next;
//		delete cur;
//	}
//	return true;
//}
//
//template <class T>
//void DList<T>::dlist_update(int pos, const T e) {
//	
//}
//
//
//template <class T>
//void DList<T>::dlist_travel() {
//	if (head == NULL)
//		return;
//	Node* p = head;
//	while (p != NULL) {
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//
//
//int main_dlist(int argc, char** argv) {
//	DList<int> dlist;
//	dlist.dinsert_back(1);
//	dlist.dinsert_back(2);
//	dlist.dinsert_back(3);
//	dlist.dinsert_insert(1, 4);
//	dlist.dlist_travel();
//	dlist.dlist_erase(2);
//	dlist.dlist_travel();
//	system("pause");
//	return 0;
//}
//
