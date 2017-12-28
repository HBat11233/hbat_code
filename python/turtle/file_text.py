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
    strss="ans: %20s have %3d\n"%(i,book[i])
    f.write(strss)
f.close()