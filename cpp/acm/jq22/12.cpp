//poj3666
#include <algorithm>
#include <cstdio>
#include <iostream>
#define INF 0x7fffffff

using namespace std;

int arr[2001];
int n;
int temparr[2001];
int dp[2001];

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        temparr[i]=arr[i];
    }
    sort(temparr,temparr+n);
    for(int i=0;i<n;++i)
    {
        int t=INF;
        for(int j=0;j<n;++j)
        {
            t=min(dp[j],t);
            dp[j]=abs(temparr[j]-arr[i])+t;
        }
    }
    int ans=INF;
    for(int i=0;i<n;++i)
        ans=min(dp[i],ans);
    cout<<ans;
    return 0;
}