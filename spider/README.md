#Sundy
##Python Spider
###1. Using scrapy tools for website crawling.
####(1). Install scrapy tools

Scrapy由 Python 编写。如果您刚接触并且好奇这门语言的特性以及Scrapy的详情， 对于已经熟悉其他语言并且想快速学习Python的编程老手， 我们推荐 Learn Python The Hard Way ， 对于想从Python开始学习的编程新手， 非程序员的Python学习资料列表 将是您的选择。

Reference:[http://scrapy-chs.readthedocs.io/zh_CN/0.24/intro/tutorial.html](http://scrapy-chs.readthedocs.io/zh_CN/0.24/intro/tutorial.html)

	创建项目: scrapy startproject tutorial
	爬取:    scrapy crawl dmoz(dmoz为爬虫的名字)	
	保存爬取到的数据：  scrapy crawl dmoz -o items.json
	选择器(Selector): CSS Selector, XPath Selector


Example1: [http://blog.csdn.net/xiaoquantouer/article/details/51840332](http://blog.csdn.net/xiaoquantouer/article/details/51840332)

	code: [https://github.com/xiaoquantou/jd_spider](https://github.com/xiaoquantou/jd_spider)

(2)数据的持久化

可以将爬到的数据存储到MySQL数据库， 复习一下简单的数据库的操作

  (1)创建数据库 

	(CREATE DATABASE TUTORIALS)

  (2)创建数据库表 

	(CREATE TABLE table_name (column_name column_type);)

   删除数据表：DROP TABLE table_name ;

  (3)增加一条记录到数据库 

	INSERT INTO table_name ( field1, field2,...fieldN )
                       VALUES
                       ( value1, value2,...valueN );

  (4)删除数据库中的所有记录

    truncate table table_name

  (5)修改数据库中的一条记录

    UPDATE table_name SET field1=new-value1, field2=new-value2
	[WHERE Clause]

  (6)数据库表数据的查询

    SELECT field1, field2,...fieldN table_name1, table_name2...
	[WHERE Clause]
	[OFFSET M ][LIMIT N]

  (7)