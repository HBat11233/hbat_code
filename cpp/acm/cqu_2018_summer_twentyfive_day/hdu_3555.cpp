#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

ll n;
ll qei[30];
ll dp[30][2];  //dp[i][j],i位数，第i+1位为4或者不为4的时候，符合条件的个数
int bit[30];

ll dfs(int len,bool is4,bool ismax)
{
    if(len==0)return 0;
    if(!ismax && dp[len][is4]>=0)return dp[len][is4];

    ll ans=0;
    int mx=ismax? bit[len]:9;
    for(int i=0;i<=mx;++i)                          //i从0开始，以便计数从个位数到len位数。
    {
        if(is4 && i==9)ans += ismax? n%qei[len-1]+1:qei[len-1];
        else ans+=dfs(len-1,i==4,ismax&&i==bit[len]);
    }
    return ismax? ans:dp[len][is4]=ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    qei[0]=1;
    for(int i=1;i<30;++i)
        qei[i]=qei[i-1]*10;
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        int len=0;
        ll temp=n;
        while(temp)
        {
            bit[++len]=temp%10;
            temp/=10;
        }
        cout<<dfs(len,false,true)<<endl;
    }
    return 0;
}