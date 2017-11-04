# Sundy
## C++学习总结week03
### 一.复习上节课
1 static 静态的

在C语言中:

	(1)修饰局部变量，在第一次调用那段代码的时候生成，程序结束时销毁。
	(2)修饰全局变量，和普通全局变量相比，生命周期没变化，都是在main函数之前产生。和普通全局变量的区别是作用域，静态全局变量只能在本文件中使用。
	(3)修饰全局函数（作用域 只能在本文件中使用，文件外无法使用）

在C++中 :

- (1)修饰成员变量(静态成员变量)  需要在类外进行初始化
	
		class A{static int i;int j; char c;static void fn(){}; void fn2(){};}
		int A::i = 0;


- (2)修饰成员函数(静态成员函数)


- (3)静态的内容是属于类的，非静态的内容是属于对象的。
 
		A::fn();  a1.fn2();


- (4)静态函数只能访问静态成员数据，非静态函数既能访问静态成员，又能访问非静态成员。
 
		sizeof只跟类型有关，与内容无关。
		class中成员函数都存在代码段。函数名是指针，类仅仅是调用成员函数。
		class中的static成员变量可以看做是一种特殊的全局变量。
		sizeof(A)  = 8 只是int j; char c;再考虑内存对齐 //其中static int i；在C++中，静态成员变量在数据段，是一种特殊的全局变量。只不过调用时要用域作用符。
		sizeof(a1) = 8 只是int j; char c;再考虑内存对齐。

- (5)因此在考虑类的大小时，丢掉静态成员变量，丢掉成员函数，其余的按计算结构体的方法(内存对齐)计算类的大小。

 2 C++中所有的对象都是唯一的。
	
	#include <iostream>
	using namespace std;
	
	class A{
		static int i; //class中的static成员变量可以看做是一种特殊的全局变量
		int j;
		char c;
		static void fn(){}
		void fn2(){}
	};
	
	class B{
		//空类只占一个字节,是为了保证空类创建的对象在內存中都占唯一的地址。
	};
	
	int main(){
		A a1;
		cout<<sizeof(A)<<","<<sizeof(a1)<<endl; // 8,8
	
		B b1,b2;
		cout<<&b1<<","<<&b2<<endl;  //0xbfe06ecb,0xbfe06eca ，可见只隔一个字节
	
		B b3;
		B b4 = b3;
		B &b5 = b3; //只有b3,b4两个对象
		return 0;
	}


3 单例模式(单子模式)

在全局和静态函数中没有this,因为连对象都没有。
	#include <iostream>
	using namespace std;
	
	class Singleton{
	private:
		//其它成员
		//static Singleton s; //1
		int data;
		Singleton(int i):data(i){cout<<"Singleton()"<<endl;}
		Singleton(const Singleton &s):data(s.data){cout<<"Singleton(copy)"<<endl;}
		//拷贝构造函数设置为私有的是为了避免外部调用拷贝构造函数
		//如果为public的话,Singleton s = *ps1;又会调用拷贝构造函数，从而创建新的对象。
	public:
		static Singleton* getInstance(){
			static Singleton s(10); //也可以写在1的地方，但是需要在类外部进行初始化。
			return &s;
		}
	
		~Singleton(){cout<<"~Singleton()"<<endl;}
	
		void show(){
			cout<<this<<endl;
			cout<<"data="<<data<<endl;
		}
	};
	
	//Singleton Singleton::s; //1
	
	int main(){
		Singleton *ps1 = Singleton::getInstance();
		Singleton *ps2 = Singleton::getInstance();
		ps1->show();
		ps2->show();
		return 0;
	}
4 拷贝构造函数



- 以下5种情况会调用拷贝构造函数:
		class A{};
		void fn(A aa,A ab){
			//A aa = a1;  //隐含的操作，因此会调用拷贝构造函数
			//A ab = a2;  //隐含的操作，因此会调用拷贝构造函数
		};
		
		void fn2(A& aa,A& ab){
			//A &aa = a1; //隐含的操作，因此不会调用拷贝构造函数
			//A &ab = a2;
		}
		
		A a;    // 5 全局的，当用函数gn()返回时,也会调用。
		
		(inline)A gn(){   //会执行类型检查，比宏定义高级一些
		        //A a;      //编译器会优化，没有调用拷贝构造函数。
			//static A a; //4编译器不会优化，会调用拷贝构造函数。
			return a;
		}
		
		A a1;     //不会		
		A a2(a1); //1会
		A a3 = a1;//2会
		fn(a1,a2);//3会
		fn2(a1,a2);//不会
		A a4 = gn();//5会


- 浅拷贝 VS 深拷贝(加强对内存的理解)

		浅拷贝:系统默认的拷贝构造函数:成员逐字节的拷贝(指针成员一定会造成浅拷贝)
		深拷贝:自己写拷贝构造函数:创建新的内存空间。（拷贝指针指向的内容）


- 正确写拷贝构造函数
 
		class A{
			A(A a){}     //error 死循环。(形参是一个新的变量(对象),用实参来初始化)
			A(A &a){}    //OK 
			A(const A &a)//更完美
		};
 

- 单重继承(派生)
 
		class A{};           //A叫基类 父类
		class B:public A{}; //B叫子类 也叫派生类
		读法：A派生出B, B继承A

- 初始化列表
	 
		以下情况必须用初始化列表中初始化。
		    (1)常量
		    (2)引用  
		    (3)调用成员对象的带参构造函数。	
		    (4)调用父类对象的带参构造函数。(创建子类对象一定会先调用父类构造函数，为了指明调用父类中哪一个带参构造函数)
		以下情况必须用构造函数初始化。
		    (1)数组
		    (2)结构体


###二.多态性

1 访问修饰符private,protected,public (类中所有的成员默认的都是private,继承中默认的也是private)
		
基类的访问特性	类的继承特性	子类的访问特性
![](http://i.imgur.com/3rHWRa9.png)

2.多态实例  见专题3-2

3. 纯虚函数
 
	只有函数声明,没有函数实现的函数,成为纯虚函数。
	
		virtual void eat(Food& food) = 0; //纯虚函数,交给子类去实现
4. 抽象类：拥有 纯虚函数 的类成为抽象类。

	特征：抽象类本身不能实例化（不能产生对象）
   当子类继承抽象类的时候，一定要实现那个抽象类的所有虚函数，否则这个子类也是抽象类。



 **作业:** 

- 	1 阅读美国的那本<23个设计模式>
- 	2 为什么父类中有了虚函数，析构函数必须写成虚析构函数？
- 	3 用引用实现多态（饲养员给动物喂食物）
