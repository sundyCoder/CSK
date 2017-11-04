#Sundy
##Swig usage

参见官方[http://www.swig.org/tutorial.html](http://www.swig.org/tutorial.html)

##步骤总结(讲C++/C代码转化为Python接口):
###1.写代码(C++/C)
Example:

	/* File : example.c */
	 
	 #include <time.h>
	 double My_variable = 3.0;
	 
	 int fact(int n) {
	     if (n <= 1) return 1;
	     else return n*fact(n-1);
	 }
	 
	 int my_mod(int x, int y) {
	     return (x%y);
	 }
	 	
	 char *get_time()
	 {
	     time_t ltime;
	     time(&ltime);
	     return ctime(&ltime);
	 }

在VS2015中配好环境:
![](http://i.imgur.com/zInFZm6.png)

![](http://i.imgur.com/89Ob6iR.png)

![](http://i.imgur.com/IcRsvTa.png)

###2.写接口文件
	/* example.i */
	 %module example
	 %{
	 /* Put header files here or function declarations like below */
	 extern double My_variable;
	 extern int fact(int n);
	 extern int my_mod(int x, int y);
	 extern char *get_time();
	 %}
	 
	 extern double My_variable;
	 extern int fact(int n);
	 extern int my_mod(int x, int y);
	 extern char *get_time();

###3.构建Python模块
	 swig -c++ -python example.i
会生成example.py,example_wrap.cxx这2个文件，然后编译example_wrap.cxx文件，就可以生成上面配置的_example.pyd文件，其实就是dll文件。

###4.在Python中使用example模块
将example.py和_example.pyd文件拷贝到python的工作目录下面，就可以使用C++提供的接口了。

	
	We can now use the Python module as follows :
	 >>> import example
	 >>> example.fact(5)
	 120
	 >>> example.my_mod(7,3)
	 1
	 >>> example.get_time()
	 'Sun Feb 11 23:01:07 1996'
	 >>>