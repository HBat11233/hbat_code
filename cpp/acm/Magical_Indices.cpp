#include <bits/stdc++.h>
#define INF 1000005

using namespace std;

struct sat
{
    int num;
    int pos;
    bool operator <(const sat &b)
    {
        if(this->num==b.num)
        return this->pos<b.pos;
        return this->num<b.num;
    }
}arr[INF];
int snm[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        memset(snm,0,sizeof(snm));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i].num);
            arr[i].pos=i;
        }
        sort(arr,arr+n);
        snm[0]=arr[0].pos;
        n--;
        for(int i=1;i<n;++i)
        {
            int temp=arr[i].pos-i;
            if(temp==0&&snm[i-1]==0)ans++;
            snm[i]=snm[i-1]+temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;

typedef struct node
{
	int number;
	int pos1;
	int minus;
}NODE;

bool cmp(NODE a, NODE b)
{
	if(a.number==b.number)
		return a.pos1<b.pos1;
	else
		return a.number<b.number;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		NODE a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i].number);
			a[i].pos1=i;
		}
		sort(a,a+n,cmp);
		int count=0,flag=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			a[i].minus=a[i].pos1-i;
			sum+=a[i].minus;
			if(i>0&&i<n-1&&a[i].pos1==i&&sum==0)
				count++;
		}
		printf("%d\n",count);
	}
	
	return 0;
}

*/