#include <iostream>
#include <string.h>

#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

double dp[10005];
int m[105];
double df[105];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        mst(dp,0);
        mst(m,0);
        mst(df,0);
        double p;
        int num;
        int sum=0;
        cin>>p>>num;
        p=1-p;
        for(int i=0;i<num;++i)
        {
            cin>>m[i]>>df[i];
            df[i]=1-df[i];
            sum+=m[i];
        }
        dp[0]=1;
        for(int i=0;i<num;++i)
            for(int j=sum;j>=m[i];--j)
                dp[j]=dp[j-m[i]]*df[i]>dp[j]? dp[j-m[i]]*df[i]:dp[j];
        int ans=0;
        for(int i=sum;i>=0;--i)
            if(dp[i]>p)
            {
                ans=i;
                break;
            }
        cout<<"Case "<<o<<": "<<ans<<endl;
    }
    return 0;
}