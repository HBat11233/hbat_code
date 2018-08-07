#include<cstdio>
#include<cstring>

using namespace std;

bool pk(char ch)
{
    return ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
}

bool dp[2][55][6];
/*
dp0[i][j]表示字符串前i位能否组成末尾有连续j个元音字母
dp1[i][j]表示字符串前i位能否组成末尾有连续j个辅音字母
*/
int main()
{
    char str[55];
    int t;
    scanf("%d",&t);
    for(int cse=1; cse<=t; ++cse)
    {
        scanf("%s",str+1);
        int n=strlen(str+1);
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=dp[1][0][0]=1;
        bool bad=0;
        for(int i=1; i<=n; ++i)
        {
            if(str[i]=='?' || pk(str[i]))
            {
                for(int j=0; j<=1; ++j)
                {
                    if(dp[1][i-1][j])        //前一长度j状态存在，后移
                    {
                        dp[1][i][j+1]=1;
                        dp[0][i][0]=1;       //如果i+1是辅音的话，可以进入if
                    }
                }
                if(dp[1][i-1][2]) bad=1;     //前一长度j==2状态存在，后移，j==3或j==5的时候不存，如果推不出BAD,则最后j==3j==5会被改变，若一定是BAD，则确定之后，不会修改dp，下面可判断good，
            }
            if(str[i]=='?' || !pk(str[i]))
            {
                for(int j=0; j<=3; ++j)
                { 
                    if(dp[0][i-1][j])        //前一长度j状态存在，后移
                    {
                        dp[0][i][j+1]=1;
                        dp[1][i][0]=1;       //随i逐步初始化
                    }
                } 
                if(dp[0][i-1][4]) bad=1;     //前一长度j==4状态存在，后移
            }
        }
        bool good=0;
        for(int i=0;i<5;++i) 
            good|=(dp[0][n][i]|dp[1][n][i]);        //妙
        if(good && bad) printf("Case %d: MIXED\n",cse);
        else if(good) printf("Case %d: GOOD\n",cse);
        else printf("Case %d: BAD\n",cse);
    }
    return 0;
}