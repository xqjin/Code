hostName=`uname -n`
filePath=`pwd`
fileName=$1
echo "ftp://${hostName}${filePath}/${fileName}"
