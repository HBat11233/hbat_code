#include <bits/stdc++.h>

#define INF 200005

using namespace std;

int que[INF];
int ans[INF];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        scanf("%d",que+i);
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=que[i];
        ans[i]=sum/m;
        sum%=m;
    }
    for(int i=0;i<n;++i)
        printf("%d ",ans[i]);
    return 0;
}