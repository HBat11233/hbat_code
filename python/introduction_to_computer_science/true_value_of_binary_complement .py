a=[0,0,0,0,0,0,0,0]
b=int(input())
for i in range(0,8):
    a[7-i]=b%10
    b//=10
if a[0]==1:
    for i in range(1,8):
        if a[i]==1:
            a[i]=0
        else:
            a[i]=1
    k=1
    for i in range(0,8):
        if k==1:
            if a[7-i]==1:
                a[7-i]=0;
            else:
                a[7-i]=1
                k=0
        else:
            break
c=0
for i in range(0,7):
    c+=a[7-i]*2**i
if a[0]==1:
    c*=-1
print(c)
