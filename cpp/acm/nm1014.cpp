#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX(a,b,c,e,d,f,g) max(a,max(b,max(c,max(d,max(e,max(f,g))))))
#define _INF -0x7fffffff

using namespace std;

int dp[105][105][105];
int que[105];
int n;

int t;

int main()
{
	cin>>t;
	while(t--)
	{
		int a,b;
		memset(dp,0,sizeof(dp));
		memset(que,0,sizeof(que));
		scanf("%d%d%d",&a,&b,&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&que[i]);
		for(int i=0;i<=a;++i)
		for(int j=0;j<=b;++j)
			dp[0][i][j]=100;
		int t=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			int c=t;
			for(int j=0;j<=a;++j)
			{
				for(int k=0;k<=b;++k)
				{
					//状态转移
					dp[i][j][k]=MAX(
						dp[i-1][j][k]-que[i],																		//不用药
						(j>0&&dp[i-1][j-1][k]>0&&dp[i-1][j-1][k]<70)? 70-que[i]:_INF,								//在前一个状态存在且>0&&<70成立的条件下，用一个急救包
						(dp[i-1][j-1][k-1]>0&&j>0&&k>0&&dp[i-1][j-1][k-1]<70)? 100-que[i]:_INF,						//在前一个状态存在且>0&&<70成立的条件下，用一个急救包和饮料
						(k>0&&dp[i-1][j][k-1]>0)? (dp[i-1][j][k-1]>70? 100-que[i]:dp[i-1][j][k-1]+30-que[i]):_INF,  //在前一个状态存在且>0成立的条件下，用一个饮料
						(k>1&&dp[i-1][j][k-2]>0)? (dp[i-1][j][k-2]>40? 100-que[i]:dp[i-1][j][k-2]+60-que[i]):_INF,  //在前一个状态存在且>0成立的条件下，用两个个饮料
						(k>2&&dp[i-1][j][k-3]>0)? (dp[i-1][j][k-3]>10? 100-que[i]:dp[i-1][j][k-3]+90-que[i]):_INF,  //在前一个状态存在且>0成立的条件下，用三个个饮料
						(k>3&&dp[i-1][j][k-4]>0)? (100-que[i]):_INF													//在前一个状态存在且>0成立的条件下，用四个个饮料
					);																						        //返回所有转移中最大的值
					//状态转移，生命值大于0就++
					//若在当前i下，所有状态都没大于0，则t==c,此处死亡,break出去
					if(dp[i][j][k]>0)t++;
				}
			}
			if(c!=t)ans=max(ans,i);//有活着的情况，记录受弹数
			else break;
		}
		cout<<ans<<endl;
	}
	return 0;
}