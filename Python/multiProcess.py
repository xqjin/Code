# -*- coding:utf-8 -*-

from multiprocessing import Process,Pool
import os,time

def run_case(task):        ##定义一个函数用于进程调用
    task[100] = 100
    print "run_proc", id(task)

def run(task_name):        ##定义一个函数用于进程调用
    info = dict()
    info[task_name] = task_name
    return info

def demoA():
    print 'Run the main process (%s).' % (os.getpid())
    mainStart = time.time() #记录主进程开始的时间
    p = Pool(8)             #开辟进程池, 默认的进程个数为CPU的个数

    task_dict = dict()
    for index in range(1):                                  #开辟16个进程
        """
        每个进程都调用run_proc函数，args表示给该函数传递的参数;
        第一个参数是：函数的名字  而不是函数对象
        第二个参数args： 是一个列表， 所以如果是一个参数必须在列表中多加入一个逗号
        说明： 因为传入的args是一个列表， 如果参数是可变对象， 那么放入元祖对象的ID发生变化，函数内部修改对象不会影响外层的值
        如果需要每个进程写一个变量， 然后返回那么调用函数使用return即可
        """

        task = task_dict.setdefault(index, dict())
        print id(task)
        p.apply_async(run_case, args=(task,)) 

    print 'Waiting for all subprocesses done ...'
    p.close() #关闭进程池
    p.join()  #等待开辟的所有进程执行完后，主进程才继续往下执行
    print 'All subprocesses done'
    mainEnd = time.time()  #记录主进程结束时间
    print 'All process ran %0.2f seconds.' % (mainEnd-mainStart)  #主进程执行时间
    print task_dict

def demoB():
    print 'Run the main process (%s).' % (os.getpid())
    mainStart = time.time() #记录主进程开始的时间
    p = Pool(8)             #开辟进程池, 默认的进程个数为CPU的个数

    task_result = list()
    for index in range(16):                                  
        task_name = str(index)
        val = p.apply_async(run, args=(task_name,)) 
        task_result.append(val)

    print 'Waiting for all subprocesses done ...'
    p.close() #关闭进程池
    p.join()  #等待开辟的所有进程执行完后，主进程才继续往下执行

    for item in task_result:
        re_val = item.get()
        print re_val

    print 'All subprocesses done'
    mainEnd = time.time()  #记录主进程结束时间
    print 'All process ran %0.2f seconds.' % (mainEnd-mainStart)  #主进程执行时间

if __name__ =='__main__': #执行主进程
    demoB()



    

