import matplotlib.pyplot as plt
list1 = [4793,10776,15302,6373]
list2 = [0,1]
for i in list1:
    plt.plot([0,16],[i,i],linewidth=1,c='grey')
for i in range(0,16):
    plt.plot([i,i],[0,16000],linewidth=1,c='grey')
li = [
    [0,1],
    [0,list1[0]]
]
for i in range(1,8):
    lia = list(li)
    lia[0][1]=i
    lia[1][1]=list1[0]
    lia[0][1]*=8
    lia[1][1]*=8
    plt.plot(lia[0],lia[1],linewidth=1,c='blue')
plt.xlabel('X', fontsize=16)
plt.ylabel('Y', fontsize=16)
#设置刻度数字的大小
plt.tick_params(axis='both', labelsize=10)
plt.show()