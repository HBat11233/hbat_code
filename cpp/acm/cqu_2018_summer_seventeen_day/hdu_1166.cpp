#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 50005

using namespace std;

int tree[INF*10];
int n;

void buildtree(int root,int l,int r)
{
    if(l==r)
    {
        scanf("%d",tree+root);
        return;
    }
    int mid=(l+r)>>1;
    buildtree(root*2,l,mid);
    buildtree(root*2+1,mid+1,r);
    tree[root]=tree[root*2+1]+tree[root*2];
    return;
}

void update(int x,int num,int root=1,int l=1,int r=n)
{
    int mid=(l+r)>>1;
    tree[root]+=num;
    if(l==r)return;
    if(mid>=x)update(x,num,root*2,l,mid);
    else update(x,num,root*2+1,mid+1,r);
}

int search(int sl,int sr,int root=1,int l=1,int r=n)
{
    int mid=(l+r)>>1;
    if(sl==l&&sr==r)return tree[root];
    if(sr<=mid)return search(sl,sr,root*2,l,mid);
    if(mid<sl)return search(sl,sr,root*2+1,mid+1,r);
    if(sl<=mid&&mid<sr) return search(sl,mid,root*2,l,mid)+search(mid+1,sr,root*2+1,mid+1,r);
    return 0xffffffff;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        printf("Case %d:\n",o);
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        buildtree(1,1,n);
        string str;
        int a,b;
        while(cin>>str,str!="End")
        {
            scanf("%d%d",&a,&b);
            if(str=="Add")update(a,b);
            else if(str=="Sub")update(a,-b);
            else
                printf("%d\n",search(a,b));
        }
    }
    return 0;
}