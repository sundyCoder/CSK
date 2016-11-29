#![](http://i.imgur.com/S7xBFja.png)Sundy#
---
##Git 常用命令和方法##
###1.长期保存密码###
  git config --global credential.helper store
  
###2.删除远程bin目录###
	git rm -r -n --cached  ./bin/\*
	git rm -r --cached  ./bin/\*
	git commit -a
	git push  

###3.提交分支###
	git add .
    git commit -a
    git push

###4.克隆单个分支 ###
	git clone -b https://github.com/sundyCoder/branch-name

###5.恢复到历史某个提交###
	git reset xxxx(版本号)
    git checkout *

###6.合并某个分支到主分支###
	git merge branch-name
    也可以采用手动用beyond compare进行合并

###7.git submodule
[http://www.kafeitu.me/git/2012/03/27/git-submodule.html](http://www.kafeitu.me/git/2012/03/27/git-submodule.html)

###8.为自己的版本库配置credential
	$ git config credential.helper store
	$ git push http://example.com/repo.git
	Username: <type your username>
	Password: <type your password>
	
	[several days later]
	$ git push http://example.com/repo.git
	[your credentials are used automatically]

###9.更改远程url
	git remote set-url origin xxx.git

#![](http://i.imgur.com/S7xBFja.png)微信公众号#
![wechat](http://i.imgur.com/1TDj1p7.jpg)

