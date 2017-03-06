#Sundy
##Swig usage

参见官方[http://www.swig.org/tutorial.html](http://www.swig.org/tutorial.html)

##步骤总结(讲C++/C代码转化为Python接口):
###1.写代码(C++/C)
	
1. example.c

		#include <time.h>
		#include "Example.h"
		
		Example::Example() {
		
		}
		
		Example::~Example() {
		
		}
		
		int Example::fact(int n) {
			if (n <= 1) return 1;
			else return n*fact(n - 1);
		}
		
		int Example::my_mod(int x, int y) {
			return (x%y);
		}
		
		char *Example::get_time()
		{
			time_t ltime;
			time(&ltime);
			char str[26];
			ctime_s(str, sizeof str, &ltime);
			return str;
		}

2.Example.h

	#pragma once	
	class Example {
	public:
		Example();
		virtual ~Example();
	
		int fact(int n);
		int my_mod(int x, int y);
		char *get_time();
	};

###2.写接口文件
	 /* example.i */
	 %module example
	 %{
	 /* Put header files here or function declarations like below */
	#include "../SwigExample/inc/Example.h"
	 %}
	
	%include "../SwigExample/inc/Example.h"

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

###5. 上面涉及到的环境参数的配置.
####5.1.需要放出外部接口的工程
![](http://i.imgur.com/pAy7V4A.png)
![](http://i.imgur.com/vCknQKt.png)
####5.2.python接口工程
![](http://i.imgur.com/uqKAXGw.png)
![](http://i.imgur.com/ipKB4kj.png)
![](http://i.imgur.com/leBKQBC.png)
###5.3 接口文件example.i
![](http://i.imgur.com/faSrp6t.png)
![](http://i.imgur.com/6wzZv8P.png)
###5.4.生成example.py和example_wrap.cxx文件
![](http://i.imgur.com/TrUJR1x.png)
###5.5.生成_example.pyd文件
![](http://i.imgur.com/pYxH91X.png)
![](http://i.imgur.com/59zPmpM.png)
###5.6.工作目录及jupyter运行
![](http://i.imgur.com/RSTQWV7.png)
![](http://i.imgur.com/aRwWfpe.png)

