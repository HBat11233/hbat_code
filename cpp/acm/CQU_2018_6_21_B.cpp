//树状数组
#include <bits/stdc++.h>

using namespace std;

typedef struct Binary_Indexed_Tree
{
	int arr[100005];
	int len;
	void init()
	{
		memset(arr,0,sizeof(arr));
	}
	void add(int i,int x)
	{
		for(;i<=len;i+=(i&-i))
			arr[i]+=x;
	}
	int put(int i)
	{
		int ans=0;
		for(;i>0;i-=(i&-i))
			ans+=arr[i];
		return ans;
	}
}BIT;

int main()
{
	BIT a;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a.len);
		int n;
		scanf("\nSweet 1\n%d",&n);
		a.init();
		for(int i=0;i<n;++i)
		{
			int s,b,c;
			scanf("%d%d%d",&s,&b,&c);
			if(s) printf("%d\n",a.put(c)-a.put(b-1));
			else a.add(b,c);
		}
		scanf("\nSweet 2\n%d",&n);
		a.init();
		for(int i=0;i<n;++i)
		{
			int s;
			scanf("%d",&s);
			if(s)
			{
				int b;
				scanf("%d",&b);
				printf("%d\n",a.put(b));
			}else
			{
				int b,c,d;
				scanf("%d%d%d",&b,&c,&d);
				a.add(b,d);
				a.add(c+1,-d);
			}
		}
	}

	return 0;
}