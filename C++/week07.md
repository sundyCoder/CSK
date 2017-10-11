# Sundy
## C++学习总结week07

### 涉及内容:

	  IO流
	  自定义模板
	  泛型编程
	  STL
	  数据结构和算法

### 一.I/O流(标准IO（控制台IO）cin,cout,cerr,clog) (其中的c代表console)
1 输入:从键盘提取数据->键盘缓冲区->输入缓冲区->应用程序

	输入流对象cin(全局的，唯一)  
	int i;   cin>>i; 100\n  遇到空格，回车就被输入到输入缓冲区
  
 2 输出：程序->输出缓冲区->屏幕

    输出流对象cout
    输出 ！= 显示(有时存在输出缓冲区中，必须刷新)
    cout<<"chen"； 
    cout<<'\n'; cout<<endl;cout<<flush;  缓冲区满，这三种情况输出到屏幕。
   

  3  I/O流支持改向(重定向)

  4 cerr,clog输出不带缓存，也不能够重定向

  5  get

	   (1) get()函数有两种：char ch1 = get();  cin.get(ch1).get(ch2);
	   (2) getline()函数的用法:
  
		    char buf[10];
		    cin.getline(buf,sizeof(buf),'\n'); //默认的有'\n'这个参数，可以不写
  
		  例如1: char buf[10];
			cout<<"input a string:";
			cin.getline(buf,sizeof(buf),'\n'); //当输入大小超过缓冲区大小时，以后的输入流将无效
			if(!cin){
				cin.clear();
			}  //处理流的错误状态
		
		 例程2：int main(){
			ifstream fin("/etc/passwd");
			string str;
			getline(fin,str,':');
			cout<<"username:"<<str<<endl;
			getline(fin,str,':');
			cout<<"password:"<<str<<endl;
			fin.close();
			return 0;
		}
     
	(3) ignore()函数：
    	 cin.ignore(10000,'\n')；//忽略10000个字符，或者直到遇到‘\n’
	
		自己实现ignore():
		void my_ignore(int n, char ch) {
			for (int i = 0; i < n; ++i) {
				if (cin.get() == ch)
					break;
			}


    （4）peek()
	    int age;
		string name;
		cout<<"input age or name:";
		char ch = cin.peek();
		if(ch>='0'&&ch<='9'){
			cin>>age;
			cout<<"age:"<<age<<endl;
		}else{
			cin>>name;
			cout<<"name:"<<name<<endl;
		}

   	(5)putback()
	   	char ch1,ch2;
		cin>>ch1;
		cout<<"ch1:"<<ch1<<endl;
		cin.putback('M');
		cin>>ch2;
		cout<<"ch2:"<<ch2<<endl;

  6 注意:打印字符的地址，数组名。输出的一定是内容，不是地址。

    只有字符如此特例，其余的都是是打印的是地址。
    要打印出字符的地址用(void *)ch
  
  7 满递减堆栈  
  
  8 A a;

	    if(a){
		cout<<"cout:"<<cout<<endl;
		}else{
		cout<<"cin:"<<cin<<endl;
		}
	   是因为重载了class A{
	                 public:
	        	 operator void*(){
			    return NULL;
	         	  }
	                }; 

### 二 ostream
 1 除开width()是一次性的，其余都是永久性的。   
 
	    cout.width(10); //only onece
		cout.fill('*'); //forever
		cout<<"chen"<<endl;
		cout.width(20);
		cout<<"hong"<<endl;

 2 封装一下

	class wf{
		int w;
		char f;
	public:
		wf(int w,char f):w(w),f(f){}
		friend ostream& operator<<(ostream& os,const wf& o){
			os.width(o.w);
			os.fill(o.f);
			return os;
		}
	};

 3 Example
	
	#include <iostream>
	using namespace std;
	#include <iomanip>
	
	int main(){
		cout<<100<<endl;
		cout<<dec<<100<<endl;
		cout<<oct<<100<<endl;
		cout<<hex<<100<<endl;
		cout<<setw(20)<<setfill('*')<<hex<<100<<endl;
		return 0;
	}
	 
 4 拷贝一个文件
	#include <iostream>
	#include <fstream>
	using namespace std;
	
	int main(){
		ifstream fin("copy.cc");
		ofstream fout("copy");
		while(1){
			char ch = fin.get();
			if(ch == EOF) break;
			fout.put(ch);
		}
		fin.close();
		fout.close();
		cout<<"copy over!"<<endl;
		return 0;
	}


### 四 read(char *xx ) 和 write(char *xx)
 1 write()向磁盘中写数据
	
		ofstream fout("test.dat");
		fout.write((char *)&i,sizeof(i));
		fout.write((char *)&d,sizeof(d));
		fout.write((char *)&s,sizeof(s));
		fout.write((char *)&str,sizeof(str));//error
	
	   	fout.write((char*)str.c_str(),str.size());
		fout.write((char *)&a,sizeof(a));
 
 2 read()从磁盘中读数据

		ifstream fin("test.dat");
		fin.read((char *)&i,sizeof(i));
		fin.read((char *)&d,sizeof(d));
		fin.read((char *)&s,sizeof(s));
	  //fin.read((char *)&str,sizeof(str));//error
	
		fin.read((char*)str.c_str(),str.size());
		fin.read((char *)&b,sizeof(b));

### 五 模板（参数化的类型）
	  template <typename T>  .....
	  template <class T> ....

	例程:
	#include <iostream>
	using namespace std;
	
	//typedef int T;
	template <typename T> 
	void bubble_sort(T* ds,int n){ //模板的形参，会根据适当的类型填充
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n-i; ++j) {
				if(ds[j] > ds[j+1]){
					T temp = ds[j];
					ds[j] = ds[j+1];
					ds[j+1] = temp;
				}
			}
		}
	}
	
	template <class T> void show(T* t,int n){ 
		for (int i = 0; i < n; ++i) {
			cout<<t[i]<<' ';
		}
		cout<<endl;
	}
	
	int main(){
		int ds[10] = {0,3,2,1,4,9,6,7,8,5};
		show<int>(ds,10);  ////模板的实参，可以指定，也可以不指定
		bubble_sort<int>(ds,10);
		show<int>(ds,10);
	
		double dd[5] = {5.5,4.4,3.3,2.2,1.1};
		show<double>(dd,5);
		bubble_sort<double>(dd,5);
		show<double>(dd,5);
		return 0;
	}



### 作业：
- 1 自己用get()实现ignore()函数
- 2 实现在字符串从磁盘中读出来。
- 3 看看osstream
- 4 用模板实现 栈

		#include <iostream>
		using namespace std;
		
		const int MaxStackSize = 50;
		
		template<class T>
		class Stack{
		private:
			T data[MaxStackSize];
			int top;
		public:
			Stack(void);
			void Push(const T& item);
			T Pop(void);
			T Peek(void) const;
			void Travel() const;
			void ClearStack(void);
			bool StackEmpty() const;
			bool StackFull() const;
		};
		
		template <class T>
		Stack<T>::Stack(void):top(-1){}
		
		template <class T>
		void Stack<T>::Push(const T& item){
				if(top == MaxStackSize-1){
					cerr<<"Stack overflow!"<<endl;
					exit(1);
				}
				top++;
				data[top] = item;
			}
		
		template <class T>
		T Stack<T>::Pop(void){
			T temp;
			if(top == -1){
				cerr<<"Attempt to pop a empty stack!"<<endl;
				exit(1);
			}
		
			top--;
			temp = data[top];
			return temp;
		}
		template <class T>
		T Stack<T>::Peek(void) const{
			if(top == -1){
				cerr<<"Attempt to peek an empty stack!"<<endl;
				exit(1);
			}
		
			return data[top];
		}
		
		template <class T>
		void Stack<T>::Travel() const{
			if(top == -1){
				cerr<<"The stack is empty!"<<endl;
				cout<<"NULL"<<endl;
			}
			for (int i = 0; i < top+1; ++i) {
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
		
		template <class T>
		void Stack<T>::ClearStack(void){
			top = -1;
		}
		
		template <class T>
		bool Stack<T>::StackEmpty() const{
			return top == -1;
		}
		
		template <class T>
		bool Stack<T>::StackFull() const{
			return top == MaxStackSize-1;
		}
		
		int main(){
			Stack<int> stack;
			stack.Push(1);
			stack.Push(3);
			stack.Push(2);
			stack.Push(4);
			stack.Travel();
		
			stack.Pop();
			stack.Travel();
			cout<<stack.Peek()<<endl;
			cout<<stack.StackFull()<<endl;
		
			stack.ClearStack();
			stack.Travel();
			cout<<stack.StackEmpty()<<endl;
			return 0;
		}
	








