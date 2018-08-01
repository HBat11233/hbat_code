#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long long n,m,k;
    while(cin>>n>>m>>k)
    {
        long long mun=n-1;
        if(m*mun<k||m>k)cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            long long ans1=k/mun;
            long long num=k%mun;
            while(ans1+num<m)
            {
                ans1--;
                num+=mun;
            }
            long long len=m-ans1;
            for(int i=0;i<ans1;++i)
                printf("%d ",i&1? 1:n);
            if(ans1&1)
            {
                for(int i=0;i<len-1;++i)
                    printf("%d ",i&1? n:n-1);
                if(len)printf("%d",len&1? n-(k-ans1*mun-len+1):n-(k-ans1*mun-len+1)-1);
            }else
            {
                for(int i=0;i<len-1;++i)
                    printf("%d ",i&1? 1:2);
                if(len)printf("%d",len&1? 1+(k-ans1*mun-len+1):2+(k-ans1*mun-len+1));
            }
            printf("\n");

        }
    }
    return 0;
}
