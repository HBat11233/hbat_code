#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len,n;
        scanf("%d%d",&len,&n);
        int maxn=-1,minn=-1;
        int num;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num);
            int temp=len-num;
            maxn=max(maxn,max(num,temp));
            minn=max(minn,min(num,temp));
        }
        printf("%d %d\n",minn,maxn);

    }
    return 0;
}