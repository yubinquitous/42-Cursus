#! /bin/bash

# update 
sudo apt-get update
sudo apt-get upgrade -y 

# k3s init
sudo apt-get install cgroup-bin
export INSTALL_K3S_EXEC="--write-kubeconfig-mode=644 --tls-san $(hostname) --node-ip 192.168.56.110 --bind-address 192.168.56.110  --advertise-address 192.168.56.110"
curl -sfL https://get.k3s.io | sh -
sudo chmod 644 /etc/rancher/k3s/k3s.yaml
sudo cp /etc/rancher/k3s/k3s.yaml /vagrant
sudo cp /var/lib/rancher/k3s/server/node-token /vagrant/
