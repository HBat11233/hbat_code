from pybdgeo import BaiduGEO

"""
申请ak和sk网址：http://lbsyun.baidu.com/apiconsole/key/update?app-id=10601098
当然你也可是使用博主的，不过每天大概是6k次上限。
自己申请很快的，五分钟...

Apply baidu ak and sk URL: http://lbsyun.baidu.com/apiconsole/key/update?App-id=10601098
Of course, you can use bloggers', but the daily limit is about 6k times.
Apply for it quickly, five minutes ...
"""
ak = 'l6jsgxmG2EKIG6Om4kih7Tu9VjLTUIWB'
sk = '5C06x25Tm9etBO2qX76FgmjS6ZERqlpz'

bdgeo = BaiduGEO(ak, sk)

print("==========test for get_longitude_latitude==========")
address = '深圳弘法寺'
res = bdgeo.get_longitude_latitude(address)
pprint.pprint(res)

print("==========test for get_address==========")
longitude = 114.1879
latitude = 22.5836
res2 = bdgeo.get_address(longitude, latitude)
pprint.pprint(res2)