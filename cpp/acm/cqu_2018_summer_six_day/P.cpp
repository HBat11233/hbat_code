#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
     int n;
     while(~scanf("%d",&n))
     {
         int ans=0;
         int pnum=0;
         int temp;
         for(int i=0;i<n;++i)
         {
             scanf("%d",&temp);
             if(temp<0)
             {
                 if(!pnum)ans++;
                 else pnum--;
             }else pnum+=temp;
         }
         printf("%d\n",ans);
     }
    return 0;
}