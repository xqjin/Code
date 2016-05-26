#coding=gbk
import sys
import re
import os

if len(sys.argv) < 4:
    print >> sys.stderr, "python %s ori sub inputName" %sys.argv[0]
    exit(-1)
else:
    ori = sys.argv[1]
    rep = sys.argv[2]
    ori = ori.decode("gb18030", "ignore")
    reg_ori = ur"(?<=[^\u4e00-\u9fa5])%s(?=[^\u4e00-\u9fa5])" %ori

    inputName = sys.argv[3]
    fr = open(inputName, "r")
    fw = open(inputName + ".tmp", "w")
    for line in fr:
        line = line.decode("gb18030", "ignore")
        line = line.strip("\r\n")
        line = re.sub(reg_ori, rep, line)
        print >> fw, line.encode("gb18030", "ignore")
    else:
        os.system("mv %s %s" %(inputName + ".tmp", inputName))
    fr.close()
    fw.close()
