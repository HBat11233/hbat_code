import math
sushu=[]
n=int(input("Input n:"))
if n>2:
    sushu.append(2)
    for i in range(3,n+1,2):
        ko=False
        for j in sushu:
            if j>int(math.sqrt(i)):
                break
            elif i%j==0:
                ko=True
                break
        if not ko:
            sushu.append(i)
elif n==2:
    sushu.append(2)
print('0-n sushu=',sushu)