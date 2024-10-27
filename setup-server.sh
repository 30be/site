ssh-keygen -t rsa -b 4096
ssh-copy-id root@23.94.5.170
ssh root@23.94.5.170 << 'EOF'
mkdir -p /root/Site
cd /root/Site
git clone https://github.com/30be/site.git
git pull
echo "Update complete"
EOF

