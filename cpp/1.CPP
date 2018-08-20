#include <iostream>
#include <cstring>

using namespace std;

int dp[20];

int dfs(int pos,int pre,bool limit,int *a/*每一位上限*/)
{
    if(pos==-1)return 1;
    int cnt=0;
    if( !limit && pre!=6 && dp[pos]!=-1)return dp[pos];
    int up= limit? a[pos]:9;
    for(int i=0;i<=up;++i)
    {
        if(i==4)continue;
        if(pre==6&&i==2)continue;
        cnt+=dfs(pos-1,i,limit && i==a[pos],a);
    }
    if(!limit && pre!=6  )dp[pos]=cnt;
    return cnt;
}

inline int sov(int x)
{
    memset(dp,-1,sizeof(dp));
    int a[20];
    memset(a,0,sizeof(a));
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos,true,true,a);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        cout<<sov(m)-sov(n-1)<<endl;
    }
    return 0;
}