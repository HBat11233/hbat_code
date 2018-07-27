#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n;
    while(~scanf("%d",&n),n)
    {
        vector<int>que(n+1);
        for(int i=1;i<=n;++i)
            scanf("%d",&que[i]);
        vector<int>ans;
        while(true)
        {
            int i;
            for(i=1;i<=n;++i)
                if(que[i]!=i)break;
            if(i==n+1)break;
            if(que[1]==n||que[1]<que[2])
            {
                que.insert(que.begin()+1,*que.rbegin());
                que.pop_back();
                ans.push_back(2);
            }else 
            {
                swap(que[1],que[2]);
                ans.push_back(1);
            }
        }
        if(ans.size()!=0)
            for(vector<int>::iterator it=ans.end()-1;it>=ans.begin();--it)
                cout<<(*it);
        cout<<'\n';
    }
    return 0;
}