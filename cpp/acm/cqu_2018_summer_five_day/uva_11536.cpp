#include <bits/stdc++.h>

#define INF 1000005

using namespace std;

int que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    que[1]=1;
    que[2]=2;
    que[3]=3;
    for(int o=1;o<=t;++o)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int cml[105],cmr[105];
        memset(cml,0x7f,sizeof(cml));
        memset(cmr,-1,sizeof(cmr));
        cml[1]=cmr[1]=1;
        cml[2]=cmr[2]=2;
        cml[3]=cmr[3]=3;
        for(int i=4;i<=n;++i)
        {
            que[i]=(que[i-1]+que[i-2]+que[i-3])%m+1;
            if(que[i]>k)continue;
            cml[que[i]]=min(i,cml[que[i]]);
            cmr[que[i]]=max(i,cmr[que[i]]);
        }
        int l=0x7fffffff,r=-1;
        for(int i=1;i<=k;++i)
        {
            l=min(cmr[i],l);
            r=max(cml[i],r);
        }
        printf("Case %d: ",o);
        if(r-l<INF)
        {
            l=1;
            for(int i=1;i<=k;++i)
                r=max(r,cmr[i]);
            int num=0;
            int pk[105];
            memset(pk,0,sizeof(pk));
            pk[que[l]]=1;
            num++;
            int i;
            int ans=r;
            int length=0x7fffffff;
            for(i=l+1;i<=r;++i)
            {
                if(num>=k&&i-l<length)ans=i,length=ans-l;
                if(que[i]<=k)
                {
                    if(!pk[que[i]])num++;
                    pk[que[i]]++;
                }
                while(que[l]>k||pk[que[l]]>1)
                {
                    if(que[l]<=k)pk[que[l]]--;
                    l++;
                }

            }
            if(num>=k&&i-l<length)ans=i,length=ans-l;
            printf("%d\n",length);
        }
        else printf("sequence nai\n");

    }
    return 0;
}