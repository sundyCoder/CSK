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

#![](http://i.imgur.com/S7xBFja.png)微信公众号#
![wechat](http://i.imgur.com/1TDj1p7.jpg)