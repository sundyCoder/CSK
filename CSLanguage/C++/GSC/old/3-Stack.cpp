/*
 * Stack.cc
 *
 *  Created on: 2012-9-5
 *      Author: root
 */

//对栈的基本操作
#include <iostream>
using namespace std;
#define MaxSize 10

template <class T>
class Stack{
private:
	T data[MaxSize];
	int top;
public:
	Stack(const T& data = 0):top(-1){}
	void stack_push(T e);
	T stack_pop();
	T stack_peek();
	T stack_gettop();
	void stack_travel();
	bool stack_empty();
	bool stack_full();
	void stack_clear();
};
template <class T>
	void Stack<T>::stack_push(T e){
	if(top<MaxSize)
	top++;
	data[top] = e;
}

template <class T>
	T Stack<T>::stack_pop(){
	if(top==-1)
		throw "Stack empty!";
		return data[top--];
}

template <class T>
	T Stack<T>::stack_peek(){
	if(top==-1) throw "stack empty!";
	return data[top];
}

template <class T>
	void Stack<T>::stack_travel(){
	for (int i = 0; i <= top; ++i) {
		cout<<" "<<data[i];
	}
	cout<<endl;
}

template <class T>
	bool Stack<T>::stack_empty(){
	return top == -1;
}

template <class T>
	bool Stack<T>::stack_full(){
	return top == MaxSize -1;
}

template <class T>
	void Stack<T>::stack_clear(){
	top = -1;
}


int main(){
	Stack<int> stack;
	stack.stack_push(1);
	stack.stack_push(2);
	stack.stack_push(3);
	stack.stack_push(4);
	stack.stack_travel();
	cout<<"pop:"<<stack.stack_pop()<<endl;
	stack.stack_travel();
	cout<<"peek:"<<stack.stack_peek()<<endl;
	cout<<"empty:"<<stack.stack_empty()<<endl;
	cout<<"full:"<<stack.stack_full()<<endl;
	stack.stack_clear();
	stack.stack_travel();
	cout<<"empty:"<<stack.stack_empty()<<endl;
	cout<<"full:"<<stack.stack_full()<<endl;
	return 0;
}
