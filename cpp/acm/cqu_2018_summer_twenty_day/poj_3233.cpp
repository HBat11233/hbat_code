#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int n,k,m;

struct matrix
{
    int _n;
    int _m;
    int arr[35][35];
    void init0(int _n=0,int _m=0)
    {
        this->_n=_n;
        this->_m=_m;
        memset(arr,0,sizeof(arr));
    }
    void init1(int _n=0,int _m=0)
    {
        this->_n=_n;
        this->_m=_m;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<35;++i)
            arr[i][i]=1;
    }
    void output()
    {
        for(int i=0;i<_n;++i)
        {
            for(int j=0;j<_m;++j)
                printf("%d ",arr[i][j]);
            printf("\n");
        }
    }
    matrix operator *(const matrix &b)const
    {
        matrix ans;
        ans.init0(this->_m,b._n);
        for(int i=0;i<ans._n;++i)
            for(int j=0;j<ans._m;++j)
                for(int k=0;k<this->_m;++k)
                {
                    ans.arr[i][j]+=(this->arr[i][k]%m*b.arr[k][j]%m)%m;
                    ans.arr[i][j]%=m;
                }
        return ans;
    }
    matrix operator +(const matrix &b)const
    {
        matrix ans;
        ans._n=b._n;
        ans._m=b._m;
        for(int i=0;i<_n;++i)
            for(int j=0;j<_m;++j)
                ans.arr[i][j]=(arr[i][j]%m+b.arr[i][j]%m)%m;
        return ans;
    }
}val;

map<int,matrix>po;

matrix m_pow(int p)
{
    if(po.count(p))return po[p];
    matrix ans;
    ans.init1(n,n);
    int b=1;
    while(p)
    {
        if(p&1)ans=ans*po[b];
        b<<=1;
        p>>=1;
    }
    return po[p]=ans;
}

matrix sol(int k)
{
    if(k==1)return val;
    matrix tem = sol(k>>1);
    tem = tem*m_pow(k>>1)+tem;
    if(k&1)return tem+m_pow(k);
    else return tem;
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    val._n=val._m=n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&val.arr[i][j]);
    matrix temp=val;
    for(int i=1;i<=k;i<<=1)
    {
        po[i]=temp;
        temp=temp*temp;
    }
    matrix ans = sol(k);
    ans.output();

    return 0;
}