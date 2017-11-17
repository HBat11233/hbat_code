while 1:
    a=input("***输入exit退出***\n请输入成绩：")
    if a=="exit":
        exit(0)
    a=float(a)
    if a>100:
        print("请重新输入成绩！")
    elif a>=85:
        print('您的成绩为：A')
    elif a>=75:
        print('您的成绩为：B')
    elif a>=60:   
        print('您的成绩为：C')
    elif a>=0:
        print('您的成绩为：D')
    else:
        print("请重新输入成绩！")


