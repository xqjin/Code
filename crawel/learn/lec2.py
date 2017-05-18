#!/usr/bin/python
#coding:utf8

import requests
import sys
from bs4 import BeautifulSoup

"""
bs4 是解析  遍历 维护 “表签树” 的功能库

HTML --  标签树  ----  BeautifulSoup

parser:  
1)
pip install beautifulsoup4
bs4的HTML解析器   
BeautifulSoup(content, 'html.parser')  

2)
pip install lxml
lxml的HTML解析器   
BeautifulSoup(content, 'lxml')  

3) 
pip install lxml
lxml的xml解析器
BeautifulSoup(content, 'xml')  

4) 
pip install html5lib
html5lib的解析器
BeautifulSoup(content, 'html5lib')  

bs4 的基本元素
<tag_name tag_attribute="value">content</tag_name>
1) tag   <> .. </>  soup.tag  返回第一个命名为tag的标签
2) name  tag.name ==> tag_name
3) attributes  tag.attrs ==> tag_attribute
4) navigableString:  标签内非属性字符串 tag.string ==> content
5) comment : 标签内字符串的注释部分 tag.string

bs4 的遍历

# down travle
.contents  子节点列表， 将<tag>所有的儿子节点存入列表
.children  子节点的迭代类型， 与.contents类似， 用于循环便利儿子节点
.descendants  子孙节点的迭代类型， 包含所有的子孙节点， 用于循环遍历


# up travel
.parent   父节点
.parents  父辈节点， 所有的父辈节点


# horritial travel
# 不保证所有的元素为tag类型
.next_sibling   下一个平行元素
.next_siblings  迭代类型， 返回后续所有的平行元素

.previous_sibling  上一个平行元素
.previous_siblings 迭代类型， 返回前面所有的平行元素

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
        demo = rep.text
        soup = BeautifulSoup(demo, 'html.parser')

        """
        print soup.prettify()
        print soup.title
        tag = soup.a
        print "a's name: ", tag.name
        print "a's parent's name: ", tag.parent.name
        print "a's parent's parent's name: ", tag.parent.parent.name
        print "a's attri:", tag.attrs            # dict
        print "a's attri's class: ", tag.attrs["class"] 
        print "a's string: ", tag.string
        """
        
        soup = BeautifulSoup("<b><!--jinxiaoqinag--></b><p>xxhh</p>", 'html.parser')
        tag = soup.b
        print "b's comment: ", tag.string
        tag = soup.p
        print "p's comment: ", tag.string

        """
        print soup.prettify()
        tag = soup.head
        print tag.contents
        
        tag = soup.body
        print tag.contents
        """
        
        """
        for parent in soup.a.parents:
            if parent is None:
                print parent
            else:
                print parent.name
        """
        
        """
        print soup.prettify()
        print soup.a.next_sibling  # 字符串类型
        print soup.a.next_sibling.next_sibling 
        print "-----------"
        print soup.a.previous_sibling
        print soup.a.previous_sibling.previous_sibling
        print "-----------"
        for silbing in soup.a.next_siblings:
            print silbing
        print "-----------"
        for silbing in soup.a.previous_siblings:
            print silbing
        """
        
    except Exception, e:
        print >> sys.stderr, e


if __name__ == "__main__":
    getHtmlText("http://python123.io/ws/demo.html")

"""
<html>
 <head>
  <title>
   This is a python demo page
  </title>
 </head>
 <body>
  <p class="title">
   <b>
    The demo python introduces several python courses.
   </b>
  </p>
  <p class="course">
   Python is a wonderful general-purpose programming language. You can learn Python from novice to professional by tracking the following courses:
   <a class="py1" href="http://www.icourse163.org/course/BIT-268001" id="link1">
    Basic Python
   </a>
   and
   <a class="py2" href="http://www.icourse163.org/course/BIT-1001870001" id="link2">
    Advanced Python
   </a>
   .
  </p>
 </body>
</html>
"""
