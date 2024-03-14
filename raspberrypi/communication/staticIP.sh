# append these lines to the end of .bashrc
sudo nmcli c mod "preconfigured" ipv4.addresses 192.168.1.145/24 ipv4.method manual
sudo nmcli c down "preconfigured"
sudo nmcli c up "preconfigured"
