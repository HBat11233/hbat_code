#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("1.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int ans=0;
        vector<int>arr;
        scanf("%d",&n);
        arr.resize(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        for(int i=0;i<n;++i)
        {
                int tnum=-1;
                for(int k=i;k<n;++k)
                {
                    tnum&=arr[k];
                    ans+=tnum;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}