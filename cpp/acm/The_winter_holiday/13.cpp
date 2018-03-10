//poj2392
#include <iostream>
#include <algorithm>

using namespace std;

struct MWS
{
    int h,a,c;
    MWS(int h=0,int a=0,int c=0):
        h(h),a(a),c(c){}
    /*
    bool operator <(const MWS &as)
    {
        return this->a<as.a;
    }
    */
    MWS operator *(const int &as)
    {
        MWS s;
        s.h=this->h*as;
        s.a=this->a;
        return s;
    }
}arr[4001];
int n;
bool dp[40001];

bool _comp(const MWS &a,const MWS &b)
{
    return a.a<b.a;
} 


int main()
{
    cin>>n;
    int i,k;
    for(i=0,k=0;k<n;++i,++k)
    {
        cin>>arr[i].h>>arr[i].a>>arr[i].c;
        if(arr[i].h*arr[i].c>arr[i].a)arr[i].c=arr[i].a/arr[i].h;
        int t=2;
        int j=i;
        arr[i].c-=1;
        while(t<arr[i].c)
        {
            j++;
            arr[j]=arr[i]*t;
            arr[i].c-=t;
            t=t<<1;
            
        }
        if(arr[i].c) arr[++j]=arr[i]*arr[i].c;
        i=j;
    }
    n=i;
    sort(arr,arr+n,_comp);
    dp[0]=true;
    for(i=0;i<n;++i)
    {
        for(int j=arr[i].a;j>=arr[i].h;--j)
            if(dp[j-arr[i].h]) dp[j]=true;
    }
    for(i=arr[n-1].a;i>=0;--i)
        if(dp[i])break;
    cout<<i<<endl;
    return 0;
}