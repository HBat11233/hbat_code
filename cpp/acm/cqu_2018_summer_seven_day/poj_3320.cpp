#include <iostream>
#include <cstdio>
#include <map>

#define INF 1000005

using namespace std;

int que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    while(~scanf("%d",&n))
    {
        int num=0;
        map<int,int>book;
        for(int i=0;i<n;++i)
        {
            scanf("%d",que+i);
            if(book[que[i]]==0)
            {
                num++;
                book[que[i]]=1;
            }
        }
        book.clear();
        int t=0,st=0,sum=0,ans=n;
        while(true)
        {
            while(t<n&&sum<num)
            {
                if(!book[que[t++]]++)
                    sum++;
            }
            if(sum<num)break;
            ans=min(ans,t-st);
            if(--book[que[st++]]==0)sum--;
        }
        printf("%d\n",ans);
    }
    return 0;
}

