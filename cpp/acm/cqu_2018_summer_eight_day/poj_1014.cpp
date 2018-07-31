#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int num[7];

int dp[200500];

int main()
{
    int t=0;
    while(scanf("%d%d%d%d%d%d",num+1,num+2,num+3,num+4,num+5,num+6),num[1]+num[2]+num[3]+num[4]+num[5]+num[6])
    {
        t++;
        vector<int>que;
        int sum=0;
        for(int i=1;i<=6;++i)
            sum+=num[i]*i;
        if(sum&1)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",t);
            continue;
        }
        for(int i=1;i<=6;++i)
        {
            if(num[i]==0)continue;
            for(int j=1;j<num[i];j<<=1)
            {
                que.push_back(j*i);
                num[i]-=j;
            }
            if(num[i])
            que.push_back(num[i]*i);
        }
        memset(dp,0,sizeof(dp));
        sum/=2;
        for(int j=0;j<que.size();++j)
        {
            for(int i=sum;i>=que[j];--i)
                dp[i]=max(dp[i],dp[i-que[j]]+que[j]);
        }
        if(dp[sum]==sum)
            printf("Collection #%d:\nCan be divided.\n\n",t);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",t);
    }
    return 0;
}