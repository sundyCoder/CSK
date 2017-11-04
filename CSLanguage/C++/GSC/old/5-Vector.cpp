/*
 * Vector.cc
 *
 *  Created on: 2012-9-5
 *      Author: Jchen   email:stevenchen1990@163.com
 */

//vector向量各种操作的实现
//vector本质上就是一个动态数组

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Vector{
private:
	T* pb;  //指向第一个元素的指针
	T* pe;  //指向最后一个元素的下个位置的指针
	T* pc;  //最大容量处的指针
public:
	class Iterator{    //迭代器
	private:
		T* pt;
	public:
		Iterator(T* pt = T()):pt(pt){}

		bool operator!=(const Iterator& it){ //!=运算符的重载
					return pt!=it.pt;
			}

		T operator*(){
			return  *pt;
		}

		Iterator& operator++(){
			pt++;
		  	return *this;
		}

		Iterator& operator--(){
			pt--;
		  	return *this;
		}
	};

	Vector():pb(0),pe(0),pc(0){}
	Vector(int n){  
		pb = new T[n];
		pe = pb;
		pc = pb+n;
	}
	~Vector(){if(pb) delete[] pb;}
	Vector(const Vector& v):pb(v.pb),pe(v.pe),pc(v.pc){}

	Vector& operator=(Vector& v){
			return NULL;
	}

	T& operator[](int pos){
				return pb[pos];
		}

	void vector_assign(T* o,T* n);
	T vector_back();
	T vector_front();
	Iterator vector_begin();
	Iterator vector_end();
	int vector_size();
	int vector_capacity();
	void vector_clear();
	bool vector_empty();
	Iterator vector_insert(int loc,const T& e);
	int vector_find(T e);
	void vector_erase(T e);
	T vector_pop_back();
	void vector_push_back(T e);
};

template <class T>
  void Vector<T>::vector_assign(T* o,T* n){
	for (int i = 0; i < n-o; ++i) {
		pb[i] = o[i];
		}
	pe = pb+(n-o);
}

template <class T>
	T Vector<T>::vector_back(){
	return *pe;
}

template <class T>
	T Vector<T>::vector_front(){
	return *pb;
}

template <class T>
 typename Vector<T>::Iterator Vector<T>::vector_begin(){
	return Iterator(pb);
}

template <class T>
	typename Vector<T>::Iterator Vector<T>::vector_end(){
	return Iterator(pe);
}

template <class T>
	int Vector<T>::vector_size(){
	return pe-pb;
}

template <class T>
	int Vector<T>::vector_capacity(){
	return pc-pb;
}

template <class T>
	void Vector<T>::vector_clear(){
  pe = pb;
}

template <class T>
	bool Vector<T>::vector_empty(){
	return pb == pe;
}

template <class T> //在pos后插入元素e,只有当vector中又元素时方可插入.
typename Vector<T>::Iterator Vector<T>::vector_insert(int pos, const T& e){
	if(pos<0 && pos>this->vector_size()) return;
	T* ppos = &pb[pos];
	int max =  pe - ppos+1;
	pe++;
	for (int i = pos+max; i > pos; --i) {
		pb[i+1] = pb[i];
	}
	pb[pos+1] = e;
	return Iterator(&pb[pos+1]);
}

template <class T>   //寻找某一个元素在Vector中的索引位置
int Vector<T>::vector_find(T e){
	T* ppb = pb;
	int count = 0;
	while(ppb!=pe){
		if(*ppb == e){
			break;
		}
		count++;
		ppb++;
	}
	return count;
}

template <class T>
	void Vector<T>::vector_erase(T e){
	int pos = this->vector_find(e);
	int max = this->vector_size();
	for (int i = pos; i < max ; ++i) {
		pb[i] = pb[i+1];
	}
	pe--;
}

template <class T>
	T Vector<T>::vector_pop_back(){
	T back = pb[this->vector_size()-1];
	pe--;
	return back;
}

template <class T>
	void Vector<T>::vector_push_back(T e){
	int n = vector_size();
	if(n==0){
		int index = 0;
		pb[index++] = e;
		pe = pb+1;
		return;
	}
	if(pe == pc){
		T* pt = new T[n*2];
		if(pb){
			delete[] pb;
			memcpy(pt,pb,n*sizeof(T));
			pb = pt;
		}
	}else{
		pb[n] = e;
		++pe;
	}

	pb[n] = e;
	pe = pb+n+1;
	pc = pb+2*n;
}


int main(){
	 Vector<int> v(10);
	 cout<<v.vector_size()<<","<<v.vector_capacity()<<endl;
	 Vector<int>::Iterator it;
		int a[] = {1,2,3,4,5};
		v.vector_assign(a,a+5);
		cout<<v.vector_size()<<","<<v.vector_capacity()<<endl;
		cout<<"begin:"<<*v.vector_begin()<<endl;
		cout<<"end:"<<*--v.vector_end()<<endl;
		cout<<v.vector_size()<<","<<v.vector_capacity()<<endl;
		v.vector_push_back(6);
		cout<<v.vector_size()<<","<<v.vector_capacity()<<endl;
		/*v.vector_clear();
		cout<<v.vector_size()<<","<<v.vector_capacity()<<endl;*/
		v.vector_insert(0,1);
		v.vector_insert(1,2);
		v.vector_insert(2,3);
		cout<<"end:"<<*v.vector_end()<<endl;
		v.vector_erase(2);
		cout<<"find:"<<v.vector_find(2)<<endl;
		cout<<"pop_back:"<<v.vector_pop_back()<<endl;
		it = v.vector_begin();
		while(it!=v.vector_end()){
			cout<<" "<<*it;
			++it;
		}
		cout<<endl;
	return 0;
}

/*
本代码为实现STL中的vector，不对的地方还希望纠正
本人email:stevenchen1990@163.com
*/