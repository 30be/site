cd /home/lyka/Code/Site/
rsync -avz --exclude='.git/' --delete ../Site root@23.94.5.170:/root
ssh root@23.94.5.170 'cd /root/Site/ && ./serve.sh' > /dev/null &
