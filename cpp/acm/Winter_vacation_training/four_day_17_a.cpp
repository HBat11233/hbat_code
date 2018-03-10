#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define LENG 10001

using namespace std;

int father[LENG];

struct WP
{
    int a;
    int b;
    int leng;
}w[LENG];

void qsort(int b,int e)
{
    int bl=w[(b+e)/2].leng;
    int i=b,j=e;
    while(i<=j)
    {
        while(w[i].leng<bl)i++;
        while(w[j].leng>bl)j--;
        if(i<=j)
        {
            swap(w[i],w[j]);
            i++;
            j--;
        }
    }
    if(i<e)qsort(i,e);
    if(b<j)qsort(b,j);
}

bool _comp(const WP &a,const WP &b)
{
    return a.leng<b.leng;
}

int findb(int x)
{
    if(father[x]!=x) father[x]=findb(father[x]);
    return father[x];
}

inline int unionb(int &a,int &b)
{
    father[b]=a;
    return a;
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int ans=0;
        for(int i=1;i<=n;++i)
            father[i]=i;
        int m=(n*(n-1))/2;
        for(int i=0;i<m;++i)
            scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].leng);
        //qsort(0,m-1);//数据有毒
        sort(w,w+m,_comp);
        for(int i=0,j=0;j<n-1&&i<m;++i)
        {
            int x=findb(w[i].a);
            int y=findb(w[i].b);
            if(x!=y)
            {
                ans+=w[i].leng;
                unionb(x,y);
                j++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}