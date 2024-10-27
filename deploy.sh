commit_date=$(date +"%Y-%m-%d %H:%M:%S")

cd /home/lyka/Code/Site/

npx quartz build

git add -A
git commit -m "Commit made on $commit_date"
git push

ssh root@23.94.5.170 'cd /root/Site/ && git pull && serve.sh'

