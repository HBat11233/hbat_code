//poj 2395
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct WTD
{
    int length;
    int lot1;
    int lot2;
    WTD(int a=0,int b=0,int c=0):
        length(a),lot1(b),lot2(c){}
}mw[10005];
int n,m;
int fr[2005];

bool _comp(const WTD &a,const WTD &b)
{
    return a.length<b.length;
}

int _f(int a)
{
    if(a==fr[a])return a;
    else return fr[a]=_f(fr[a]);
}

int _b(int a,int b)
{
    int num1=_f(a);
    int num2=_f(b);
    if(num1!=num2)
    {
        fr[num1]=num2;
        return true;
    }
    return false;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
            fr[i]=i;
        for(int i=0;i<m;++i)
            scanf("%d%d%d",&mw[i].lot1,&mw[i].lot2,&mw[i].length);
        sort(mw,mw+m,_comp);
        int num=1;
        int i=0;
        int ans;
        while(num!=n)
        {
            if(_b(mw[i].lot1,mw[i].lot2))
            {
                num++;
                ans=mw[i].length;
            }
            ++i;
        }
        printf("%d\n",ans);
    }
    return 0;
}