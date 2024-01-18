#! /bin/bash

sudo apt-get update
sudo apt-get upgrade -y 

sudo apt-get install net-tools -y 

# docker install
sudo apt-get install apt-transport-https ca-certificates curl gnupg-agent software-properties-common -y 
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io -y
sudo chmod 666 /var/run/docker.sock
#sudo usermod -aG docker $USER

# k3d install
curl -s https://raw.githubusercontent.com/k3d-io/k3d/main/install.sh | bash

# k3d cluster  create
k3d cluster create joowparkNode --agents 1 -p "8081:80@loadbalancer" --wait

#kubectl install
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"
curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl.sha256"
echo "$(cat kubectl.sha256)  kubectl" | sha256sum --check
chmod +x kubectl
sudo mv ./kubectl /usr/local/bin
export KUBECONFIG=$(k3d kubeconfig write joowparkNode)


#helm-chart install 
curl -fsSL -o get_helm.sh https://raw.githubusercontent.com/helm/helm/main/scripts/get-helm-3
chmod 700 get_helm.sh
./get_helm.sh

## generate namespace
kubectl create namespace argocd
kubectl create namespace dev

##argoCD intall
kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml
kubectl wait --for=condition=Ready pods --all -n argocd

echo "For get argoCD admin Password ENTER : "
echo "kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d"
echo "kubectl port-forward --address=0.0.0.0 svc/argocd-server -n argocd 8080:443 2>&1 & "

rm get_helm.sh
rm kubectl.sha256 

echo "export KUBECONFIG=$(k3d kubeconfig write joowparkNode)" >> /home/vagrant/.bashrc
source /home/vagrant/.bashrc

kubectl apply -f ../argoCD
kubectl wait --for=condition=Ready pods --all -n dev
