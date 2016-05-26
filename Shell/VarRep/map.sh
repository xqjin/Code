# This shell script can repalce the variable;
# Auther by jinxiaoqiang
# data: 2016-05-23

while read ori sub
do
    echo $ori
    echo $sub
    find include/ src -name "*.h" -o -name "*.cpp" | xargs sed -i "s/\<$ori\>/$sub/g"
done < map
