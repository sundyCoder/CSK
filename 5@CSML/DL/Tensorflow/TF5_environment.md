## Tensroflow 常用指令
1. 安装
	1. pip3 install tensorflow-gpu==1.41
2. 卸载
	1. pip3 uninstall tensorflow-gpu==1.41
3. 环境配置
	
	- 	export PATH=/usr/local/cuda-8.0/bin${PATH:+:${PATH}}
	- 	export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
	- 	export CUDA_DIR=/usr/local/cuda-8.0

4.配置jupyter可以远程访问
		
	1. 生成配置文件:  jupyter notebook --generate-config
	2. 生成密码:    'sha1:ce23d945972f:34769685a7ccd3d08c84a18c63968a41f1140274' 
	3. 修改默认配置文件: vim ~/.jupyter/jupyter_notebook_config.py 
		c.NotebookApp.ip='*'
		c.NotebookApp.password = u'sha:ce...刚才复制的那个密文'
		c.NotebookApp.open_browser = False
		c.NotebookApp.port =8888 #随便指定一个端口