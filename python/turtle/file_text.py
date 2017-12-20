f=open("input.txt","r")
ans=0
s=f.readline()
while (s):
    for i in range(0,256):
        if((i>=65 and i<=90)or(i>=97 and i<=122)):
            continue
        s=s.replace(chr(i),' ')
    t=s.split()
    ans+=len(t)
    s=f.readline()
f.close()
f=open("output.txt",'w')
print(ans)
f.close()
