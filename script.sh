BLUE='\033[0;36m'
NC='\033[0m'

printf "${BLUE}----------------------> INSTALAR DOCKER <----------------------${NC}\n"
printf "${BLUE}Eliminar instalaciones anteriores con :${NC}\n"
sudo apt-get remove docker docker-engine docker.io
printf "${BLUE}Actualizar :${NC}\n"
sudo apt-get update
sudo apt-get upgrade
printf "${BLUE}Instalaciones previas :${NC}\n"
sudo apt-get install apt-transport-https ca-certificates curl software-properties-common
printf "${BLUE}Instalo claves necesarias :${NC}\n"
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88
printf "${BLUE}Abro fichero :${NC}\n"
sudo gedit /etc/apt/sources.list.d/docker.list
Dentro del fichero escribo: deb https://apt.dockerproject.org/repo ubuntu-xenial main
printf "${BLUE}Actualizo :${NC}\n"
sudo apt-get update
printf "${BLUE}Instalo Dockers :${NC}\n"
sudo apt-get install docker.io
sudo systemctl restart docker
printf "${BLUE}Creación de un usuario :${NC}\n"
sudo usermod -a -G docker valentina
newgrp docker
printf "${BLUE}Instalar un contenedor :${NC}\n"
docker search centos
printf "${BLUE}Agregar imagen (tutorial) :${NC}\n"
docker pull ubuntu:14.04
printf "${BLUE}Listar imagenes :${NC}\n"
docker images
printf "${BLUE}Salir del contenedor :${NC}\n"
exit
printf "${BLUE}Versión docker :${NC}\n" 
docker --version
printf "${BLUE}----------------------> INSTALAR DOCKER COMPOSE <----------------------${NC}\n"
printf "${BLUE}Descargar :${NC}\n"
sudo curl -L "https://github.com/docker/compose/releases/download/1.23.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
printf "${BLUE}Verificar version de docker compose :${NC}\n"
docker-compose --version
