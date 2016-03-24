hostName=`uname -n`
#hostName=`hostname`
filePath=`pwd`
fileName=$1
echo "ftp://${hostName}${filePath}/${fileName}"
