#include <bits/stdc++.h>

#define INF 1005

using namespace std;

int dp[INF];
string str;

bool ispp(int l,int r)
{
    while(str[l]==str[r]&&l<=r)
    {
        l++;
        r--;
    }
    if(l>r)return true;
    else return false;
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        
        cin>>str;
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=1;i<str.size();++i)
        {
            int temp=INF;
            for(int j=0;j<=i;++j)
            {
                if(ispp(j,i))
                {
                    temp=min(temp,dp[j]+1);
                }
            }
            dp[i+1]=temp;
        }
        printf("Case %d: %d\n",o,dp[str.size()]);
    }
    return 0;
}