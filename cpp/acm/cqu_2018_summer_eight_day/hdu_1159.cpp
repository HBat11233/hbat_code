#include <iostream>
#include <cstdio>
#include <vector>

#define INF 100005

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    string str1,str2;
    while(cin>>str1>>str2)
    {
        vector< vector<int> >dp(str2.size(),vector<int>(str1.size()));
        for(int i=0;i<str1.size();++i)
            if(str1[i]==str2[0])
                for(;i<str1.size();i++)
                    dp[0][i]=1;
            else dp[0][i]=0;
        for(int i=0;i<str2.size();++i)
            if(str1[0]==str2[i])
                for(;i<str2.size();i++)
                    dp[i][0]=1;
            else dp[i][1]=0;
        for(int i=1;i<str2.size();++i)
            for(int j=1;j<str1.size();++j)
                if(str2[i]==str1[j])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        printf("%d\n",dp[str2.size()-1][str1.size()-1]);
    }
    return 0;
}