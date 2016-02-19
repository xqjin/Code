

function getProcessNum()
{
    local pNum=$(ps -few | grep $1 | grep -v "grep $1" | wc -l) 
    echo $pNum
}
