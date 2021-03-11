## install mate for ubuntu16.04
* sudo apt-get install aptitude
* sudo apt-get install ubuntu-mate-desktop


## uninstall mate 
* sudo apt-get purge $(dpkg --list | grep MATE | awk '{print $2}')


## 如何解决ubuntu侧边栏消失问题
* mv ~/.cache/compizconfig-1 ~/.cache/compizconfig-renamed
