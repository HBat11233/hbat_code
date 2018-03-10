#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>arrque;
int da[100001];
bool das[100001];
int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&da[i]);
	for(int i=1;i<=n;++i)
	{
		int tem=0;
		if(!das[i])
		{
			int a=i;
			das[i]=true;
			tem=1;
			while(da[a]!=i)
			{
				tem++;
				a=da[a];
				das[a]=true;
			}
			arrque.push_back(tem);
		}
	}
	int minans=0,maxans=0;
	int tempk=k;
	sort(arrque.begin(),arrque.end());
	for(int i=0;i<arrque.size()&&tempk;++i)
	{
		 if(arrque[i]<=tempk)
		 {
			minans+=arrque[i];
			tempk-=arrque[i];
		 }else
		 {
			 minans+=tempk+1;
			 break;  
		 }
	}
	int jishu=0;
	tempk=k;
	for(int i=arrque.size()-1;i>=0&&tempk;--i)
	{
		if(arrque[i]%2==1)
		{
			if(arrque[i]/2<=tempk)
			{
				tempk-=arrque[i]/2;
				maxans+=arrque[i]-1;
				jishu++;
			}else
			{
				maxans+=tempk*2;
				tempk=0;
				break;
			}
		}else
		{
			if(arrque[i]/2<=tempk)
			{
				tempk-=arrque[i]/2;
				maxans+=arrque[i];
			}else
			{
				maxans+=tempk*2;
				tempk=0;
				break;
			}
		}
	}
	if(tempk>=jishu)maxans+=jishu;
	else maxans+=tempk;
	cout<<minans<<' '<<maxans<<endl;
	return 0;
}