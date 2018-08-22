import urllib
from urllib.request import *
#打开网站
request=Request("http://www.baidu.com")
response=urlopen(request)#urlopen(url,data,headers) ,response = urlopen("http://www.baidu.com")
#print(response.read())
#print()
values = {"username":"eedsyz467","password":"888666wh"}
data = urllib.parse.urlencode(values)#.encode(encoding='UTF8')
url = "https://mail.126.com/"
geturl = url + "?" + data
#这是get打开，
#post是r
#data = urllib.parse.urlencode(values).encode(encoding="UTF8")
#reuest= Request(url,data)
request = Request(geturl)
response = urlopen(request) 
#print (response.read())

url = 'https://weibo.com/'
user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:57.0) Gecko/20100101 Firefox/57.0'
values = {'username':'15134948750','password':'1123376988w'}
headers = {"User-Agent":user_agent}
data = urllib.parse.urlencode(values).encode(encoding='UTF8')
request = Request(url,data,headers)
response = urlopen(request)
page = response.read()
print(page)