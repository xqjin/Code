#!/usr/bin/python
#coding:utf8

import requests
import sys

"""
requests.request(method, url, **kwargs) # basic method
# method: request method: get put head post patch delete
# url   : html page
# kwargs: 13 control parameters

# http request method
# requests.request("OPTIONS", url,**kwargs) # 获取与服务器打交道的方法
# requests.request("GET", url, **kwargs)
# requests.request("HEAD", url, **kwargs)
# requests.request("POST", url, **kwargs)
# requests.request("PUT" , url, **kwargs)  # 存储资源
# requests.request("PATCH", url, **kwargs)  # 资源局部更新
# requests.request("delete", url,**kwargs)  # 删除资源

# **kwargs 控制访问的参数， 均为可选项
# params: 字典或者字节序列， 作为参数增加到URl中
# data  : 字典，字节序或文件对象， 作为request的内容
# json  : Json格式的数据， 作为request的内容
# headers: 字典，HTTP定制头
# cookies: 字典或者CookieJar Request中的cookie
# auth   : 元组  支持HTTP认证功能
# files  : 字典类型  传输文件
# timeout: [num second]
# proxies: 字典类型， 设定访问代理服务器， 可以增加登录认证
# allow_redirects: True/False  default=True
# stream : True/False default=True 获取内容立即下载
# verify : True/False default True 认证SSl证书开关
# cert   : 本地SSL证书路径

requests.get(url, params=None, **kwargs) # kwargs 12 parameters
requests.head(url, **kwargs) 
requests.post(url, data=None, json=None, **kwargs) # kwargs 11 paratmers
requests.put(url, data=None, **kwargs)  
requests.patch(url, data=None, **kwargs)  
requests.delete(url, **kwargs) 
"""

"""
1. 爬虫的尺寸
1) 小规模: requests  网页级别   >90%
2) 中规模: Scrapy    网站级别
3) 大规模: nothing   整个互联网

2. 网络爬虫的限制
1) 网络审查,协议头
2) 发布公告: Robots协议 : 存放在网站根目录
2.1) 基本格式：
user-agent: agent # 限制的代理
disallow  : path  # 不允许爬取路径
2.2) 路径：网站根目录

"""
def getHtmlText(url):
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

def getHtmlDemo():
    try:
        """
        req = requests.head("https://www.baidu.com", timeout = 30)
        print req.headers
        print req.text
        """
        """
        # demo of post and data
        payload = {"key1":"value1", "key2":"value2"}  # key-value pair will be save in form data
        req = requests.post("http://httpbin.org/post", data = payload)
        print req.text
        req = requests.post("http://httpbin.org/post", data = "abcdef") # string will be save in data
        print req.text
        """
        
        """
        payload = {"key1":"value1", "key2":"value2"}  # key-value pair will be save in form data
        req = requests.put("http://httpbin.org/put", data = payload)
        print req.text
        """
        
        """
        kv = {"key1":"value1", "key2":"value2"}
        req = requests.request("GET", "http://python123.io/ws", params = kv)
        print req.url # http://python123.io/ws?key2=value2&key1=value1
        """

        """
        # demo of data : bad demo
        kv = {"key1":"value1", "key2":"value2"}
        req = requests.request("POST", "http://python123.io/ws", data = kv)
        print req.text
        body = "content"
        req = requests.request("POST", "http://python123.io/ws", data = body)
        print req.text
        """

        """
        # demo of json
        kv = {"key1":"value1", "key2":"value2"}
        #req = requests.request("POST", "http://python123.io/ws", json = kv)  #bad case
        req = requests.request("POST", "http://httpbin.org/post", json = kv)
        print req.text
        """

        """
        hd = {"user-agent":"Chrome/10"}
        req = requests.request("POST", "http://python123.io/ws", headers=hd)
        print req.headers
        """
        
        """
        fs = {"file": open('data.txt', 'r')}
        req = requests.request("POST", "http://python123.io/ws", files=fs)
        """

        pxs = {"http": "http://dev-proxy.oa.com:8080", "https": "https://dev-proxy.oa.com:8080"}
        req = requests.request("GET", "https://www.baidu.com", proxies = pxs)
        print req.headers
        print >> sys.stdout, "lec1"    
    except Exception, e:
        print >> sys.stderr, "sys.stderr: ", e

if __name__ == "__main__":
    #print getHtmlText("https://www.baidu.com")
    getHtmlDemo()

