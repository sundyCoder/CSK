
1. sudo vim /etc/mysql/mysql.conf.d/mysqld.cnf
    注释掉 bind-address = 127.0.0.1
2. mysql -u root -p
3. user mysql 
   GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'lens' WITH GRANT OPTION;
   flush privileges;
4. sudo /etc/init.d/mysql restart


2. lavalite
	git clone git@github.com:LavaLite/cms.git
	composer install
	composer create-project LavaLite/cms --prefer-dist website
	vim .env
	sudo apt-get install php libapache2-mod-php
	npm install
	gulp all
	
   php artisan config:clear 
   //配置数据库
   php artisan lavalite:install 
   //部署
   php artisan serve   

   user: sundycoder@gmail.com
   passwd: lam@lens
   
  
   php artisan key:generate
   php artisan config:cache

   php artisan optimize --force
   php artisan config:cache
   php artisan route:cache
   composer dump-autoload



a. php artisan vendor:publish
b. php artisan migrate
c. composer dump-autoload
d. 开始填充数据
	php artisan db:seed
	
e.  填充指定的数据
	php artisan db:seed --class=你要执行的类名称