#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int ans=1;
        while(n>2&&n>=m)
        {
            if(n==m&&n%2==0)break;
            ans++;
            if(n%2==1)n+=1;
            int t1= m>>1;
            m=t1+1;
            n>>=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 4 5 6
1 2 3 4
1 2
*/