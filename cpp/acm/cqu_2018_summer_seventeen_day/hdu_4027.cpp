#include <iostream>
#include <cstdio>
#include <cmath>

#define INF 100005

using namespace std;

typedef long long ll;
ll bit[INF*4];
int n;

void buildtree(int root=1,int l=1,int r=n)
{
    if(l==r)
    {
        scanf("%lld",bit+root);
        return;
    }
    int mid=(l+r)>>1;
    buildtree(root<<1,l,mid);
    buildtree(root<<1|1,mid+1,r);
    bit[root]=bit[root<<1]+bit[root<<1|1];
}

void updata(int sl,int sr,int root=1,int l=1,int r=n)
{
    if(r-l+1==bit[root])return;
    if(l==r)
    {
        bit[root]=sqrt(bit[root]);
        return ;    
    }
    int mid=(l+r)>>1;
    if(sr<=mid) updata(sl,sr,root<<1,l,mid);
    if(sl>mid) updata(sl,sr,root<<1|1,mid+1,r);
    if(sl<=mid&&sr>mid) updata(sl,sr,root<<1,l,mid),updata(sl,sr,root<<1|1,mid+1,r);
    bit[root]=bit[root<<1]+bit[root<<1|1];
}

ll search(int sl,int sr,int root=1,int l=1,int r=n)
{
    int mid=(l+r)>>1;
    if(sl==l&&sr==r)return bit[root];
    if(sr<=mid) return search(sl,sr,root<<1,l,mid);
    if(sl>mid) return search(sl,sr,root<<1|1,mid+1,r);
    if(sl<=mid&&sr>mid) return search(sl,mid,root<<1,l,mid)+search(mid+1,sr,root<<1|1,mid+1,r);
}

int main()
{
    int o=0;
    while(~scanf("%d",&n))
    {
        printf("Case #%d:\n",++o);
        buildtree();
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int bb=min(b,c),cc=max(b,c);            //nani????,坑，超时点。。。。
            if(a)printf("%lld\n",search(bb,cc));
            else updata(bb,cc);
        }
        printf("\n");
    } 
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define INF 100005

using namespace std;

typedef long long ll;
ll bit[INF*4];
int n;

ll buildtree(int root=1,int l=1,int r=n)
{
    if(l==r)
    {
        scanf("%lld",bit+root);
        return bit[root];
    }
    int mid=(l+r)>>1;
    return bit[root]=buildtree(root*2,l,mid)+buildtree(root*2+1,mid+1,r);
}

ll updata(int sl,int sr,int root=1,int l=1,int r=n)
{
    if(r-l+1==bit[root])return 0;
    if(l==r)
    {
        ll sq=sqrt(bit[root]);
        ll te=sq-bit[root];
        bit[root]=sq;
        return te;
    }
    int mid=(l+r)>>1;
    if(sr<=mid) 
    {
        ll te=updata(sl,sr,root*2,l,mid);
        bit[root]+=te;
        return te;
    }
    if(sl>mid)
    {
        ll te=updata(sl,sr,root*2+1,mid+1,r);
        bit[root]+=te;
        return te;
    }
    if(sl<=mid&&sr>mid)
    {
        ll te=updata(sl,sr,root*2,l,mid)+updata(sl,sr,root*2+1,mid+1,r);
        bit[root]+=te;
        return te;
    }
}

ll search(int sl,int sr,int root=1,int l=1,int r=n)
{
    int mid=(l+r)>>1;
    if(sl==l&&sr==r)return bit[root];
    if(sr<=mid) return search(sl,sr,root*2,l,mid);
    if(sl>mid) return search(sl,sr,root*2+1,mid+1,r);
    if(sl<=mid&&sr>mid) return search(sl,mid,root*2,l,mid)+search(mid+1,sr,root*2+1,mid+1,r);
}

int main()
{
    int o=0;
    while(~scanf("%d",&n))
    {
        memset(bit,0,sizeof(bit));
        printf("Case #%d:\n",++o);
        buildtree();
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int bb=min(b,c),cc=max(b,c);
            switch(a)
            {
                case 0:
                    updata(bb,cc);
                    break;
                case 1:
                    printf("%lld\n",search(bb,cc));
                    break;
            }
        }
        printf("\n");
    } 
    return 0;
}
*/