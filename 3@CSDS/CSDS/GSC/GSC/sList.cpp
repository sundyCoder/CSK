//
//#include <iostream>
//using namespace std;
//
//template <class T>
//class SList {
//private:
//	struct Node {
//		T data;
//		Node* next;
//		Node(T data) :data(data), next(NULL) {};
//	};
//
//	Node* head;
//public:
//	SList() :head(NULL) {};
//	~SList() { cout << "~SList()" << endl; };
//	void insert_front(const T e);
//	void insert_back(const T e);
//	int list_find(const T e);
//	int list_size();
//	bool list_erase(const T e);
//	void list_update(int n, const T e);
//	void list_travel();
//	Node* list_getPointer(int pos);
//};
//
//template <class T>
//void SList<T>::insert_front(const T e) {
//	Node* p= new Node(e);
//	p->next = head;
//	head = p;
//}
//
//template <class T>
//void SList<T>::insert_back(const T e) {
//	Node* p = new Node(e);
//	if (head == NULL) {
//		head = p;
//		return;
//	}
//	Node* q = head;
//	while (q->next != NULL) {
//		q = q->next;
//	}
//	q->next = p;
//}
//
//
//template <class T>
//int SList<T>::list_find(const T e) {
//	if (head == NULL) {
//		return -1;
//	}
//	int n = 0;
//	Node* p = head;
//	while (p != NULL) {
//		if (p->data == e) {
//			break;
//		}
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//
//template <class T>
//int SList<T>::list_size() {
//	int n = 0;
//	Node* p = head;
//	while (p != NULL) {
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//
//template <class T>
//typename SList<T>::Node* SList<T>::list_getPointer(int pos) {
//	if (head == NULL)
//		return NULL;
//	if (pos < 0 || pos >= list_size()) {
//		return NULL;
//	}
//	Node* p = head;
//	for (int i = 0; i < pos; i++) {
//		p = p->next;
//	}
//	return p;
//}
//
//template <class T>
//bool SList<T>::list_erase(const T e) {
//	int pos = list_find(e);
//	if (pos == -1)
//		return false;
//	if (pos == 0) {
//		Node* p = head->next;
//		delete head;
//		head = p;
//	} else {
//		Node* pre = list_getPointer(pos - 1);
//		Node* cur = pre->next;
//		pre->next = cur->next;
//		delete cur;
//	}
//	return true;
//}
//
//template <class T>
//void SList<T>::list_update(int n, const T e) {
//	if (n < 0 || n > list_size()) {
//		return;
//	}
//	Node* cur = list_getPointer(n);
//	cur->data = e;
//	return;
//}
//
//template <class T>
//void SList<T>::list_travel() {
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
//int main_slist(int argc, char** argv) {
//	SList<int> list;
//	list.insert_back(1);
//	list.insert_back(2);
//	list.insert_back(3);
//	cout << list.list_find(2) << endl;
//	//list.list_erase(2);
//	list.list_update(1, 4);
//	list.list_travel();
//	system("pause");
//	return 0;
//}
//
//
