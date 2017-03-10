#!/bin/bash

# method-1
while read line
do
    echo $line
done < tmp


# method-2
cat tmp | while read line
do
    echo $line
done

# method-3
for line in `cat tmp`
do
    echo $line
done

# method-4
OIFS=$IFS
IFS=$'\n'
for line in `<tmp`
do
    echo $line
done
IFS=$OIFS


#
#  method-1,2  line seperate
#  method-3,4  blank seperate, but can special the seperate
#
#
