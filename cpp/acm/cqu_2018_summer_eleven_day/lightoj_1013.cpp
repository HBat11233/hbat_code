#include <bits/stdc++.h>

using namespace std;

int dp[35][35];
long long ans[35][35][70];

int main()
{
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        string str1,str2;
        cin>>str1>>str2;
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<str2.size();++i)
            dp[0][i]= str1[0]==str2[i]? 1:0;
        for(int i=0;i<str1.size();++i)
            dp[i][0]= str1[i]==str2[0]? 1:0;
        for(int i=1;i<str1.size();++i)
            for(int j=1;j<str2.size();++j)
                if(str1[i]==str2[j])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        int len=str1.size()+str2.size()-dp[str1.size()-1][str2.size()-1];
        ans[0][0][0]=1;
        for(int i=1;i<=len;++i)
            for(int j=1;j<=str1.size();++j)
                for(int k=1;k<=str2.size();++k)
                    if(ans[i-1][j-1][k-1])
                    {
                        if(str1[j-1]==str2[k-1])ans[i][j][k]+=ans[i-1][j-1][k-1];
                        else
                        {
                            ans[i][j][k-1]+=ans[i-1][j-1][k-1];
                            ans[i][j-1][k]+=ans[i-1][j-1][k-1];
                        }
                    }
        printf("Case %d: %d %lld\n",o,len,ans[len][str1.size()][str2.size()]);
    }
    return 0;
}