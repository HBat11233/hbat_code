#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m;
    bool pk[22];
    while(cin>>n>>k>>m,n+k+m)
    {
        int none=0;
        memset(pk,0,sizeof(pk));
        int posa=0,posb=n-1;
        int ia,ib;
        while(none!=n)
        {
            for(ia=0;;)
            {
                if(!pk[posa])ia++;
                if(ia==k)break;
                posa++;
                posa%=n;
            }
            for(ib=0;;)
            {
                if(!pk[posb])ib++;
                if(ib==m)break;
                posb--;
                posb=posb<0?n-1:posb;
            }
            if(posa==posb)
            {
                pk[posa]=true;
                none++;
                printf("%3d",posa+1);
                if(none!=n)printf(",");
            }
            else
            {
                pk[posa]=pk[posb]=true;
                none+=2;
                printf("%3d%3d",posa+1,posb+1);
                if(none!=n)printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}