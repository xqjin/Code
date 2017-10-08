function parseArg()
{
    while getopts "a:b:c:d" opt
    do
        case $opt in
            a) echo $OPTARG $OPTIND;;
            b) echo $OPTARG $OPTIND;;
            c) echo $OPTARG $OPTIND;;
            d) echo $OPTARG $OPTIND;;
            *) echo "error";;
        esac
    done
    shift $(($OPTIND-1))
    echo $*
    echo $#
}

parseArg $*
