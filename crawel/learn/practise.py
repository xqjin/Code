#!/usr/bin/python
#coding:utf8

import requests
import sys

def getHtmlText01(url):
    try:
        rep = requests.get(url, timeout = 30)
        """
        print rep.status_code
        print rep.encoding
        print rep.apparent_encoding
        rep.encoding = rep.apparent_encoding
        print rep.text
        """
        rep.raise_for_status()   # if the status_code != 200, exception will be arise httperror
        rep.encoding = rep.apparent_encoding
        return rep.text
    except Exception, e:
        print >> sys.stderr, e

def getHtmlText02(url):
    try:
        kv = {"user-agent":"Mozilla/5.0"}  #有些网站禁止爬虫
        rep = requests.get(url, headers = kv, timeout = 30)
        """
        print rep.status_code
        print rep.encoding
        print rep.apparent_encoding
        rep.encoding = rep.apparent_encoding
        print rep.text
        """
        rep.raise_for_status()   # if the status_code != 200, exception will be arise httperror
        rep.encoding = rep.apparent_encoding
        return rep.text
    except Exception, e:
        print >> sys.stderr, e

def getHtmlText03(url):
    try:
        kv = {"user-agent":"Mozilla/5.0"} 
        pkv = {"wd":"python"}
        rep = requests.get(url, headers = kv, params = pkv, timeout = 30)
        """
        print rep.status_code
        print rep.encoding
        print rep.apparent_encoding
        rep.encoding = rep.apparent_encoding
        print rep.text
        """
        rep.raise_for_status()   # if the status_code != 200, exception will be arise httperror
        rep.encoding = rep.apparent_encoding
        print rep.request.url
        return rep.text
    except Exception, e:
        print >> sys.stderr, e

def getHtmlText04(url, path):
    try:
        kv = {"user-agent":"Mozilla/5.0"} 
        rep = requests.get(url, headers = kv, timeout = 30)
        rep.raise_for_status()   # if the status_code != 200, exception will be arise httperror
        with open(path, 'wb') as fw:
            fw.write(rep.content)  # url's content in binary format
            fw.close()
    except Exception, e:
        print >> sys.stderr, e

if __name__ == "__main__":
    #print getHtmlText01("https://item.jd.com/2538439.html")  # success
    #print getHtmlText02("https://www.amazon.cn/gp/product/B01M8L5Z3Y")
    #print getHtmlText03("http://www.baidu.com/s")
    #getHtmlText04("http://image.nationalgeographic.com.cn/2017/0330/20170330050301973.jpg", "demo.jpg")



