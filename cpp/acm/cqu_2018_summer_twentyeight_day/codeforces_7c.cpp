#include <bits/stdc++.h>

#define MAX 5000000000000000000
#define MIN -5000000000000000000

using namespace std;

typedef long long ll;

ll e_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll ans=e_gcd(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-a/b*y;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    ll x,y;
    ll g=e_gcd(a,b,x,y);
    x=(x*-c)/g;
    y=(y*-c)/g;
    ll t=0;
    map<ll,bool>book;
    bool pk=false;
    while(true)
    {
        if(-c%g!=0)
        {
            pk=true;
            break;
        }
        if(MIN<=x&&x<=MAX&&MIN<=y&&y<=MAX)break;
        if(x<MIN||y>MAX)t++;
        else if(x>MAX||y<MIN)t--;
        if(book[t])
        {
            pk=true;
            break;
        }
        book[t]=true;
        x+=b*t;
        y-=a*t;
    }
    if(!pk&&MIN<=x&&x<=MAX&&MIN<=y&&y<=MAX)cout<<x<<' '<<y<<endl;
    else cout<<-1<<endl;
    return 0;
}