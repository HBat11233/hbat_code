#include <bits/stdc++.h>

using namespace std;

int bio[1000005];
int bb[1000005];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    for(int i=1;i<=1000000;++i)
        bb[i]=bb[i-1]^i;
    while(~scanf("%d",&n))
    {
        memset(bio,0,sizeof(bio));
        int ans=0;
        int temp=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&temp);
            ans^=temp;
        }
        for(int i=1;i<=n;++i)
        {
            bio[i]^=bio[i-1];
            if(((n-n%i-i)/i)%2)bio[i]^=bb[i-1]^bb[n%i];
            else bio[i]^=bb[n%i];
        }
        for(int i=1;i<=n;++i)
            if((n-i)%2==1)bio[n]^=i;
            ans^=bio[n];
        printf("%d\n",ans);
    }
    return 0;
}