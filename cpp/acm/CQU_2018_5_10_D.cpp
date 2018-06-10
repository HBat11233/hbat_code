#include <cstdio>
#include <iostream>

<<<<<<< HEAD
<<<<<<< HEAD
const int UP=0,RIGHT=1,DOWN=2,LEFT=3;
const int TIME=1e5;
struct node{int n[4];};
int N;
node inpt[30];
int Cnt[20][20];
int Map[20][20];
bool vis[30];
int ntime=0;
=======
>>>>>>> parent of 0a0a1d3... 6

#pragma (disable :4996)

<<<<<<< HEAD
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    #endif
    int T;
    scanf("%d", &T);
    for(int ck=1; ck<=T; ck++)
    {
        ntime=0;
        CLR(vis);CLR(Cnt);CLR(Map);
        scanf("%d", &N);
        for(int i=0; i<N*N; i++) for(int j=0; j<4; j++)
        {
            scanf("%d", &inpt[i].n[j]);
            Cnt[j][inpt[i].n[j]]++;
        }
        if(dfs(0)&&ntime<=TIME) puts("Possible");
        else
        {
            puts("Impossible");
        }
//      printf("%lld\n", ntime);
    }
    return 0;
}
=======
using namespace std;
>>>>>>> 47639abb13dad5d66c6be4f09a8942d6896246a8
=======
using namespace std;
>>>>>>> parent of 0a0a1d3... 6

struct SQ
{
    int fnum[4]; 
};

SQ mps[6][6];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int t;
int n;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int temp=n*n;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int z=0;z<4;++z)
                    scanf("%d",mps[i][j].fnum+z);
        
    }
    return 0;
}