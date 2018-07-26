#include <bits/stdc++.h>

using namespace std;

int main()
{
    int que[40];
    int len=0;
    while(~scanf("%d",que+0))
    {
        int od[40];
        vector <int>ans;
        char ch=getchar();
        od[0]=que[0];
        while(ch!='\n')
            scanf("%d",que+(++len)),ch=getchar(),od[len]=que[len];
        len++;
        int mnum=-1,mpos=-1;
        int lm=0x7fffffff;
        for(int k=len-1;k>=0;--k)
        {
            for(int i=k;i>=0;--i)
            {
                if(que[i]<=lm&&que[i]>mnum)
                {
                    mnum=que[i];
                    mpos=i;
                }
            }
            if(k!=mpos)
            {
                int temp[40];
                if(mpos)
                {
                    ans.push_back(len-mpos);
                    for(int j=0;j<=mpos;++j)
                        temp[mpos-j]=que[j];
                    for(int j=0;j<=mpos;++j)
                        que[j]=temp[j];
                }
                ans.push_back(len-k);
                for(int j=0;j<=k;++j)
                    temp[k-j]=que[j];
                for(int j=0;j<=k;++j)
                    que[j]=temp[j];
            }
            lm=mnum;
            mnum=-1;
            mpos=-1;
        }
        for(int i=0;i<len;++i)
            printf("%d ",od[i]);
        printf("\n");
        for(int i=0;i<ans.size();++i)
            printf("%d ",ans[i]);
        printf("0\n");
        len=0;
    }
    return 0;
}