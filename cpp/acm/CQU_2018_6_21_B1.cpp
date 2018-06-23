#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
#define inf 0x3f3f3f3f
#define ms(a,b) memset(a,b,sizeof a)
#define ll long long
using namespace std;
int lowbit(int k) {
    return k & -k;
}
int num[100005];
void update(int a,int sum) {
    while(a <= 100000) {
        num[a] += sum;
        a += lowbit(a);
    }
}
int sum(int a) {
    int ans = 0;
    while(a > 0) {
        ans += num[a];
        a -= lowbit(a);
    }
    return ans;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        ms(num, 0);
        scanf("%d", &n);
        char p[100];
        scanf("%s%s", p, p);
        int q1;
        scanf("%d", &q1);
        for(int i = 1; i <= q1; i++) {
            int o;
            scanf("%d", &o);
            if(!o) {
                int a, b;
                scanf("%d%d", &a, &b);
                update(a, b);
            }
            else {
                int a, b;
                scanf("%d%d", &a, &b);
                printf("%d\n",sum(b) - sum(a - 1));
            }

        }
        ms(num, 0);
        int q2;
        scanf("%s%s", p, p);
        scanf("%d", &q2);
        for(int i = 1; i <= q2; i++) {
            int o;
            scanf("%d", &o);
            if(!o) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                update(a,c);
                update(b + 1, -c);
            }
            else {
                int a;
                scanf("%d", &a);
                printf("%d\n", sum(a));
            }
        }

    }
    return 0;
}