#Sundy
##专题1-2
1 this为指向当前类的对象的指针变量

如果this放在构造函数中代表此构造函数创建的对象的地址
如果this放在普通函数中代表调用此函数的对象的地址

例程:
	#include <iostream>
	using namespace std;
	
	class B{
		int data;
	public:
		B(){
			cout<<"B()"<<this<<endl;  //此处的this为此构造函数创建的对象的的地址
		}
	
		void show(){
			cout<<"this="<<this<<endl;  //此处的this为调用此函数的对象的地址
		}
	};
	
	int main(){
		B a1;
		a1.show();
		cout<<"a1的地址为:"<<&a1<<endl;
		cout<<endl;
	
		B a2;
		a2.show();
		cout<<"a2的地址为"<<&a2<<endl;
		return 0;
	}
	
	输出为：
	B()0xbfb64430
	this=0xbfb64430
	a1的地址为:0xbfb64430
	
	B()0xbfb6442c
	this=0xbfb6442c
	a2的地址为0xbfb6442c
	c

