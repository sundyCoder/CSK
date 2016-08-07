#Sundy
##C++学习总结week08

###一 STL(STL(standard template library))：标准模板库

常用容器的类的使用例程:http://www.cplusplus.com/

1 C++由什么组成:C(70%)+OOP(20%)+STL(10%)

2 STL：惠普(HP)做的,送给了C++

	   组成部分:
		(1)容器(模板类) vector list set   (java中叫集合)：序列式，关联式
		(2)算法(模板函数) find search swap order:排序，查找
		(3)迭代器(智能指针)iterator 

 3 迭代器是容器类的内部类

###二 序列式容器(用数组 或者 链表实现) 

1 vector:用动态数组实现的

	  (1) size();容器实际的大小   （为其中存放的元素的个数，不是sizeof每个元素之和）
 	  (2) capacity();最大的容量
    	  (3) sizeof(vector<T>)的大小永远为12，因为它里面有三个成员数据:T *pb;T* pe;T* pc;
	  (4) [] VS  at():at()更安全，可以抛出out of rage异常,访问更安全。

 2 list(双向链表)：多用于频繁的插入和删除时。
 
 3 deque(双端队列)：vector的子类，但是可以从对头和队尾进行操作。

 4 适配器:用标准的容器作为基础，然后创建新的容器。


###三 关联式容器(是用树来实现的:二叉搜索树，红黑树)
	  1 map()      映射
	  2 mutimap()  多映射(和map的唯一区别就是它的键值允许重复)
	  3 set()      数据集
	  4 mutiset()  多数据集


###四  常用数据结构的实现
	  链表
	  栈
	  队列
	  搜索二叉树
	  哈希表


###总结： 
1 指针也可以加引用  Node*& tree = root; (tree是指针类型的引用)
    int& i = j;
	int*& k = &i;

2 引用不能引用NULL


###作业: 
1 分别用C和C++,随机生成10个不重复的0~100之间的整数。
	srand(); //做个种子
	rand()%10;  //生成一个整数

	分析:rand（）是0-32767随机数rand（）%100是对其求余比如1297 和11297 都是97
	不过概率比较小 srand（time（0））是以时间作为种子来产生随机数 

	C++中可以用set(集合的互异性)
详见专题8-1-随机数的产生

2 自己写vector,list, map,set

3 用栈实现队列


