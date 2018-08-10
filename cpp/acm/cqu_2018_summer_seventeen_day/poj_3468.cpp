#include <cstdio>

#define INF 100005

using namespace std;

typedef long long ll;
ll treearr[INF];
ll treearr2[INF];
ll sum[INF];
int n,q;

void add(int x,ll num,ll *arr)
{
    for(int i=x;i<=n;i+=(i&-i))
        arr[i]+=num;
}

ll search(int x,ll *arr)
{
    ll sum=0;
    for(int i=x;i>0;i-=(i&-i))
        sum+=arr[i];
    return sum;
}

int main()
{
    int a,b,c;
    char ch;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&a),sum[i]=sum[i-1]+a;
    for(int i=0;i<q;++i)
    {
        getchar();
        ch=getchar();
        switch(ch)
        {
            case 'C':
                scanf("%d%d%d",&a,&b,&c);
                //对后面的操作和，某点的search为给点结果
                add(a,c,treearr);
                add(b+1,-c,treearr);
                //将对i点的操作和翻i倍，相当对add(a,c,treearr)多算了1 ~ a-1 个c，所以下面储存起来，树状数组保存两个操作，所以负的也会多算
                add(a,c*a,treearr2);                            //存多算的（这里多了一个）
                add(b+1,-c*(b+1),treearr2);                     //多算 1 ~ b 个 -c， （这里也多一个）
                break;
            case 'Q':
                scanf("%d%d",&a,&b);
                ll ans=sum[b]-sum[a-1];
                ans+=(b+1)*search(b,treearr)-search(b,treearr2);//因为上面多一个，所以是b+1不是b，是a不是a-1，
                ans-=(a)*search(a-1,treearr)-search(a-1,treearr2);
                printf("%lld\n",ans);
                break;
        }
    }
    return 0;
}