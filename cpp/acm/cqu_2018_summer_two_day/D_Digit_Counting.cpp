#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int ans[10]={0};
        for(int i=1;i<=n;++i)
        {
            int k=i;
            while(k)
            {
                int a=k%10;
                k/=10;
                ans[a]++;
            }
        }
        for(int i=0;i<10;++i)
        {
            printf("%d",ans[i]);
            if(i!=9)printf(" ");//卡
        }
        printf("\n");//卡
    }
    return 0;
}
//垃圾题。。。