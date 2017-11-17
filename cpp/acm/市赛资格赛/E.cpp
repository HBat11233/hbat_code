#include <iostream>
#include <vector>

using namespace std;

struct water
{
	int le;
	int v;
};

vector <water> num;

int q_sort(int l,int r)
{
	int be=num[(l+r)/2].v;
	int i=l;
	int j=r;
	while(i<=j)
	{
		while(num[i].v>be)++i;
		while(num[j].v<be)--j;
		if(i<=j)
		{
			if(i!=j)
			{
				num[i].le^=num[j].le;
				num[j].le^=num[i].le;
				num[i].le^=num[j].le;
				
				num[i].v^=num[j].v;
				num[j].v^=num[i].v;
				num[i].v^=num[j].v;
			}
			++i;
			--j;
		}
	}
	if(i<r)q_sort(i,r);
	if(l<j)q_sort(l,j);
	return 0;
}

int q_sortl(int l,int r)
{
	int be=num[(l+r)/2].le;
	int i=l;
	int j=r;
	while(i<=j)
	{
		while(num[i].le>be)++i;
		while(num[j].le<be)--j;
		if(i<=j)
		{
			if(i!=j)
			{
				num[i].le^=num[j].le;
				num[j].le^=num[i].le;
				num[i].le^=num[j].le;
			}
			++i;
			--j;
		}
	}
	if(i<r)q_sortl(i,r);
	if(l<j)q_sortl(l,j);
	return 0;
}

int main()
{
	int n;
	int sum=0;
	cin>>n;
	num.reserve(n);
	for(int i=0;i<n;++i)
	{
		cin>>num[i].le;
		sum+=num[i].le; 
	}
	for(int i=0;i<n;++i)
		cin>>num[i].v;
		
	q_sort(0,n-1);
	
	for(int j,i=0;i<n;i=j)
	{
		for(j=i+1;j<n;++j)
		{
			if(num[j].v==num[i].v)continue;
			else break;
		}
		if(j!=i+1)
			q_sortl(i,j-1);
	}
	
	int k=0;
	while(sum>0)
	{
		sum-=num[k].v;
		k++;
	}
	sum=0;
	
	for(int i=k;i<n;++i)
		sum+=num[i].le;
	cout<<k<<' '<<sum; 
	return 0;
}
