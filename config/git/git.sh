# config the global proxy of the tecent
# git config --global http.proxy http://web-proxy.oa.com:8080

# New ssh-figure

ssh-keygen -ras -C "jinxiaoqiang0608@gmail.com"

#input enter if need

ssh-add id_rsa


# if you need to proxy ; make config in the .ssh path 
# the content of the config is as fellowing:

Host *
  ProxyCommand connect-proxy -H proxy.xxxxxx.com:8080 %h %p
  protocol 2
  ServerAliveInterval 60
 
# something need to say:
1. if you need https repository, you must input user name and passwd each time you commit the code
2. do remember the code how you get: according to the https or ssh
