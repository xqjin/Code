#!/usr/bin/python

import os
import sys
import commands


def function1(command):
    re_num = os.system(command)
    return re_num

def function2(command):
    re_val = os.popen(command)

def function3(command):
    (status, output) = commands.getstatusoutput(command)
    print status, output

if __name__ == "__main__":
    command = "ls | wc -l"
    #function1(command)
    function2(command)
    #function3(command)


