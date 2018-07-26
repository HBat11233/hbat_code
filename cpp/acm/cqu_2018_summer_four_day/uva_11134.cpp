#include <bits/stdc++.h>

//#define DEBUG

using namespace std;

struct mar
{
    int bx;
    int by;
    int ex;
    int ey;
    int ax;
    int ay;
    int pos;
    bool operator <(const mar &b)const
    {
        return pos<b.pos;
    }
}que[5005];

bool _cmp1(const mar &a,const mar &b)
{
    if(a.bx==b.bx)return a.ex<b.ex;
    else return a.bx<b.bx;
}

bool _cmp2(const mar &a,const mar &b)
{
    if(a.by==b.by)return a.ey<b.ey;
    else return a.by<b.by;
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;++i)
            scanf("%d%d%d%d",&que[i].bx,&que[i].by,&que[i].ex,&que[i].ey),que[i].pos=i;
        sort(que,que+n,_cmp1);
        for(int i=0;i<n;++i)
        {
            if(i+1>=que[i].bx&&i+1<=que[i].ex)
            {
                que[i].ax=i+1;
                int j;
                for(j=i+1;j<n;++j)
                {
                    if(que[j].bx==i+1)que[j].bx++;
                    else break;
                }
                int k;
                for(k=j;k<n;++k)
                    if(que[k].bx!=que[j].bx)break;
                sort(que+i+1,que+k,_cmp1);
            }
            else
            {
                printf("IMPOSSIBLE\n");
                goto END;
            }
        }
        sort(que,que+n,_cmp2);
        for(int i=0;i<n;++i)
        {
            if(i+1>=que[i].by&&i+1<=que[i].ey)
            {
                que[i].ay=i+1;
                int j;
                for(j=i+1;j<n;++j)
                {
                    if(que[j].by==i+1)que[j].by++;
                    else break;
                }
                int k;
                for(k=j;k<n;++k)
                    if(que[k].by!=que[j].by)break;
                sort(que+i+1,que+k,_cmp2);
            }
            else
            {
                printf("IMPOSSIBLE\n");
                goto END;
            }
        }
        sort(que,que+n);
        for(int i=0;i<n;++i)
            printf("%d %d\n",que[i].ax,que[i].ay);
        END:;
    }
    return 0;
}
