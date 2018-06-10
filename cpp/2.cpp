#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;

int T, N, M;
int deg[MAXN];
int par[MAXN];
int in[MAXN], out[MAXN];
int Find (int x) {
    return par[x] == -1 ? x : par[x] = Find (par[x]);
}
void Union (int a, int b) {
    int pa = Find (a), pb = Find (b);
    if (pa != pb) par[pb] = pa;
}
void init() {
    memset (deg, 0, sizeof (deg) );
    memset (in, 0, sizeof (in) );
    memset (out, 0, sizeof (out) );
    memset (par, -1, sizeof (par) );
}
bool connected() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (par[i] == -1) cnt ++;
    }
    return cnt <= 1;
}
bool dir() {
    int num;
    num = 0;
    for (int i = 1; i <= N; i++) {
        if (deg[i] & 1) num ++;
    }
    return (num == 0 || num == 2);
}
bool undir() {
    int num, s, t;
    num = 0;
    s = t = -1;
    for (int i = 1; i <= N; i++) {
        if(out[i] > in[i]) s = i, num ++;
        else if(in[i] > out[i]) t = i, num ++;
    }
    if((num == 0 || (num == 2 && ~s && ~t && (out[s] - in[s]) == 1) && (out[t] - in[t]== -1))) return true;
    return false;
}
int main() {
///    freopen ("input.txt", "r", stdin);
    int u, v;
    scanf("%d", &T);
    while (T --) {
        init();
        scanf ("%d %d", &N, &M);
        for (int i = 1; i <= M; i++) {
            scanf ("%d %d", &u, &v);
            deg[u] ++, deg[v] ++;
            Union (u, v);
            out[u] ++, in[v] ++;
        }
        bool con, res1, res2;
        con = connected();
        if(!con) {
            puts("No No");
            continue;
        }
        res1 = dir();
        res2 = undir();
        printf("%s %s\n", res1 ? "Yes" : "No", res2 ? "Yes" : "No");
    }
    return 0;
}