import requests
from bs4 import BeautifulSoup
import bs4

def findurl(urls):
    try:
        r = requests.get(urls,timeout = 5)
        r.raise_for_status();
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""

def fillunivlist(ulist,demo):
    soup = BeautifulSoup(demo,"html.parser")
    for tr in soup.tbody.children:
        if isinstance(tr,bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string,tds[1].string,tds[3].string])

def printful(ulist,num):
    print("{0:^10}\t{1:{3}^10}\t{2:^10}".format("排名","学校","总分",chr(12288)))
    for i in range(num):
        u = ulist[i]
        print("{0:^10}\t{1:{3}^10}\t{2:^10}\t".format(u[0],u[1],u[2],chr(12288)))

if __name__ == "__main__":
    ulist = []
    url = "http://www.zuihaodaxue.cn/zuihaodaxuepaiming2018.html"
    demo = findurl(url)
    fillunivlist(ulist,demo)
    printful(ulist,20)

