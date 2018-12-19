# tensorflow environment 

## 0. install nvidia driver

    sudo service lightdm stop
    install nvidia driver
    sudo service lightdm start

## 1. install cuda

    export CUDA_HOME=/usr/local/cuda
    export PATH=$PATH:$CUDA_HOME/bin
    export LD_LIBRARY_PATH=/usr/local/cuda/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}

## 2. install cudnn

    sudo cp cuda/include/cudnn.h /usr/local/cuda/include/
    sudo cp cuda/lib64/libcudnn* /usr/local/cuda/lib64/
    sudo chmod a+r /usr/local/cuda/include/cudnn.h
    sudo chmod a+r /usr/local/cuda/lib64/libcudnn*

## 3. install python3.n 

    sudo apt-get install python3-pip python3-dev
  
## 4. install tensorflow
  
    pip3 install tensorflow-gpu

    //pip3 uninstall tensorflow-gpu
  
## 5. install jupyter notebook
  
    python3 -m pip install --upgrade pip
    python3 -m pip install jupyter  

## 6. config jupyter notebook remote access
  
  1. jupyter notebook --generate-config
  2. generate passwd
  
    In [1]: from IPython.lib import passwd

    In [2]: passwd()

    Enter password:

    Verify password:

    Out[2]: 'sha1:0e422dfccef2:84cfbcbb3ef95872fb8e23be3999c123f862d856'
   
   3. vim ~/.jupyter/jupyter_notebook_config.py
    c.NotebookApp.ip='*'

    c.NotebookApp.password = u'sha1:0e422dfccef2:84cfbcbb3ef95872fb8e23be3999c123f862d856' # 就是把引号里边的内容替换成刚才生成的密码

    c.NotebookApp.open_browser = False

    c.NotebookApp.port =8888 
