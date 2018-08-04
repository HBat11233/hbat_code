//error
#include <bits/stdc++.h>

#define INF 100005

using namespace std;

int que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d",que+i);
    int v;
    for(v=31;v>=0;--v)
        if(((1<<v)&que[n-1])==(1<<v)&&)break;
    int v2=1<<v;
    int temp=-1;
    int i;
    for(i=n-1;que[i]>=v2;--i)
        temp&=que[i];
    return 0;
}