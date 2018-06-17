#include <cstdio>
#include <cstring>
//#pragma comment(linker,"/STACK:102400000,102400000")
#define N 50010
#define M 100010
#define min(a,b) ((a) < (b) ? (a): (b))

struct Edge
{
    int to, next;
}E[M];

    struct Node 
    {
    int x, y;
}node[M];

int head[N], sccno[N], pre[N], lowlink[N], stack[N], link[N];
int n, m, tot, scc_cnt, dfs_clock, top;
bool vis[N];

void AddEdge(int u, int v) 
{
    E[tot].to = v;
    E[tot].next = head[u];
     head[u] = tot++;  
}

void init() 
{
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    tot = 0;

    for (int i = 1; i <= m; i++) 
    {
        scanf("%d%d", &node[i].x, &node[i].y);
        AddEdge(node[i].x, node[i].y);
    }
}

void dfs(int u) 
{
    pre[u] = lowlink[u] = ++dfs_clock;
    stack[++top] = u;

    for (int i = head[u]; i != -1; i = E[i].next) 
    {
        int v = E[i].to;
        if (!pre[v]) 
        {
            dfs(v);
            lowlink[u] = min(lowlink[v], lowlink[u]);
        }
        else if(!sccno[v]) 
        {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }

    int x;
    if (lowlink[u] == pre[u]) 
    {
        ++scc_cnt;
        while (1) 
        {
            x = stack[top--];
            sccno[x] = scc_cnt;
            if (x == u)
                break;
        }
    }
}

bool dfs2(int u) 
{
    for (int i = head[u]; i != -1; i = E[i].next) 
    {
        int v =E[i].to;
        if (!vis[v]) 
        {
            vis[v] = true;
            if (link[v] == -1 || dfs2(link[v])) 
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

void solve() 
{
    memset(pre, 0, sizeof(pre));
    memset(sccno, 0, sizeof(sccno));
    scc_cnt = top = dfs_clock = 0;

    for (int i = 1; i <= n; i++)
        if (!pre[i])
            dfs(i);

    memset(head, -1, sizeof(head));
    tot = 0;

    int u, v;
    for (int i = 1; i <= m; i++) 
    {
        u = sccno[node[i].x];
        v = sccno[node[i].y];
        if (u != v) AddEdge(u, v);
    }

    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= scc_cnt; i++) 
    {
        memset(vis, 0, sizeof(vis));
        if (dfs2(i)) ans++;
    }
    printf("%d\n", scc_cnt - ans);
}

int main() 
{
    int test;
    scanf("%d", &test);
    while (test--) 
    {
        init();
        solve();
    }
    return 0;
}