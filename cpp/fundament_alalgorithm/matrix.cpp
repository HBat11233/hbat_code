#include <bits/stdc++.h>

using namespace std;

int read()
{
    int s=0,f=1;
    char ch = getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch == '-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<1)+(s<<3)+ch-'0';
        ch=getchar();
    }
    return s*f;
}

const int max_n = 100,max_m=100;
int mod = 10000;
struct matrix
{
    int n,m;
    long long s[max_n][max_m];
    matrix()
    {
        clean();
    }
    void clean()
    {
        n = max_n;
        m = max_m;
        for(int i = 0;i<max_n;++i)
            for(int j = 0;j<max_m;++j)
                s[i][j]=0;
    }
}A,F0;

long long ss[max_n];
matrix operator* (matrix a,matrix b)
{
    matrix c;
    if(a.m != b.n)
    {
        return c;
    }
    c.n=a.n;
    c.m=b.m;
    for(int j=0;j<c.m;++j)
    {
        for(int i=0;i<c.n;++i)
            ss[i] = b.s[i][j];
        for(int i=0;i<c.n;++i)
        {
            for(int k=0;k<a.m;++k)
                c.s[i][j]+=a.s[i][k]*ss[k];
            c.s[i][j]%=mod;
        }
    }
    return c;
}

matrix pow(matrix a,int b)
{
    matrix ans;
    ans.n=ans.m=a.n;
    for(int i=0;i<a.n;++i)
        for(int j=0;j<a.n;++j)
            ans.s[i][j]=(i==j);
    for(;b;b>>=1,a=a*a)
    if(b&1)
        ans=ans*a;
    return ans;
}

int n,k;

int mian()
{
    n=read();
    k=read();
    for(int i=0;i<k;++i)
        A.s[0][i]=read();
    for(int i=1;i<k;++i)
        A.s[i][i-1]=1;
    for(int i=0;i<k;++i)
        F0.s[k-i-1][0]=read();
    A.n=A.m=k;
    F0.n=k;
    F0.m=1;
    if(n<k)
    {
        printf("%d\n",int(F0.s[k-n-1][0]));
        return 0;
    }
    matrix dd = pow(A,1);
    printf("%d\n",int((pow(A,n-k+1)*F0).s[0][0]));
    return 0;
} 