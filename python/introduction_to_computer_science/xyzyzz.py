def xyz(x,y,z):
    return x*100+y*10+z

def yzz(y,z):
    return y*100+z*10+z

for i in range(10):
    for j in range(10):
        for k in range(10):
            if xyz(i,j,k)+yzz(j,k)==532:
                print("x =",i," y =",j," z =",k)