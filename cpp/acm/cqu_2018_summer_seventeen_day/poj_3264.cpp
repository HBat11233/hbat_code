#include <iostream>
#include <algorithm>
#include <cstdio>

#define INF 500005

using namespace std;

int maxtree[INF];
int mintree[INF];
int arr[INF/4];
int n,q;

int bmaxt(int root=1,int l=1,int r=n)
{
    if(l==r) return maxtree[root]=arr[l];
    int mid=(l+r)>>1;
    return maxtree[root]=max(bmaxt(root*2,l,mid),bmaxt(root*2+1,mid+1,r));
}

int bmint(int root=1,int l=1,int r=n)
{
    if(l==r) return mintree[root]=arr[l];
    int mid=(l+r)>>1;
    return mintree[root]=min(bmint(root*2,l,mid),bmint(root*2+1,mid+1,r));
}

int searchmax(int sl,int sr,int root=1,int l=1,int r=n)
{
    if(sl==l&&sr==r)return maxtree[root];
    int mid=(l+r)>>1;
    if(sl>mid)return searchmax(sl,sr,root*2+1,mid+1,r);
    if(sr<=mid)return searchmax(sl,sr,root*2,l,mid);
    if(sl<=mid&&mid<sr) return max(searchmax(sl,mid,root*2,l,mid),searchmax(mid+1,sr,root*2+1,mid+1,r));
}

int searchmin(int sl,int sr,int root=1,int l=1,int r=n)
{
    if(sl==l&&sr==r)return mintree[root];
    int mid=(l+r)>>1;
    if(sl>mid)return searchmin(sl,sr,root*2+1,mid+1,r);
    if(sr<=mid)return searchmin(sl,sr,root*2,l,mid);
    if(sl<=mid&&mid<sr) return min(searchmin(sl,mid,root*2,l,mid),searchmin(mid+1,sr,root*2+1,mid+1,r));
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    bmaxt();
    bmint();
    for(int i=0;i<q;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans=searchmax(a,b)-searchmin(a,b);
        printf("%d\n",ans);
    }
    return 0;
}