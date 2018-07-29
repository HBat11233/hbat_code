#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,t,c;
    while(~scanf("%d%d%d",&n,&t,&c))
    {
        vector<int>pos;
        int temp;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&temp);
            if(temp>t)pos.push_back(i);
        }
        int ans=0;
        int l=0,r=c-1;
        int posn=0;
        for(;r<n;++r,++l)
        {
            if(posn<pos.size()&&pos[posn]<=r)
            {
                l=pos[posn];
                r=l+c-1;
                posn++;
            }
            else
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}