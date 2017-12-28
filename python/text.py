import os
import re
with open('input.txt','r') as f:
#with open('input.txt','w')
    all_num={}
    for i in f.readlines():#f.readlines()读入全部数据，返回列表，列表中的每一个元素是一行字符串   ；  ； ；  如果用f.readline()，是读入一行字符串，所以列表中的美一个元素是字母
        listline=re.findall(r'[A-Za-z]+',i)#'[A-Za-z]'//匹配字母
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
