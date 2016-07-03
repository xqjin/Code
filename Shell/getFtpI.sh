hostName=`uname -n`
#hostName=`hostname`
curPath=`pwd`

fileName=`basename $1`
filePath=`dirname $1`
cd $filePath
ftpPath=`pwd`
cd $curPath
echo "ftp://${hostName}${ftpPath}/${fileName}"
