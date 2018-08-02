#include <bits/stdc++.h>

#define INF 1005

using namespace std;

string str;

bool is(int a,int b)
{
    while(a<=b&&str[a]==str[b])
    {
        a++;
        b--;
    }
    if(a<=b)return false;
    else return true;
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int tnum;
    scanf("%d",&tnum);
    for(int o=1;o<=tnum;++o)
    {
        cin>>str;
        int dp[INF];
        memset(dp,0x7f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=str.size();++i)
            for(int j=1;j<=i;++j)
                if(is(j-1,i-1))dp[i]=min(dp[i],dp[j-1]+1);
                //else dp[i]=min(dp[i],dp[i-1]+1);//循环会判断到
        printf("%d\n",dp[str.size()]);

    }
    return 0;
}