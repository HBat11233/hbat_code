#include <iostream>
#include <cstdio>

using namespace std;

struct SEG
{
    int v;
    int l;
    int r;
    SEG(int v=0,int l=0,int r=0)
        :v(v),l(l),r(r){}
};

SEG TE[280000];
int n,m;

void build(const int &k,const int &l,const int &r)
{
    TE[k].l=l;
    TE[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    return;
}

void tree_in(const int &l,const int &r,const int &n,const int &k=1)
{
    if(l==TE[k].l&&r==TE[k].r)
    {
        TE[k].v+=n;
        return;
    }
    int mid = (TE[k].r+TE[k].l)>>1;
    if(r<=mid)tree_in(l,r,n,k<<1);
    else if(l<=mid)
    {
        tree_in(l,mid,n,k<<1);
        tree_in(mid+1,r,n,k<<1|1);
    }
    else if(l>mid)tree_in(l,r,n,k<<1|1);
    return;
}

int find_tr(const int &s,int ans=0,const int &k=1)
{
    if(TE[k].l==TE[k].r)return ans+TE[k].v;
    int mid = (TE[k].r+TE[k].l)>>1;
    if(s<=mid)return find_tr(s,ans+TE[k].v,k<<1);
    else return find_tr(s,ans+TE[k].v,k<<1|1);
    return ans;
}

int main()
{
    scanf("%d%d\n",&n,&m);
    build(1,1,n);
    for(int i=0;i<m;++i)
    {
        char ch;
        scanf("%c",&ch);
        switch(ch)
        {
            case 'L':
                int a,b,c;
                scanf("%d%d%d\n",&a,&b,&c);
                tree_in(a,b,c);
                break;
            case 'S':
                int s;
                scanf("%d\n",&s);
                printf("%d\n",find_tr(s)+100);
                break;
        }
    }
    return 0;
}
/*
3 3
L 1 2 3
S 2
L 1 3 1
*/

