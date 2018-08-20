#include <iostream>
#include <string.h>

using namespace std;

int bit[20];
int dp[20][15][3];

int dfs(int pos,int mod13=0,int have13=0,bool ismax=true)
{
    if(pos==0)return mod13==0 && have13 == 2;
    if(!ismax && dp[pos][mod13][have13] != -1)return dp[pos][mod13][have13];
    int mx=ismax? bit[pos]:9;
    int ans=0;
    for(int i=0;i<=mx;++i)
    {
        int modx=(mod13*10+i)%13;
        int havex=have13;
        if(have13 == 0 && i == 1)havex=1;
        if(have13 == 1 && i != 1)havex=0;
        if(have13 == 1 && i == 3)havex=2;
        ans+=dfs(pos-1,modx,havex,ismax&&i==bit[pos]);
    }
    return ismax? ans:dp[pos][mod13][have13]=ans;
}

int sol(int x)
{
    memset(bit,0,sizeof(bit));
    int len=0;
    while(x)
    {
        bit[++len]=x%10;
        x/=10;
    }
    return dfs(len);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)
        cout<<sol(n)<<endl;
    return 0;
}