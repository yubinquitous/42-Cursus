#! /bin/bash

sudo apt-get update
sudo apt-get upgrade -y

# k3s init in agent
sudo apt-get install cgroup-bin
export INSTALL_K3S_EXEC="agent --server https://192.168.56.110:6443 --token-file /vagrant/node-token --node-ip 192.168.56.111"
mkdir -p $HOME/.kube
curl -sfL https://get.k3s.io | sh - 
