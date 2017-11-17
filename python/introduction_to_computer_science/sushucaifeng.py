sushu=[2,3,5]
for i in range(7,1000):
    j=0
    for j in range(2,i//2):
        if i%j==0:
            break;
    if j==i//2-1:
        sushu.append(i)

def fj(a):
    for i in sushu:
        if a-i in sushu:
            print(a,'=',i,'+',a-i)
            return
    return

print("Input number:")
num=int(input())
fj(num)
