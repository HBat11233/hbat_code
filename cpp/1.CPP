//uva_1597
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<sstream>
#include<array>
#include<bits/stdc++.h>
using namespace std; 

int N,M,lines;  //N是文章总数，M是请求总数, lines是总行数 

string doc[1505];  //存放文章原始内容,doc[i]是第i行的内容 

int ar[105];  //存每篇文章开始的行（最多100篇，数组开大点） , ar[i]是第i篇文章开始的那行  

struct mod
{
	int pos=0;
	map<string,int>in1;
	map<int,bool>que[2000];
	map<int,bool>& operator [](const string &str)
	{
		if(!in1.count(str))
		{
			in1[str]=pos;
			pos++;
		}
		else
			return que[in1[str]];
		return que[pos-1];
	}
	bool count(const string &str)
	{
		return in1.count(str);
	}
}indexs; //对于每个单词而言，存它的出现情况

int main()
{
    freopen("2.txt","r",stdin);
    freopen("1.txt","w",stdout);
//存文章	
	scanf("%d",&N); 
    getchar();
	lines=0;
	int i;
	for(i=0;i<N;i++)
	{
		ar[i]=lines;
		while(getline(cin,doc[lines])&&doc[lines]!="**********")  //一行一行存文章
		{
           // cout<<doc[lines];
			string term;
			term=doc[lines];
			for(string::iterator p=term.begin();p!=term.end();p++)
				if(isalpha(*p))
					*p=tolower(*p);                                //改小写 
				else
					*p=' ';
			string temp;
			stringstream ss(term);
			while(ss>>temp)
				indexs[temp][lines]=true;     //记录每个单词出现的行数 
			
			lines++;
		}	
	}
	ar[i]=lines;   //记录最后一篇文章的最后一行+1行（整个文档的最后一行） 

//对应请求，查找内容
	scanf("%d",&M);	
    getchar();
	bool mark[1505];   //记录某行是否要打印 
	bool art[105];   //记录某篇文章是否要打印 
	
	while(M--)
	{
		memset(mark,false,sizeof(mark));
		memset(art,false,sizeof(art));
		string req,arg[4];
		getline(cin,req);    //读取每次的请求
		int count1=0,count2=0,count=0,flag=0;
		int odf=0;
		stringstream  ss1(req);
        int sdf=1;
        while(ss1>>arg[sdf])
			sdf++;
		sdf--;
		
		if(sdf==3&&arg[2]=="AND")
		{
			if(indexs.count(arg[1])&&indexs.count(arg[3]))  //这两个词都在总文章中出现过 
			{
				for(int i=0;i<N;i++)   //每篇文章中再筛选
				{
					for(int j=ar[i];j<ar[i+1];j++)    //每一行查完 
					{
						if(indexs[arg[1]][j])
						{
							count1++;
							mark[j]=true;
						}
						if(indexs[arg[3]][j])
						{
							count2++;
							mark[j]=true;
						}	
					}
					
					if(count1&&count2)  //同时存在 
					{
						count++;
						art[i]=true;
					}
                    count1=0;
                    count2=0;
				}
				if(count==0)
					printf("Sorry, I found nothing.\n"); 
				else
					for(int i=0;i<N;i++)
						if(art[i])
						{
							odf++; 
							for(int j=ar[i];j<ar[i+1];j++)
								if(mark[j])
									cout<<doc[j]<<endl;
							if(odf!=count)
								printf("----------\n");
						}
			}
			else                         //这两个词没有都在文章中出现过 
				printf("Sorry, I found nothing.\n"); 
		}
		else if(sdf==3&&arg[2]=="OR")
		{
			if(indexs.count(arg[1])||indexs.count(arg[3]))
			{
				for(int i=0;i<N;i++)   //每篇文章中再筛选
				{
					for(int j=ar[i];j<ar[i+1];j++)  //每行筛选 
						if(indexs[arg[1]][j]||indexs[arg[3]][j])   //符合条件 
						{
							art[i]=true;    //这篇文章要 
							mark[j]=true;  //这行要 
							flag=1;
						}
					if(flag==1)
						count++;
                    flag=0;
				}
				for(int i=0;i<N;i++)   
					if(art[i])
					{
						odf++;
						for(int j=ar[i];j<ar[i+1];j++)
							if(mark[j])
								cout<<doc[j]<<endl;
						if(odf!=count)
							printf("----------\n");
					}
			}
			else           //这两个词都没有在文章中出现过 
				printf("Sorry, I found nothing.\n"); 
		}
		else if(sdf==2&&arg[1]=="NOT")
		{
			if(indexs.count(arg[2]))
            {
                int k;
                for(k=0;k<N;k++)
                {
                    for(int j=ar[k];j<ar[k+1];j++)
                        if(indexs[arg[2]][j])
                        {
                            flag=1;
                            break;
                        }
                    if(flag==0)   //这篇文章中没有这个词 
                    {
                        count++;
                        art[k]=true;
                    }
                    flag=0;
                }
                if(count==0)
                    printf("Sorry, I found nothing.\n"); 
                else
                    for(int i=0;i<N;i++)
                        if(art[i])
                        {
                            odf++;
                            for(int j=ar[i];j<ar[i+1];j++)
                                cout<<doc[j]<<endl;
                            if(odf!=count)
                            printf("----------\n");
                        }
            }
            else
			{
				for(int i=0;i<N;i++)
				{
					for(int j=ar[i];j<ar[i+1];j++)
						cout<<doc[j]<<endl;
					if(i!=N-1)
						printf("----------\n");
				}
			}
		}
		else if(sdf==1)  //只给了一个要查询的单词 
		{
			if(indexs.count(arg[1]))
			{
				for(int i=0;i<N;i++)
				{
					for(int j=ar[i];j<ar[i+1];j++)
						if(indexs[arg[1]][j])
						{
							art[i]=true;
							mark[j]=true;
							flag=1;
						}
					if(flag==1)
						count++;
                    flag=0;
				}
				for(int i=0;i<N;i++)
					if(art[i])
					{
						odf++;
						for(int j=ar[i];j<ar[i+1];j++)
							if(mark[j])
								cout<<doc[j]<<endl;
						if(odf!=count)
							printf("----------\n");
					}
			}
			else
				printf("Sorry, I found nothing.\n"); 
		}
		
		
		printf("==========\n");                 //一个请求结束 
	}
	
	
	
	
	
	
	return 0;
} 

