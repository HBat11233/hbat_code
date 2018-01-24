#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int dis[1001];
int w[1001][1001];
int s[1001],d[1001];

int main()
{
    int T,S,D;
    while(cin>>T>>S>>D)
    {
        int ma=-1;
        for(int i=0;i<1001;++i)
        {
            dis[i]=INF;
            s[i]=0;
            d[i]=0;
            for(int j=0;j<1001;++j)
            {
                if(i==j)w[i][j]=0;
                else w[i][j]=INF;
            }
        }
        dis[0]=0;
        for(int i=0;i<T;++i)
        {
            int a,b,t;
            scanf("%d%d%d",&a,&b,&t);
            if(t<w[a][b])
            {
                w[a][b]=w[b][a]=t;
            }
            ma=ma>(a>b? a:b)? ma:(a>b? a:b);
        }
        for(int i=0;i<S;++i)
        {
            scanf("%d",s+i);
            dis[s[i]]=w[0][s[i]]=w[s[i]][0]=0;
        }
        for(int i=0;i<D;++i)
            scanf("%d",d+i);
        bool v[1001]={false};
        v[0]=true; 
        for(int i=0;i<=ma;++i)
        {
            int t=INF;
            int x=-1;
            for(int j=0;j<=ma;++j)
            {
                if(!v[j]&&dis[j]<t)
                {
                    x=j;
                    t=dis[j];
                }
            }
            if(t>=INF)break;
            v[x]=true;
            for(int j=0;j<=ma;++j)
            {
                if(dis[x]==INF||w[x][j]==INF)continue;
                dis[j]=dis[j]<dis[x]+w[x][j]? dis[j]:dis[x]+w[x][j];
            }
        }
        int ans=INF;
        for(int i=0;i<D;++i)
        {
            ans=ans<dis[d[i]]? ans:dis[d[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}