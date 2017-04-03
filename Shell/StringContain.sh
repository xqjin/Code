#!/usr/bin/sh

whole="jinxiaoqiang"
part="jin"

[[ $whole =~ $part ]]  && echo "yes1"

[ -n `echo $whole | grep $part` ] && echo "yes2"

[ $whole == *${part}* ] && echo "yes3"

[ ${whole/$part/} != $whole ] && echo "yes4"
