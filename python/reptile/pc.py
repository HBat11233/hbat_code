import requests
import re

url = "https://m.weibo.cn/api/comments/show?id=4177685162249811&page={}"

headers = {
    "Accept":"application/json, text/plain, */*",
    "Accept-Encoding":"application/json, text/plain, */*",
    "Accpet-Language":"zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2",
    "Cache-Control":"max-age=0",
    "Connection":"keep-alive",
    "Cookie":"_T_WM=64c997b89810b28d3065ae4a45061d27; M_WEIBOCN_PARAMS=oid%3D4177685162249811%26luicode%3D20000061%26lfid%3D4177685162249811%26uicode%3D20000061%26fid%3D4177685162249811; SUB=_2A253HLgbDeRhGeVH6FAS8C7NzT2IHXVU_thTrDV6PUJbkdANLRL6kW1NT0gizyFcafs-3vArWWJiu680La462CzI; SUHB=0QS56TThH7akv8; SCF=AvHB5PfioNtOhPcMaP9GmHJEa9IHuBEQt1gGREEgE3mSD7qrp6qy_UUZNi7PhcaMLd2m3_TmDpkgxw05hwdb-UE.; SSOLoginState=1511573579; H5:PWA:UID=1",
    "Host":"m.weibo.cn",
    "Referer":"https://m.weibo.cn/status/4177685162249811",
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; WOW64; rv:57.0) Gecko/20100101 Firefox/57.0",
    "X-Requested-With":"XMLHttpRequest"
}

i=1
while True:
    req = requests.get(url=url.format(i),headers=headers)
    content = req.json()
    data = content['data']
    print(content)
    i += 1
    for j in range(len(data)):
        comment = data[j]
        created_at = comment['created_at']
        source = comment['source']
        user_name=comment['user']['screen_name']
        comment_text=re.sub("<.,*?>","",comment['text'])
        print(source)
    i += 1