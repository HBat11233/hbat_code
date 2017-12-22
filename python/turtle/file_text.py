#f=open("input.txt","r")
#ans=0
#s=f.readline()
#while (s):
#    for i in range(0,256):
#        if((i>=65 and i<=90)or(i>=97 and i<=122)):
#            continue
#        s=s.replace(chr(i),' ')
#    t=s.split()
#    ans+=len(t)
#    s=f.readline()
#f.close()
#f=open("output.txt",'w')
#print(ans)
#f.close()
f=open("input.txt","r")
s=f.read()
for i in range(0,256):
    if((i>=65 and i<=90)or(i>=97 and i<=122)):
        continue
    s=s.replace(chr(i),' ')
t=s.split()
ansnum=len(t)
book={}
for i in t:
    if( book.get(i,False) ):
        book[i]+=1
    else:
        book[i]=1
f.close()
f=open("output.txt","w")
strs="word number is %d\n"%(ansnum)
f.write(strs)
t=book.keys()
for i in t:
    strss="%s have %d\n"%(i,book[i])
    f.write(strss)
f.close()