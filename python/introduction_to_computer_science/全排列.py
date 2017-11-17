bo=[1>2]*5
ans=[0,0,0,0,0]
length=0

def n(num):
    global bo
    global ans
    global length
    if num==5:
        anum=0
        length+=1
        for i in range(4):
            anum*=10
            anum+=ans[i+1]
        print(anum);
    for i in range(1,5):
        if not bo[i]:
            bo[i]= not bo[i]
            ans[num]=i
            n(num+1)#递归
            bo[i]= not bo[i]
            ans[num]=0
    return

n(1)
print (length)
