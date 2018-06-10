#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) (a*a)

const int UP=0,RIGHT=1,DOWN=2,LEFT=3;
const int TIME=1e5;
struct node{int n[4];};
int N;
node inpt[30];
int Cnt[20][20];
int Map[20][20];
bool vis[30];
int ntime=0;

int dfs(int);
void GetCor(int,int&,int&);
void change(int,int);
bool check(int);

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

int dfs(int step)
{
    if(++ntime>TIME) return 1;

    if(step==N*N) return 1;

    for(int i=0; i<N*N; i++)
    {
        if(vis[i]) continue;
        int x,y;
        GetCor(step,x,y);
        if( x && inpt[i].n[UP] != inpt[ Map[x-1][y] ].n[DOWN] ) continue;
        if(x&1)
        {
            if( y+1<N && inpt[i].n[RIGHT] != inpt[ Map[x][y+1] ].n[LEFT]) continue;
            vis[i]=1;
            Map[x][y]=i;
            if(dfs(step+1)) return 1;
            Map[x][y]=0;
            vis[i]=0;
        }
        else
        {
            if(y && inpt[i].n[LEFT] != inpt[ Map[x][y-1] ].n[RIGHT]) continue;
            vis[i]=1;
            Map[x][y]=i;
            if(dfs(step+1)) return 1;
            Map[x][y]=0;
            vis[i]=0;
        }
    }
    return 0;
}

void GetCor(int step, int &x, int &y)
{
    x=step/N;
    if(x&1) y=N-1-step%N;
    else y=step%N;
}