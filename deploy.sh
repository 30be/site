cd /home/lyka/Code/Site/

npx quartz build
rsync -avzc --exclude='.git/' --delete ../Site root@23.94.5.170:/root
ssh root@23.94.5.170 'cd /root/Site/ && ./serve.sh' &
