# This shell script can repalce the variable;
# Auther by jinxiaoqiang
# data: 2016-05-23

while read ori sub
do
    echo $ori $sub
    files=`find include/ src/ -name "*.h" -o -name "*.cpp"`
    for file in $files
    do
        python sub.py $ori $sub $file
    done

    #just for english
    find include/ src/ -name "*.h" -o -name "*.cpp" | xargs sed -i "s/\<$ori\>/$sub/g"
done < map
