## install mate for ubuntu16.04
* sudo apt-get install aptitude
* sudo apt-get install ubuntu-mate-desktop


## uninstall mate 
* sudo apt-get purge $(dpkg --list | grep MATE | awk '{print $2}')
