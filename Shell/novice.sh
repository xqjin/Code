
# awk 使用正则表达式过滤文本
awk -F'\t' '/\\"answer\\":\\"\\"/{print $2}' restaurant_bot.log
