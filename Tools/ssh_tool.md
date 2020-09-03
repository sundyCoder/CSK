## 1. Frpc tools 
* A fast reverse proxy to help you expose a local server behind a NAT or firewall to the internet. (https://github.com/fatedier/frp)
### 1.1. Server
* Install openssh server: sudo apt-get install  openssh-server
* allow ssh:  sudo ufw allow ssh
* frpc config file:

  [common]
  
  bind_port = 11416

### 1.2. Client
* frpc config file:

  [common]
  
  server_addr = ServerIp (e.g. 101.101.101.2 (public cloud))
  
  server_port = 11416

  [ssh-2]
  
  type = tcp
  
  local_ip = 127.0.0.1
  
  local_port = 22
  
  remote_port = 6060

### 1.3 SSh connection

* ssh user@ServerIP -p 6060     (ssh connection)
* scp -P6060 user@ServerIP:/home/user/file.zip . (file download)
