#include <bits/stdc++.h>

#define INF 100005

using namespace std;

bool pk[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
            pk[i]=0;
        char ch;
        int id;
        bool a=0,b=0;
        vector<int>que;
        for(int i=1;i<=m;++i)
        {
            getchar();
            scanf("%c %d",&ch,&id);
            if(ch=='+')que.push_back(id);
            else que.push_back(-id);
        }
        for(int i=0;i<que.size()-1;++i)
            if(que[i]<0&&que[i]+que[i+1]==0)
            {
                que.erase(que.begin()+i,que.begin()+i+2);
                i--;
            }
        for(int i=1;i<=n;++i)
            if(pk[i])printf("%d ",i);
        printf("\n");
    }
    return 0;
}