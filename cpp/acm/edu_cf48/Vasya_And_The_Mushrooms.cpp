#include <bits/stdc++.h>

#define INF 300005

using namespace std;

long long maps[3][INF];
long long ans[INF];
long long ti[3][INF];
long long qa[3][INF],qb[3][INF];

int main()
{
    int n;
    scanf("%d",&n);
    vector<int>que;
    for(int i=1;i<=n;++i)
        scanf("%d",&maps[1][i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&maps[2][i]);
    for(int i=2;i<=n;++i)
        qa[1][i]=qa[1][i-1]+maps[1][i];
    qa[2][n]=qa[1][n]+maps[2][n];
    for(int i=n-1;i>=1;--i)
        qa[2][i]=qa[2][i+1]+maps[2][i];
    qb[2][1]=maps[2][1];
    for(int i=2;i<=n;++i)
        qb[2][i]=qb[2][i-1]+maps[2][i];
    qb[1][n]=qb[2][n]+maps[1][n];
    for(int i=n-1;i>1;--i)
        qb[1][i]=qb[1][i+1]+maps[1][i];
    long long t=0;
    for(int j=1;j<=n;++j)
    {
        if(1&j)
        {
            ti[1][j]+=maps[1][j]*(t++)+ti[1][j-1];
            ti[2][j]+=maps[2][j]*(t++)+ti[1][j];
        }else
        {
            ti[2][j]+=maps[2][j]*(t++)+ti[2][j-1];
            ti[1][j]+=maps[1][j]*(t++)+ti[2][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        long long t=(i-1)*2;
        ans[i]+=ti[1&i? 1:2][i-1];
        //printf("%d %d\n",t,ans[i]);
        if(i&1)
        {
            for(int j=i;j<=n;++j)
                ans[i]+=maps[1][j]*(t++);
            for(int j=n;j>=i;--j)
                ans[i]+=maps[2][j]*(t++);
        }else
        {
            for(int j=i;j<=n;++j)
                ans[i]+=maps[2][j]*(t++);
            for(int j=n;j>=i;--j)
                ans[i]+=maps[1][j]*(t++);
        }
    }
    long long out=-1;
    for(int i=1;i<=n;++i)
        out=max(out,ans[i]);
    printf("%d\n",out);
    return 0;
}
