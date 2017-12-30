def sele_sort(l):#选择排序
    ip=0
    for i in range(0,len(l)):
        a=0x7fffffff
        for j in range(i,len(l)):
            if(l[j]<a):
                a=l[j]
                ip=j
        temp=l[i]
        l[i]=l[ip]
        l[ip]=temp

def find(x,l,b,e):#二分查找
    if(b==e):
        if(x==l[b]):
            return b
        else:
            return -1
    mid=int((b+e)/2)
    if(x<=l[mid]):
        return find(x,l,b,mid)
    else:
        return find(x,l,mid+1,e)

l=[]
print("输入列表长度：")
n=int(input())
print("输入列表内容：")
for i in range(0,n):
    a=int(input())
    l.append(a)
print(l)
sele_sort(l)
print("排序后：")
print(l)
while(True):
    print("输入查找数：")
    x=int(input())
    print(find(x,l,0,len(l)-1))