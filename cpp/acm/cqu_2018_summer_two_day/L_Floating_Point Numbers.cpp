#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a;
    scanf("%lf",&a);
    printf("%lf",a);
    double we=0.5;
    double je=1;
    double ans[20][40];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<10;++i)
    {
        je=2;
        for(int k=1;k<=30;++k)
        {
            ans[i][k]=we*je;
            je=(2*je*je);
        }
        we=we/2+0.5;
    }
    return 0;
}