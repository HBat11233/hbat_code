def md(length,stun,clan,i):  #因为字典传递的是地址，所以用函数建立新空间
    temp={}
    for j in range(length):
        while(True):         #判断输入成绩是否正确
            num=int(input("Input %s's %s grade:"%(stun[i],clan[j])))
            if(num<0 or num>100):
                print("error\n")
            else:
                break
        temp.setdefault(clan[j],num)
    return temp
stunum=int(input("Input student number:"))  #学生人数
clanum=int(input("Input class number:"))    #科目数
stuname=[]                                  #学生名字
claname=[]                                  #科目名字
map={}                                      #成绩单
for i in range(stunum):                     #输入姓名
    stuname.append(input("Input NO.%d student name:"%(i+1)))
for i in range(clanum):                     #输入科目
    claname.append(input("Input NO.%d class name:"%(i+1)))
for i in range(stunum):                     #输入成绩
    map.setdefault(stuname[i],md(clanum,stuname,claname,i))
for i in range(stunum):                     #输出成绩单
    print(stuname[i],"=",map[stuname[i]])
while(1):                                   #查询
    str_name=input("Input student name:")
    if(map.get(str_name,-1)==-1):
        print("Error!")
        continue
    templist=map[str_name].values()
    print("max score:%d min score:%d prv score%d"%(max(templist),min(templist),sum(templist)/clanum))