n=int(input("请输入学生数："))
m=int(input("请输入课程数："))
name=[]                                           #定义列表，存储学生姓名
nam=[]                                             #学生姓名列表，做备份，因为之后又一个数组要变成字典存放成绩信息
sub=[]                                              #定义列表，存储课程名称
for i in range(m):                               #读入m门课程，并放到sub列表里
   print("请输入第%d门课程名字："%(i+1),end='')
   sub.append(input())
for i in range(n):                                #读入n位同学姓名，并存到name列表
   print("请输入第%d位学生名字："%(i+1),end='')
   name.append(input())
for i in range(n):                               #用笨办法备份name列表
   nam.append(name[i])
student={}                                        #定义大字典，存储每一个同学的信息
for i in range(n):
   name[i]={}                                     #将存储姓名的列表改为以当前同学名字为字典名字的小字典，存储成绩信息
   
   for j in range(m):
      x=int(input("请输入%s同学的%s成绩："%(nam[i],sub[j])))      #将成绩存到当前同学名字的小字典里
      while((x<0)or(x>100)):
         x=int(input("不合法,请重新输入："))      #判断输入成绩的合法性
      name[i][sub[j]]=x                        #在name[i]小字典里，存入属性sub[j]（即课程）的成绩x
   student[nam[i]]=name[i]               #在student大字典里，存入属性nam[i](即名字)的各类成绩name[i]
for i in range(n):
   print("%s"%(nam[i]),"=",student[nam[i]])        #输出每一位学生的成绩信息
x=input("请输入要查询的学生姓名：")
while (student.get(x,-1)==-1):          #判断合法性
   print("查询的学生不存在")
   x=input("请重新输入：")
l=[]
for e in student[x]:
   l.append(student[x][e])                    #将当前学生的信息里成绩存到列表中，便于访问数值
maxx=minn=l[0]
summ=0
for i in range(len(l)):                           #寻找最高分、最低分和平均分
   if (l[i]>maxx):
      maxx=l[i]
   if(l[i]<minn):
      minn=l[i]
   summ+=l[i]
summ=summ//m
print(student[x])
print("最高分为%d   最低分为%d   平均成绩为%d"%(maxx,minn,summ))  
      
