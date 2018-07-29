#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        getchar();
        string mat[103];
        for(int i=0;i<n;++i)
            getline(cin,mat[i]);
        int len=n;
        while(len%2==0)
        {
            int mid=len/2;
            int i;
            for(i=0;i<mid;++i)
                if(mat[i]!=mat[len-i-1])break;
            if(i==mid)len=mid;
            else break;
        }
        printf("%d\n",len);
    }
    return 0;
}