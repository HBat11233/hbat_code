#include <bits/stdc++.h>

#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int n,k;
int he;
int ti[7];
int w[705][705];
int dis[705];
int pk[705];

int spfa(int x)
{
    queue<int>que;
    mem(pk,0);
    mem(dis,0x7f);
    pk[x]=true;
    que.push(x);
    dis[x]=0;
    int len=(he+1)*n;
    while(!que.empty())
    {
        int h=que.front();
        for(int i=1;i<=len;++i)
        {
            if(dis[i]>dis[h]+w[h][i])
            {
                dis[i]=dis[h]+w[h][i];
                if(!pk[i])
                {
                    pk[i]=true;
                    que.push(i);
                }
            }
        }
        que.pop();
        pk[h]=false;
    }
    int ans=0x7fffffff;
    len=k*n;
    for(int i=1;i<=n;++i)
        ans=min(ans,dis[len+i]);
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    while(~scanf("%d%d",&n,&k))
    {
        static int o=0;
        o++;
        mem(ti,0);
        mem(w,0x7f);
        for(int i=1;i<=n;++i)
            scanf("%d",ti+i);
        char ch;
        int pos=1;
        int te;
        int la=-1;
        he=k;
        while(pos<=n)
        {
            scanf("%d",&te);
            he=max(he,te);
            ch=getchar();
            if(la!=-1)
                w[pos+la*n][pos+te*n]=w[pos+te*n][pos+la*n]=(te-la)*ti[pos];
            la=te;
            if(ch=='\n')
            {
                pos++;
                la=-1;
            }
        }
        for(int i=1;i<=he;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    if(j!=k)w[i*n+j][i*n+k]=w[i*n+k][i*n+j]=60;
        for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    if(j!=k)w[j][k]=w[k][j]=0;
        int ans=spfa(1);
        if(ans>=0x7f7f7f7f)printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}

/*
4 44
47 9 82 95
0 1 2 3 4 5 9 10 11 13 14 15 16 18 23 25 26 27 29 31 33 34 35 37 38 39 41 43 44 47 49 52 53 54 55 56 57 58 62 63 64 66 68 70 71 73 74 75 76 78 80 81 82 83 84 85 87 89 90 91 92 93 94 95 96 97 99
3 7 22 26 30 34 37 38 47 49 61 62 70 97
1 19 24 33 40 54 70 77
95
3 31
25 63 83
5 7 12 15 22 27 28 29 30 34 35 36 39 46 47 48 51 57 59 69 71 73 75 76 83 90 96 98
0 1 3 4 5 6 9 10 11 12 13 15 16 17 18 19 20 21 23 24 25 26 28 30 32 33 35 36 37 38 39 40 41 43 44 45 49 50 51 52 53 55 56 58 59 60 62 64 65 67 69 70 72 74 77 78 79 80 82 83 84 85 86 89 90 91 93 95 96 98
0 7 8 10 11 13 17 32 34 39 41 43 48 49 54 59 60 63 70 71 73 74 79 82 86 90 92 93 95 96 98
*/