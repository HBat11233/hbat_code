import re
import urllib.request

class TodayMoive(object):
    '''获取金逸影院当日影视'''#网站过期
    def __init__(self):
        self.url = 'https://www.toutiao.com/a6589513280434209284/'
        self.timeout = 5
        self.fileName = './todayMoive.txt'
        '''内部变量定义完毕'''
        self.getMoiveInfo()

    def getMoiveInfo(self):
        response = urllib.request.urlopen(url=self.url,timeout = self.timeout)
        stri= response.read().decode('gbk')
        moiveList = re.findall('film-title.*',stri)
        with open(self.fileName,'w') as fp:
            fp.write(stri)
            for moive in moiveList:
                moive = self.subStr(moive)
                print(moive.decode('utf-8'))
                fp.write(moive + '\n')
        
    def subStr(self,st):
        st = st.replace('film-title">','')
        st = st.replace('</h3>','')
        return st

if __name__ == '__main__':
    tm = TodayMoive()