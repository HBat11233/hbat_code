import os
import re
with open('input.txt','r') as f:
#with open('input.txt','w')
    all_num={}
    for i in f.readlines():
        listline=re.findall(r'[A-Za-z]+',i)
        print(listline)
        for word in listline:
            word_count=len(re.findall(word,i))
            all_num[word]=all_num.get(word,0)+ word_count
all_words=sorted(all_num.items(),key=lambda d: d[1], reverse=True)
for each in all_words:  
    print(each)
with open('output.txt', 'w') as fp:
    for each in all_words:  
        fp.writelines(str(each)+"\n")
