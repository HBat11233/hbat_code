//poj2184
#include <iostream>
#include <algorithm>
#include <map>
#define LEN 100000

using namespace std;

struct COW
{
    int s;
    int t;
    COW(int s=0,int t=0):
        s(s),t(t){}
}arr[101];
int n;
map<string,bool>dp;
map<string,int>stp;

bool _comp(const COW & a,const COW & b)
{
    if(a.s==a.t)return a.t>b.t;
    return a.s>b.s;
}

inline string INT_TO_STR(int a,int b)
{
    string str1="0000000",str2="0000000";
    if(a>=0)str1[0]='+';
    else str1[0]='-';
    int i=1;
    a=abs(a);
    while(a>0)
    {
        str1[i]=a%10;
        a/=10;
        i++;
    }
    if(b>=0)str2[0]='+';
    else str2[0]='-';
    b=abs(b);
    i=1;
    while(b>0)
    {
        str2[i]=b%10;
        b/=10;
        i++;
    }
    return str1+','+str2;
}

int main()
{
    cin>>n;
    int ms=0,mt=0;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i].s>>arr[i].t;
        if(arr[i].s>0)ms+=arr[i].s;
        if(arr[i].t>0)mt+=arr[i].t;
    }
    sort(arr,arr+n,_comp);
    dp[INT_TO_STR(0,0)]=true;
    stp[INT_TO_STR(0,0)]=-1;
    bool p=false;
    int mis=0,mit=0;
    for(int i=0;i<n;++i)
    {
        if(arr[i].s<=0&&arr[i].t<=0)continue;
        for(int j=ms;j>=arr[i].s+mis;--j)
        {
             for(int k=mt;k>=arr[i].t+mit;--k)
            {
                string str=INT_TO_STR(j-arr[i].s,k-arr[i].t);
                if(dp.count(str)&&stp[str]!=i)
                {
                    string strk=INT_TO_STR(j,k);
                    stp[strk]=i;
                    p=dp[strk]=true;
                    mis=min(mis,j);
                    mit=min(mit,k);
                }
            }
        }
    }
    if(p)
    {
        int ans=-1;
        for(int j=ms;j>=0;--j)
            for(int k=mt;k>=0;--k)
                if(dp.count(INT_TO_STR(j,k))) ans=max(j+k,ans);
        cout<<ans<<endl;
        return 0;
    }
    else
        cout<<0<<endl;
    return 0;
}