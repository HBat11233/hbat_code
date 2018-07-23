#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

typedef struct Node
{
	int length;
	int weight;
	bool used;
    Node()
    :length(0),weight(0),used(0){}
}WOOD;

bool cmp(WOOD &a, WOOD &b)
{
	if(a.length==b.length)
		return a.weight<b.weight;
	else
		return a.length<b.length; 
}

int main()
{
<<<<<<< HEAD
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		WOOD a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].length,&a[i].weight);
			a[i].used=false;
	    }
		sort(a,a+n,cmp);
		//a[0].used=1;
		int count=0,pos=0;
		while(pos<n)  //pos表新的一组的第一根 
		{
			count++;
			a[pos].used=true;
			int flag=1;
			for(int i=pos+1;i<n;i++)  //i表示pos往后的每一根 
			{
				if(a[i].used==true)  //这根被用掉了 
					continue; 
				if(a[i].weight>=a[pos].weight)  //这根可以用 
					a[i].used=true;
				else  //这根不能用 
				{
					if(flag==1)
					{
						pos=i;  //记录第一个不能用的位置
						flag=0; 
					}
				}
			}
			if(flag==1)  //全都用掉了 
				break;
		}
		printf("%d\n",count);
	} 
	
	return 0;
=======
    freopen("1.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int ans=0;
        vector<int>arr;
        scanf("%d",&n);
        arr.resize(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        for(int i=0;i<n;++i)
        {
                int tnum=-1;
                for(int k=i;k<n;++k)
                {
                    tnum&=arr[k];
                    ans+=tnum;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
>>>>>>> 29e4a2b78c9d66d2216bedd4b82aacd759b79058
}