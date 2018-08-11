#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sol(ll num,bool pe,int l=0)
{
    ll ans=-1;
    bool p=false;
    for(ll i=2;i*i<=num;++i)
    {
        if(num%i==0)
        {
            p=true;
            if(sol(i,!pe,l+1)!=-1)ans=i;
            else if(l)
            {
                ans=-1;
                break;
            }
            if(sol(num/i,!pe,l+1)!=-1)ans=num/i;//卡过去了，嘻嘻嘻，这里和上面对应的地方加return就过不去了
            else if(l)
            {
                ans=-1;
                break;
            }
        }
    }
    if(!p)
    {
        if(pe)return -1;
        else return 0;
    }
    return ans;
}

int main()
{
    ll q;
    while(cin>>q)
    {
        ll ans=sol(q,0);
        if(ans==-1)cout<<2<<endl;
        else cout<<1<<'\n'<<ans<<endl;
    }
    return 0;
}