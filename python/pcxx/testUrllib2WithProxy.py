#! python3
import urllib.request
import sys
import re

def testArgument():
    '''测试输入参数，只需要一个参数'''
    #argu = u'http://36.7.172.18:82'
    if(False and len(sys.argv) !=2):
        print(u'只需要一个参数就够了')
        tipUse()
        exit()
    else:
        TP = TestProxy(sys.argv[1])#TestProxy(argu)

def tipUse():
    '''显示提示信息'''
    print(u'该程序只能输入一个参数，这个参数必须是一个可用的proxy')
    print(u'usage: python testUrllib2WithProxy.py http://1.2.3.4:5')
    print(u'usage: python testUrllib2WithProxy.py https://1.2.3.4:5')

class TestProxy(object):
    '''这个类的作用是测试proxy是否有效'''
    def __init__(self,proxy):
        self.proxy = proxy
        self.checkProxyFromat(self.proxy)
        self.url = 'http://www.baidu.com'
        self.timeout = 5
        self.flagWord = '百度' #在网页的返回数据中查找这个关键词
        self.useProxy(self.proxy)
    
    def checkProxyFromat(self,proxy):
        try:
            proxyMatch = re.compile('http[s]?://[\d]{1,3}\.[\d]{1,3}\.[\d]{1,3}\.[\d]{1,3}:[\d]{1,5}$')
            re.search(proxyMatch,proxy).group()
        except AttributeError:
            print(1)
            tipUse()
            exit()
        flag = 1
        proxy =proxy.replace('//','')
        try:
            protocol = proxy.split(':')[0]
            ip = proxy.split(':')[1]
            port = proxy.split(':')[2]
        except IndexError:
            print(u'数组下标出界')
            tipUse()
            exit()
        flag = flag and len(proxy.split(':')) == 3 and len(ip.split('.')) ==4
        flag = ip.split('.')[0] in map(str,range(1,256)) and flag
        flag = ip.split('.')[1] in map(str,range(256)) and flag
        flag = ip.split('.')[2] in map(str,range(256)) and flag
        flag = ip.split('.')[3] in map(str,range(1,255)) and flag
        flag = protocol in [u'http',u'https'] and flag
        flag = port in map(str,range(1,65535)) and flag
        '''这里是检查 proxy 的格式'''
        if(flag):
            print(u'输入的http代理服务器符合标准')
        else:
            tipUse()
            exit()

    def useProxy(self,proxy):
        '''利用代理服务器访问百度，并查找关键字'''
        protocol = proxy.split('//')[0].replace(':','')
        ip = proxy.split('//')[1]
        opener = urllib.request.build_opener(urllib.request.ProxyHandler({protocol:ip}))
        urllib.request.install_opener(opener)
        try:
            response = urllib.request.urlopen(self.url,timeout=self.timeout)
        except urllib.request.URLError:
            print(u'连接错误，退出程序')
            exit()
        strs = str(response.read())
        if(re.search(self.flagWord,strs)):
            print(u'已取得特征词，该代理可用')
        else:
            print(u'该代理不可用')

if __name__ == '__main__':
    testArgument()
