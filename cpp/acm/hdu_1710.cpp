//二叉树遍历
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int n;
vector <int> qque,zque;

struct tree
{
    int num;
    struct tree *lnext;
    struct tree *rnext;
    tree(int num=0,tree *lnext=NULL,tree *rnext=NULL)
    :num(0),lnext(lnext),rnext(rnext){}
};

int ftre(int l1,int r1,int l2,int r2,tree &f,int num)
{
    if(l1>r1)return 0;
    tree *p=new tree();
    p->num=qque[l1];
    if(num==0)f.lnext=p;
    else f.rnext=p;
    int be=0;
    for(int i=l2;i<=r2;++i)
        if(qque[l1]==zque[i])
        {
            be=i;
            break;
        }
    int be2=r1+1;
    for(int i=l1+1;i<=r1;++i)
    {
        int j;
        for(j=l2;j<be;++j)
            if(qque[i]==zque[j])break;
        if(j==be)
        {
            be2=i;
            break;
        }
    }
    ftre(l1+1,be2-1,l2,be-1,*p,0);
    ftre(be2,r1,be+1,r2,*p,1);
    return 0;
}

void htree(tree &a)
{
    if(a.lnext!=NULL)htree(*a.lnext);
    if(a.rnext!=NULL)htree(*a.rnext);
    if(a.num!=qque[0])cout<<a.num<<' ';
    else cout<<a.num;
}

int main()
{
    while(~scanf("%d",&n))
    {
        qque.resize(n,0);
        zque.resize(n,0);
        for(int i=0;i<n;++i)
            scanf("%d",&qque[i]);
        for(int i=0;i<n;++i)
            scanf("%d",&zque[i]);
        tree bw;
        ftre(0,n-1,0,n-1,bw,0);
        htree(*bw.lnext);
        cout<<endl;
    }
    return 0;
}