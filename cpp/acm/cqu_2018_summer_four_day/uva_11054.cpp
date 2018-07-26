#include <bits/stdc++.h>

using namespace std;

int que[100005];

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;++i)
            scanf("%d",que+i);
        long long int ans=0;
        for (int i = 0; i < n - 1; i++) 
        {
	        ans += abs(que[i]);
	        que[i + 1] += que[i];
	    }
        printf("%lld\n",ans);
    }
    return 0;
}