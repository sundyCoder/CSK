#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <array>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main_data_structure(int argc, char** argv) {
	//1. array为c++内建(build-in)数组,array是静态空间，一旦配置了就不能改变；要换个大（或小） 
	array<int, 1> array_test;
	array_test.fill(3);
	array_test.fill(4);
	//int array_test[1];
	cout << "array:" << sizeof(array_test) << endl; // 4 bytes

	/************************************************************************/
	/*	2. vector底层数据结构为动态数组,支持快速随机访问,dynamic array, resizable array.
		注意，所谓动态增加大小，并不是在原空间之后接续新空间（因为无法保证原空
		间之后尚有可供配置的空间），而是以原大小的两倍另外配置一块较大空间，然
		后将原内容拷贝过来，然后才开始在原内容之后建构新元素，并释放原空间。因
		此，对vector的任何操作，一旦引起空间重新配置，指向原vector的所有迭
		代器就都失效了。这是程序员易犯的一个错误，务需小心。                     */
	/************************************************************************/
	vector<int> vec_test;
	cout << "vector:" << sizeof(vec_test) << endl; // 12 bytes(32bits), 24 bytes(64bits) T* pb, T* pe, T* pc;

	/************************************************************************/
	/*3. list 底层数据结构为双向链表(double linked-list),支持快速增删      */
	/************************************************************************/
	list<int> list_test;
	cout << "list:" << sizeof(list_test) << endl;

	//4. forward_list 底层数据结构为单链表
	forward_list<int> forward_list_test;
	cout << "forward_list:" << sizeof(forward_list_test) << endl;

	//5. deque  vector是单向开口的连续线性空间，deque则是一种双向开口的连续线性空间。 
	// 底层数据结构为一个中央控制器和多个缓冲区，详细见STL源码剖析P146，支持首尾（中间不能）快速增删，也支持随机访问
	//  deque是一个双端队列(double - ended queue)，也是在堆中保存内容的.它的保存形式如下:
	//  [堆1] -- > [堆2] -- > [堆3] -- > ...
	//	每个堆保存好几个元素, 然后堆和堆之间有指针指向, 看起来像是list和vector的结合品.
	deque<int> deque_test;
	cout << "deque:" << sizeof(deque_test) << endl;

	//6. stack,底层一般用list或deque实现，封闭头部即可，不用vector的原因应该是容量大小有限制，扩容耗时
	stack<int> stack_test;
	cout << "stack:" << sizeof(stack_test) << endl;

	/************************************************************************/
	/*7. queue 底层一般用list或deque实现，封闭头部即可，不用vector的原因应该是容量大小有限制，扩容耗时
  	  (stack和queue其实是适配器,而不叫容器，因为是对容器的再封装）                */                                                         
	/************************************************************************/
	queue<int> queue_test;
	cout << "queue:" << sizeof(queue_test) << endl;

	/************************************************************************/
	/* 8. priority_queue的底层数据结构是heap, heap并不归属于STL容器组件，它是个幕后英雄，扮演priority queue的推手                                                                  
		binary max heap(complete binary tree) */
	/************************************************************************/
	priority_queue<int> pri_queue_test;
	cout << "priority_queue:" << sizeof(pri_queue_test) << endl;

	/************************************************************************/
	/* 9.  底层数据结构为红黑树，有序，不重复                                  */
	/************************************************************************/
	set<int> set_test;
	cout << "set:" << sizeof(set_test) << endl;

	/************************************************************************/
	/* 10.  底层数据结构为红黑树，有序，可重复                                  */
	/************************************************************************/
	multiset<int> multiset_test;
	cout << "multiset:" << sizeof(multiset_test) << endl;

	/************************************************************************/
	/* 11.底层数据结构为红黑树，有序，不重复                                   */
	/************************************************************************/
	map<int, int> map_test;
	cout << "map:" << sizeof(map_test) << endl;

	/************************************************************************/
	/* 12. 底层数据结构为红黑树，有序，可重复                                   */
	/************************************************************************/
	multimap<int, int> multimap_test;
	cout << "multimap:" << sizeof(multimap_test) << endl;

	/************************************************************************/
	/* 13. unordered_set 底层数据结构为hashtable,无序,不重复                  */
	/************************************************************************/
	unordered_set<int> unordered_set_test;
	cout << "unordered_set:" << sizeof(unordered_set_test) << endl;

	/************************************************************************/
	/* 14. unordered_multiset  底层数据结构为hashtable,无序,重复              */
	/************************************************************************/
	unordered_multiset<int> unordered_multiset_test;
	cout << "unordered_multiset_test:" << sizeof(unordered_multiset_test) << endl;

	/************************************************************************/
	/* 15. unordered_map底层数据结构为hashtable,无序，不重复                   */
	/************************************************************************/
	unordered_map<int, int> hash_test;
	cout << "unordered_map:" << sizeof(hash_test) << endl;

	/************************************************************************/
	/* 16. unordered_multimap   底层数据结构为hashtable,无序，重复             */
	/************************************************************************/
	unordered_multimap<int, int> unordered_multimap_test;
	cout << "unordered_multimap_test:" << sizeof(unordered_multimap_test) << endl;

	system("pause");
	return 0;
}


/************************************************************************/
/*Output:
array:4
vector:32
list:24
forward_list:16
deque:40
stack:40
queue:40
priority_queue:40
set:24
multiset:24
map:24
multimap:24
unordered_set:80
unordered_multiset_test:80
unordered_map:80
unordered_multimap_test:80
*/
/************************************************************************/