#!/bin/bash

GET_CHAR()
{
  SAVEDSTTY=`stty -g`
  stty -echo
  stty raw
  dd if=/dev/tty bs=1 count=1 2> /dev/null
  stty -raw
  stty echo
  stty $SAVEDSTTY
}

SSSH_HOME=/home/admin/sssh
if [ -z $1 ];then
  echo -n "请输入要登陆的机器IP/域名： "
  read target
else
  target=$1
fi
target=".*$target.* .*"
AUTHFILE=$SSSH_HOME/ssh-passwd.conf
count=`grep "$target" $AUTHFILE -c`
targetfullname=`grep "$target" $AUTHFILE | awk '{print $1}'`
passwd=`grep "$target" $AUTHFILE | awk '{print $2}' | awk -F ':' '{print $2}'`
user=`grep "$target" $AUTHFILE | awk '{print $2}' | awk -F ':' '{print $1}'`
encoding=`grep "$target" $AUTHFILE | awk '{print $3}'`
if [ $count -gt 1 ];then
  echo -e '查找到以下主机 (\033[0;31msit\033[0m)'
  arrtarget=($targetfullname)
  arruser=($user)
  arrpasswd=($passwd)
  arrencoding=($encoding)
  length=${#arrtarget[@]}
  for ((i=0; i<$length; i++))
  do
    echo -e '[\033[4;34m'$(($i+1))'\033[0m]' ${arruser[$i]}@${arrtarget[$i]}
  done
  echo -n "选择序号："
  choice=`GET_CHAR`
  echo ""
  targetfullname=${arrtarget[$(($choice-1))]}
  passwd=${arrpasswd[$(($choice-1))]}
  user=${arruser[$(($choice-1))]}
  encoding=${arrencoding[$(($choice-1))]}
fi

if [ -z $targetfullname ] || [ -z $passwd ] || [ -z $user ];then
  echo "配置文件中没有查找到匹配的信息";
  exit 1;
fi
if [ -z $encoding ];then
  encoding=GB18030
fi
target=$targetfullname
$SSSH_HOME/ssh-expect.sh $user $target $passwd $encoding
