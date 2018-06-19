#include <bits/stdc++.h>

using namespace std;

#define INF 100005 
#define MOD 1000000007
int ans[10005][10005];

int js(int n,int m)
{
    if(n==0||m==0)return 0;
    if(m==1)return 1;
    if(n<10000&&m<10000&&~ans[n][m])return ans[n][m];
    else 
    {
        if(n<10000&&m<10000)
        {
            if(n==m)ans[n][m]=(js(n,m-1)+1)% MOD;
            else if(n<m)ans[n][m]=js(n,n) % MOD;
            else ans[n][m]=(js(n,m-1)+js(n-m,m)) % MOD;
            return ans[n][m];
        }else
        {
            if(n==m)return (js(n,m-1)+1)% MOD;
            else if(n<m)return js(n,n) % MOD;
            else return (js(n,m-1)+js(n-m,m)) % MOD;
        }
    }
}

int main()
{
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<10000;++i)
        ans[0][i]=ans[i][0]=0;
    for(int i=1;i<10000;++i)
        ans[1][i]=ans[i][1]=1;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%d\n",js(n,n)-js(n,k)+js(n,k-1));
    }

    return 0;
}