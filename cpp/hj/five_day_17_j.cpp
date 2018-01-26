#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int a[1<<20];
int b[1<<20];
int len[22];
int main()
{
    int n,m;
    int *f0,*f1;
    vector< vector <int> >data;
    scanf("%d%d",&n,&m);
    data.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",len+i);
        data[i].resize(len[i]);
        for(int j=0;j<len[i];++j)
        {
            int aa;
            scanf("%d",&aa);
            data[i][j]=1<<(aa-1);
        }
    }
    f0=a;
    f1=b;
    int temp=(1<<m)-1;
    for(int k=temp;k>0;--k)
        for(int j=0;j<data[1].size();++j)
            if(k&data[1][j])
                f0[k]+=1;
    for(int i=2;i<=n;++i)
    {
        for(int k=temp;k>0;--k)
        {
            if(!f0[k])continue;//从超时边缘拉回我的if
            for(int j=0;j<len[i];++j)
                if((k&data[i][j]))
                    f1[k]+=f0[k^data[i][j]];
        }
        swap(f0,f1);
        memset(f1,0,sizeof(a));
    }    
    printf("%d\n",f0[(1<<m)-1]);
    return 0;
}

/*
    #include<cstdio>  
    #include<cstring>  
    #include<algorithm>  
    using namespace std;  
    #define maxm 22  
    int dp[2][1<<20],a[maxm][maxm];  
    //dp[i][j]表示第i头在第j中状态下的方法数，a[i][j]表示第i头牛能在第j个牛圈里   
    int main()  
    {  
        int n,m,k,i,j,cnt,num;  
        while(scanf("%d%d",&n,&m)!=EOF)  
        {  
            memset(a,0,sizeof(a)); 
            for(i=1;i<=n;++i)  
            {  
                scanf("%d",&cnt);  
                while(cnt--)  
                {  
                    scanf("%d",&num);  
                    a[i][num-1]=1;//为了方便运算把牛圈的编号变为从0~m-1   
                }  
            }  
            memset(dp,0,sizeof(dp));  
            dp[0][0]=1;  
            for(i=1;i<=n;++i)  
            {  
                for(j=0;j<(1<<m);++j)  
                {  
                    if(dp[1-(i&1)][j])//表示前一头牛在j状态下有值   
                    {  
                        for(k=0;k<m;++k)  
                        {  
                            if(a[i][k]&&(j!=(j|(1<<k))))//表示第i头牛能放进k位置且k位置没有其他的牛   
                                dp[i&1][j|(1<<k)]+=dp[1-(i&1)][j];  
                        }  
                    }  
                }  
                memset(dp[1-(i&1)],0,sizeof(dp[1-(i&1)]));  
            }  
            int ans=0;  
            for(i=1;i<(1<<m);++i)//统计所有结果   
                ans+=dp[n&1][i];
            printf("%d\n",ans);  
        }  
        return 0;  
    }   
    */