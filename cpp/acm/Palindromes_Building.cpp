#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int ans=-1;

struct mts
{
    char str[20];
    int al[27];
    int len;
    int size;
    mts()
    :len(0),size(0)
    {
        for(int i=0;i<20;++i)
            str[i]='\0';
        for(int i=0;i<27;++i)
            al[i]=0;
    }
};

int js(int ipos,mts &app)
{
    int sum=0;
    if(ipos==app.len)return 1;
    for(int i=0;i<app.size;++i)
    {
        mts n=app;
        if((--n.al[n.str[i]-'a'])==0)
        {
            char temp[20];
            int k=0;
            for(int j=0;j<n.size;++j)
            {
                if(j==i)continue;
                temp[k]=n.str[j];
                k++;
            }
            n.size=k;
            for(int j=0;j<k;++j)
                n.str[j]=temp[j];
        }
        sum+=js(ipos+1,n);
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ans=-1;
        scanf("%d\n",&n);
        char ch;
        int al[27];
        memset(al,0,sizeof(al));
        for(int i=0;i<n;++i)
        {
            ch=getchar();
            al[ch-'a']++;
        }
        int k=0;
        for(int i=0;i<'z'-'a';++i)
        {
            if(al[i]%2!=0)k++;
            if(k>1)
            {
                ans=0;
                break;
            }
        }
        if(ans)
        {
            mts tp;
            for(int i=0;i<'z'-'a';++i)
            {
                if(al[i]!=0)
                {
                    tp.str[tp.size]=i+'a';
                    tp.size++;
                }
            }
            tp.str[tp.size]='\0';
            for(int i=0;i<27;++i)
                tp.al[i]=al[i]/2;
            for(int i=0;i<tp.size;++i)
                tp.len+=tp.al[tp.str[i]-'a'];
            ans=js(1,tp);
        }
        printf("%d\n",ans);
    }
    return 0;
}