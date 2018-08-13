//https://blog.csdn.net/weizhuwyzc000/article/details/50505375
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

#define MOD 10007

using namespace std;

int n;

struct matrix
{
    int n;
    int m;
    int arr[3][3];
    void init0(int n=0,int m=0)
    {
        this->n=n;
        this->m=m;
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                arr[i][j]=0;
    }
    void init1(int n=0,int m=0)
    {
        this->n=n;
        this->m=m;
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                arr[i][j]=0;
        for(int i=0;i<3;++i)
            arr[i][i]=1;
    }
    matrix operator *(const matrix &b)const
    {
        matrix ans;
        ans.init0(n,b.m);
        for(int i=0;i<ans.n;++i)
            for(int j=0;j<ans.m;++j)
                for(int k=0;k<m;++k)
                {
                    ans.arr[i][j]+=((arr[i][k]%MOD)*(b.arr[k][j]%MOD))%MOD;
                    ans.arr[i][j]%=MOD;
                }
        return ans;
    }
    matrix operator *=(const matrix &b)
    {
        return *this=*this*b;
    }
}valM,movM;

map<int,matrix>po;

matrix m_pow(int p)
{
    matrix ans;
    ans.init1(3,3);
    int b=1;
    while(p)
    {
        if(p&1)ans=ans*po[b];
        b<<=1;
        p>>=1;
    }
    return ans;
}

void init()
{
    valM.init0(3,1);
    valM.arr[0][0]=2;
    valM.arr[1][0]=2;
    valM.arr[2][0]=0;
    movM.init0(3,3);
    movM.arr[0][0]=2;
    movM.arr[0][1]=1;
    movM.arr[1][0]=2;
    movM.arr[1][1]=2;
    movM.arr[1][2]=2;
    movM.arr[2][1]=1;
    movM.arr[2][2]=2;
    matrix &temp=movM;
    for(int i=0;(1<<i)<=1000000000;++i)
    {
        po[1<<i]=temp;
        temp*=temp;
    }
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        matrix ans=m_pow(n-1);
        ans=ans*valM;
        cout<<ans.arr[0][0]<<'\n';
    }
    return 0;
}