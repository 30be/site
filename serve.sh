#!/bin/sh
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm
killall node
ln -s /home/shared/shared/ /root/Site/public/shared
node server/app.js &
