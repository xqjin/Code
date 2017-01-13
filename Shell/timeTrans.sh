#!/usr/bin/sh

function transTime()
{
    input=$1
    date_str=${input%_pbshow*}
    date_format=$(echo $date_str | awk -F '_' '{ printf("%s-%s-%s %s:%s:00",$1,$2,$3,$4,$5)}')
    seconds=`date -d "$date_format" +%s`
    echo $seconds
}


a=$(transTime 2017_01_09_00_10_pbshow..c5fc628aae4959a2bda174c414ae6941.base64)
b=$(transTime 2017_01_09_00_11_pbshow..c5fc628aae4959a2bda174c414ae6941.base64)

echo $a
echo $b
