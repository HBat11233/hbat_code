//poj2184
#include <iostream>
#include <algorithm>
#define INF 200000

using namespace std;

int n;
struct COW
{
    int s;
    int f;
    COW(int s=0,int f=0):
        s(s),f(f){}
}arr[101];

int dp[INF];
bool dk[INF];
bool dl[INF];
int mak[2];

bool _comp(const COW a,const COW b)
{
    return a.f>b.f;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i].s>>arr[i].f;
        if(arr[i].s>0)mak[0]+=arr[i].s;
        else mak[1]+=arr[i].s;
    }
    sort(arr,arr+n,_comp);
    for(int i=((INF>>1)+mak[1]);i<=((INF>>1)+mak[0]);++i)
        dp[i]=INF>>1;
    dk[INF>>1]=true;
    dl[INF>>1]=true;
    for(int i=0;i<n;++i)
    {
        if(arr[i].s>0)
        {
            for(int j=(INF>>1)+mak[0];j>=(INF>>1)+mak[1];--j)
            {
                if(!dk[j-arr[i].s])continue;
                    if(dl[j])dp[j]=max(dp[j],dp[j-arr[i].s]+arr[i].f);
                    else
                    {
                        dp[j]=dp[j-arr[i].s]+arr[i].f;
                        dl[j]=true;
                    }
                    dk[j]=true;
            }
        }else
        {
            if(arr[i].f<0)continue;
            for(int j=(INF>>1)+mak[1];j<=(INF>>1)+mak[0];++j)
            {
                if(!dk[j-arr[i].s])continue;
                    if(dl[j])dp[j]=max(dp[j],dp[j-arr[i].s]+arr[i].f);
                    else
                    {
                        dp[j]=dp[j-arr[i].s]+arr[i].f;
                        dl[j]=true;
                    }
                    dk[j]=true;
            }
        }
    }
    int ans=0;
    for(int i=(INF>>1);i<=(INF>>1)+mak[0];++i)
        if(dk[i]&&dp[i]-(INF>>1)>=0)
            ans=max(ans,i+dp[i]-INF);
    cout<<ans<<endl;
    return 0;
}