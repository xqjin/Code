# config the global proxy of the tecent
# git config --global http.proxy http://web-proxy.oa.com:8080

# New ssh-figure
if [ ! -f ~/.ssh/id_rsa ]
then
    # generate a new ssh-key and add it to ssh-agent
    ssh-keygen -t rsa -b 4096 -C "mail@qq.com"
    #input enter if need
    eval "$(ssh-agent -s)"
    ssh-add ~/.ssh/id_rsa
fi

# add the id_rsa.pub to github configure

# test the connect
ssh -T git@github.com

# if you need to proxy ; make config in the .ssh path 
# the content of the config is as fellowing:

Host *
  ProxyCommand connect-proxy -H proxy.xxxxxx.com:8080 %h %p
  protocol 2
  ServerAliveInterval 60


# 
 
# something need to say:
1. if you need https repository, you must input user name and passwd each time you commit the code
2. do remember the code how you get: according to the https or ssh
3. github config
    git config --global user.email "410272505@qq.com"
    git config --global user.name "justinxqjin"
