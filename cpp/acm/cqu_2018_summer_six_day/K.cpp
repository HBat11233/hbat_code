#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,s;
    while(cin>>n>>s)
    {
        vector<int>que(n);
        for(int i=0;i<n;++i)
            cin>>que[i];
        sort(que.begin(),que.end());
        int vp=0;
        int i=0;
        for(i=0;i<n-1;++i)
        {
            vp+=que[i];
            if(vp>s)break;
        }
        if(i!=n-1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}