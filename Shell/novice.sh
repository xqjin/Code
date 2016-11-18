# awk 使用正则表达式过滤文本
#awk -F'\t' '/\\"answer\\":\\"\\"/{print $2}' restaurant_bot.log


if [ $1 -eq 1 ]
then
    echo $1
elif [ $1 -eq 2 ]
then
    echo $1
else
    echo $1
fi
