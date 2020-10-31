## 1. Install docker on ubuntu16.04

First, in order to ensure the downloads are valid, add the GPG key for the official Docker repository to your system:
* curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
* sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
* sudo apt-get update
* apt-cache policy docker-ce
* sudo apt-get install -y docker-ce
* sudo systemctl status docker


## 2. Executing the Docker Command Without Sudo (Optional)
* sudo usermod -aG docker ${USER}
* su - ${USER}
* id -nG
* sudo usermod -aG docker username


## 3.  Using the Docker Command
* docker [option] [command] [arguments]
* docker

To view system-wide information about Docker, use:

* docker info

## 4. Working with Docker Images

To check whether you can access and download images from Docker Hub, type:
* docker run hello-world
* docker search ubuntu
* docker pull ubuntu
* docker run ubuntu
* docker rmi ubuntu ( remove ubuntu image)

To see the images that have been downloaded to your computer, type:
* docker images

## 5.  Running a Docker Container
* docker run -it ubuntu

Install some software in the container:
* apt-get update
* apt-get install -y nodejs

To exit the container, type exit at the prompt.
## 5. Managing Docker Containers
* docker ps
* docker ps -l
* docker ps -a
* docker start 9b0db8a30ad1 
* docker stop container_name
* docker rm container_name

## 6. Committing Changes in a Container to a Docker Image
When you start up a Docker image, you can create, modify, and delete files just like you can with a virtual machine. 
The changes that you make will only apply to that container. You can start and stop it, but once you destroy it with the docker rm command, the changes will be lost for good.

* docker commit -m "What did you do to the image" -a "Author Name" container-id repository/new_image_name
* e.g.: docker commit -m "added node.js" -a "sammy" d9b100f2f636 sammy/ubuntu-nodejs
* docker images


## 7. Reference
* https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-16-04






