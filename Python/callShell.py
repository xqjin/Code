#!/usr/bin/python

import os
import sys
import commands


def function1():
    re_num = os.system('ls')
    return re_num
def function2():
    re_val = os.popen('ls -a')

def function3():
    (status, output) = commands.getstatusoutput("ls")
    print status, output
    


if __name__ == "__main__":
    #function1()
    #function2()
    function3()


