#This is a function to get the program execute time
#Auther: jinxiaoqiang
#Date: 2016-04-27
#Version: 1.0

#arg1=start arg2=end, format: %s.%N
function getTiming() {
    start=$1
    end=$2

    start_s=$(echo $start | cut -d '.' -f 1)
    end_s=$(echo $end | cut -d '.' -f 1)

    end_ns=$(echo $end | cut -d '.' -f 2)
    start_ns=$(echo $start | cut -d '.' -f 2)

    time=$(( ( 10#$end_s - 10#$start_s ) * 1000 + ( 10#$end_ns / 1000000 - 10#$start_ns / 1000000 ) ))

    echo $time
}

# Here is a test case
#start=$(date +%s.%N)
#sleep 2
#end=$(date +%s.%N)
#
#elaps=`getTiming $start $end`
#echo $elaps
