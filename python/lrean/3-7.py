liat=['夏敏','丽丽','杰克','HBat','阿尔纳','维纳斯']
for i in liat:
    print("来我家吃饭把"+i+'\n')
notliat=["杰克","阿尔纳"]
for i in notliat:
    print(i+"有事不能来\n")
liat[2]="盖亚"
liat[4]="艾瑞克"
for i in liat:
    print("来我家吃饭把"+i+'\n')
print("我又一个新的桌子\n")
liat.insert(0,"哈迪斯")
liat.insert(len(liat)//2,"克拉克")
liat.append("布鲁斯")
for i in liat:
    print("来我家吃饭把"+i+'\n')
print("因为桌子到不了，所有只能来两个人\n")
while(len(liat)!=2):
    strs=liat.pop(len(liat)//2)
    print("我很抱歉"+strs+"你可能不能来了")
for i in liat:
    print(i+"希望你可以来")
del liat[0]
del liat[0]
print(liat)