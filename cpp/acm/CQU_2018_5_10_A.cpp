#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e7+2;
struct node
{
    int ch[N][2];
    int root,L;
    int newnode()
    {
        ch[L][0]=ch[L][1]=-1;
        return L++;
    }
    void Init()
    {
        L=0,root=newnode();
    }
    void Insert(int x)
    {
        int now=root;
        for(int j=30; j>=0; j--)
        {
            int go=(x&(1<<j))?1:0;
            if(ch[now][go]==-1)
            {
                ch[now][go]=newnode();
                now=ch[now][go];
            }else
                now=ch[now][go];
        }
    }
    int Query(int x)
    {
        int now=root;
        int ans=0;
        for(int j=30;j>=0;j--)
        {
            int go=(x&(1<<j))?1:0;
            if(ch[now][!go]!=-1) ans|=(1<<j),now=ch[now][!go];
            else now=ch[now][go];
        }
        return ans;
    }
}Trie;
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        Trie.Init();
        int maxans=-1;
        int val;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&val);
            Trie.Insert(val);
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&val);
            maxans=max(maxans,Trie.Query(val));
        }
        printf("%d\n",maxans);
    }
    return 0;
}
