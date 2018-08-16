import urllib.request
import userAgents
'''usrAgents.py是个自定义模块'''

class Urllib2ModifyHeader(object):
    '''使用Urllib2修改Header'''
    def __init__(self):
        #PC + IE 的 User-Agent
        PIUA = userAgents.pcUserAgent.get('IE 9.0')
        #Mobile + UC 的 User-Agent
        MUUA = userAgents.mobileUserAgent.get('UC standard')
        #测试用的网站选择是有道翻译
        self.url = 'http://fanyi.youdao.com'
        self.useUserAgent(PIUA,1)
        self.useUserAgent(MUUA,2)

    def useUserAgent(self,userAgent,name):
        request = urllib.request.Request(self.url)
        request.add_header(userAgent.split(':')[0],userAgent.split(':')[1])
        response = urllib.request.urlopen(request)
        content = response.read()
        data = content.decode('utf-8')
        fileName = str(name) + '.html'
        '''以二进制形式存储'''
        with open(fileName,'wb') as fp:
            fp.write(userAgent.encode())
            fp.write('\n\n'.encode())
            fp.write(content)

if __name__  == '__main__':
    umh = Urllib2ModifyHeader()
