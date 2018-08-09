#include <bits/stdc++.h>

#define INF 6500
#define INFN 65000

using namespace std;

typedef long long LL;

int arr[INF];
int pos=0;

bool arrcount(int x)
{
    int l=0;
    int r=pos-1;
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(arr[mid]==x)return true;
        if(arr[mid]>x)r=mid-1;
        else l=mid+1;
    }
    return false;
}

int qpow_mod(int a,int b,int m)
{
    int ans=1;
    LL temp=a%m;
    while(b)
    {
        if(b&1)ans=(temp*ans)%m;
        temp=(temp*temp)%m;
        b>>=1;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    arr[0]=2;
    arr[1]=3;
    pos=2;
    for(int i=5;i<=INFN;++i)
    {
        int j;
        for(j=0;arr[j]*arr[j]<=i;++j)
            if(i%arr[j]==0)break;
        if(arr[j]*arr[j]>i)arr[pos++]=i;
    }
    int n;
    while(scanf("%d",&n),n)
    {
        bool pk=false;
        if(!arrcount(n))
        {
            int i;
            for(i=n-1;i>1;--i)
                if(qpow_mod(i,n,n)!=i)break;
            if(i!=1)pk=true;
        }else pk=true;
        if(!pk)
			printf("The number %d is a Carmichael number.\n",n);
		else
			printf("%d is normal.\n",n);
    }
    return 0;
}