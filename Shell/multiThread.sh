#!/bin/bash

tmpfile=$$.fifo  #创建管道名称
mkfifo $tmpfile  #创建管道
exec 9<>$tmpfile #创建文件标识符, 用以读写方式操作管道$tmpfile
rm $tmpfile      #将创建的管道文件清除

thread=4         #设定可以并行的任务个数
seq=`seq 8`     #模拟显示中实际的任务个数,可以改变成从文件读取内容

#为并发线程创建相应个数的占位符
{
    for(( i=1; i<=$thread; i++ ))
    do
        echo;
    done
} >&9


function doSomething() {
    echo $1
    sleep 5
}

for id in $seq
do
    read
    ( doSomething $id || echo "error"; echo >&9 ) &
done <&9
wait             #等待所有的子线程执行完毕


for(( i=1; i<=$thread; i++ ))
do
    echo >&9
    echo $i >> input
    echo $i >> input
    echo $i >> input
    echo $i >> input
done


# 从文件中读取内容进行处理
while read line
do
    read -u 9
    {
        echo $line
        sleep 5
    }& 
    echo >&9
done < input
wait

exec 9>&-       #关闭管道
echo "finished"
