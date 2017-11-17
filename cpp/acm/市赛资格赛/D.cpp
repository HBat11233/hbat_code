#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define C2(b) (b*(b-1)/2)

using namespace std;

typedef long long int LONG;

map <LONG,LONG>bk;
vector <LONG> que;

int main()
{
	LONG n;
	LONG x,y;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		if(!bk.count(x-y))que.push_back(x-y);
		if(!bk.count(x+y))que.push_back(x+y);
		bk[x-y]++;
		bk[x+y]++;
	}
	LONG ans=0;
	for(int i=0;i<que.size();i++)
		ans+=C2(bk[que[i]]);
	cout<<ans;
	return 0;
} 
