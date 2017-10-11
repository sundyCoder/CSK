/*
 * Queue.cc
 *
 *  Created on: 2012-9-5
 *      Author: root
 */

#include <iostream>
using namespace std;
#define MaxSize 10

template <class T>
class Queue{
private:
	T data[MaxSize];
	int front;
	int rear;
public:
	Queue():front(0),rear(0){}
	~Queue(){
		cout<<"~Queue()"<<endl;
		for(int i=front;i<rear;i++)
			cout<<"del:"<<data[i]<<' ';
		cout<<endl;
	}
	void queue_enter(T e);
	T queue_out();
	int queue_size();
	T queue_getFront();
	T queue_getRear();
	bool queue_empty();
	void queue_travel();
	bool queue_full();
	void queue_clear();
};

template <class T>
	void Queue<T>::queue_enter(T e){
	data[rear]=e;
	rear=(rear+1)%10;
}

template <class T>
	T Queue<T>::queue_out(){
	if(rear == front)
		throw "Queue Empty!";
	T out = data[front];
	front = (front+1)%MaxSize;
	return out;
}

template <class T>
 int Queue<T>::queue_size(){
	return ((rear-front+MaxSize)%MaxSize);
}

template <class T>
	T Queue<T>::queue_getFront(){
	return data[front];
}

template <class T>
	T Queue<T>::queue_getRear(){
	return data[rear-1];
}

template <class T>
	bool Queue<T>::queue_empty(){
	return front == rear;
}

template <class T>
	void Queue<T>::queue_travel(){
	if(!queue_empty()){
		for (int i = front; i < rear; ++i) {
			cout<<" "<<data[i];
		}
		cout<<endl;
	}
}

template <class T>
	bool Queue<T>::queue_full(){
	return ((rear+1)%MaxSize == front);
}


template <class T>
	void Queue<T>::queue_clear(){
	front = rear = 0;
}

int main(){
	Queue<string> queue;
	/*for (int i = 0; i < 4; ++i) {
		double value = (i+1)*1.1;
		queue.queue_enter(value);
	}*/
	queue.queue_enter("aaa");
	queue.queue_enter("bbb");
	queue.queue_enter("ccc");
	queue.queue_travel();
	cout<<"size:"<<queue.queue_size()<<endl;
	cout<<"front:"<<queue.queue_getFront()<<endl;
	cout<<"rear:"<<queue.queue_getRear()<<endl;
	cout<<"out:"<<queue.queue_out()<<endl;
	//queue.queue_clear();
	queue.queue_travel();
	return 0;
}

/*
用数组实现先进先出的队列(对头出，队尾进)：
  1 栈空的判断条件: front == rear;
  2 栈满的判断条件: (rear+1)%MaxSize == front;
  3 每次进队，出对之后都要修改front,rear的值。
*/