#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

struct matrix
{
    int n;
    int m;
    long long s[6][6];
    matrix()
    {
        n=0;
        m=0;
        for(int i=0;i<6;++i)
            for(int j=0;j<6;++j)
                s[i][j]=0;
    }
};

matrix operator * (const matrix & a,const matrix & b)
{
    matrix c;
    if(a.m!=b.n)return c;
    c.n=a.n;
    c.m=b.m;
    for(int i=0;i<c.n;++i)
        for(int j=0;j<c.m;++j)
        {
            for(int k=0;k<a.m;++k)
            {
                c.s[i][j]+=((a.s[i][k]%MOD)*(b.s[k][j]%MOD))%MOD;
                c.s[i][j]%=MOD;
            }
        }
    return c;
}

matrix qpow(matrix a,int n)
{
    matrix ans=a;
    matrix temp=a;
    int p=n-1;
    while(p)
    {
        if(p&1)ans=ans*temp;
        temp=temp*temp;
        p>>=1;
    }
    return ans;
}

int main()
{
    matrix f0;
    f0.n=5;
    f0.m=1;
    int sa[5][1]={{2},{1},{4},{4},{1}};
    for(int i=0;i<5;i++)
        for(int j=0;j<5;++j)
            f0.s[i][j]=sa[i][j];
    matrix a;
    a.n=a.m=5;
    int sb[5][5]=
    {
        {1,1,1,0,0},
        {1,0,0,0,0},
        {0,0,1,1,1},
        {0,0,0,1,2},
        {0,0,0,0,1},
    };
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            a.s[i][j]=sb[i][j];
    int n,m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        if(m<=2)cout<<f0.s[2-m][0]<<'\n';
        else
        {
            matrix an=qpow(a,m-2);
            matrix fn=an*f0;
            cout<<fn.s[0][0]<<'\n';
       }
    }
    return 0;
}