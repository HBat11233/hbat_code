#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<int>que;
        vector<int>bans;
        vector<int>ans;
        vector<int>tque;
        int temp;
        scanf("%d",&temp);
        que.resize(temp);
        ans.resize(temp);
        for(int i=0;i<temp;++i)
            scanf("%d",&que[i]);
        temp=0;
        for(int i=0;i<que.size();++i)
        {
            for(;temp<que[i];++temp)
            {
                tque.push_back(temp);
            }
            bans.push_back(*tque.rbegin());
            tque.pop_back();
        }
        for(int i=0;i<bans.size();++i)
            for(int j=0;j<=i;++j)
                if(bans[i]<=bans[j])ans[i]++;
        for(int i=0;i<ans.size();++i)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}