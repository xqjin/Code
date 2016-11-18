# find $2 in $1's path 
# the file must be *.py or *.sh


function find_it() {
    find $1 -type f -name "*.py" -o -name "*.sh" | xargs -i sh -c '[ `grep $0 {}| wc -l` -gt 0 ] && echo {}' $2
}


