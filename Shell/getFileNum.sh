
function getFileNum()
{
    local num=$(cat $1 | wc -l | bc)
    echo $num
}


getFileNum $1
