//快速幂+快速乘+拓展欧拉定理降幂
//https://zhuanlan.zhihu.com/p/31510871
//https://blog.csdn.net/hzj1054689699/article/details/80693756     //有点看不懂
#include <iostream>

using namespace std;

typedef long long ll;           //这个题居然有负数输出，垃圾题目

ll a,c;
string b;

ll phi(ll n)
{
    if(n==1)return 0;
    ll ans = n;
    for(ll i=2;i*i<=n*10;++i)
    {
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}

ll gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

ll qpow(ll n,ll m)
{
    ll ans=1;
    n%=c;
    while(m)
    {
        if(m&1) 
        {
            ans*=n;
            ans%=c;
        }
        n*=n;
        n%=c;
        m>>=1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    while(cin>>a>>b>>c)
    {
        ll ans=0;
        ll num=0;
        ll temp=phi(c);
        if(temp==0)ans=0;
        else if(b.size()<16)
        {
            for(int i=0;i<b.size();++i)
            {
                num*=10;
                num+=b[i]-'0';
            }
            if(num<temp)ans=qpow(a,num);
            else ans=qpow(a,num%temp+temp);
        }
        else
        {
            for(int i=0;i<b.size();++i)
            {
                num*=10;
                num+=b[i]-'0';
                if(num>=temp)
                    num%=temp;
            }
            if(gcd(a,c)==1)ans=qpow(a,num);
            else ans=qpow(a,num+temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}