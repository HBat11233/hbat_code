#include <bits/stdc++.h>

using namespace std;

int liq[1000005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map<int,int>book;
        for(int i=0;i<n;++i)
            scanf("%d",liq+i);
        int l=0,r=1;
        int ans=-1;
        book[liq[0]]=0;
        for(;r<n;r++)
        {
            if(book.count(liq[r])&&book[liq[r]]>=l)
            {
                ans=max(ans,r-l);
                l=book[liq[r]]+1;
            }
            book[liq[r]]=r;
        }
        if(ans==-1)ans=n;
        printf("%d\n",ans);
    }
    return 0;
}