def md(length,stun,clan,i):
    temp={}
    for j in range(length):
        num=int(input("Input %s's %s grade:"%(stun[i],clan[j])))
        temp.setdefault(clan[j],num)
    return temp
stunum=int(input("Input student number:"))
clanum=int(input("Input class number:"))
stuname=[]
claname=[]
map={}
for i in range(stunum):
    stuname.append(input("Input NO.%d student name:"%(i+1)))
for i in range(clanum):
    claname.append(input("Input NO.%d class name:"%(i+1)))
for i in range(stunum):
    map.setdefault(stuname[i],md(clanum,stuname,claname,i))
for i in range(stunum):
    print(stuname[i],"=",map[stuname[i]])
while(1):
    str_name=input("Input student name:")
    if(map.get(str_name,-1)==-1):
        print("Error!")
        continue
    templist=map[str_name].values()
    print("max score:%d min score:%d prv score%d"%(max(templist),min(templist),sum(templist)/clanum))