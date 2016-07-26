# paste [-s] [-d <separetor>] [--help]
# -s:  col-contate
# example
paste -d '*' 1.txt 2.txt > res.txt

# output the hostname of the server
hostname 

# show the IP of the host
host hostname 

# here document
(
cat << EOF
"content we want to write to output_file"
EOF
) >> output_file

# how to judge the condition
# if the condition is ture, echo yes
[ condition ] && echo yes 
test condition && echo yes 

# replace the string
old_string="old_jinxiaoqiang_old"
new_string=${old_string/old/new} //replace the first old
new_string=${old_string//old/new} //replace all the old

# string cut
string="jinxiaoqiang"
new_string=${string:begin:end} # string[begin:end) begin = 0,1,2..

# cut the path of the file
basename dirname # get filename or directory name

# string delete
${string#pattern}
${string##pattern}

${string%pattern}
${string%%pattern}
