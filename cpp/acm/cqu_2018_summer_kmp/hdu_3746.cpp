#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

#define INF 100005

using namespace std;

int nexta[INF];
char str[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        getchar();
        int len=strlen(str);
        int ans=0;
        memset(nexta,0,sizeof(nexta));
        for(int i=1,pos=0;i<len;i++)
        {
            if(str[i]==str[pos])
            {
                nexta[i]=pos;
                pos++;
            }else
            {
                nexta[i]=pos;
                pos=0;
            }
        }
        int lst=str[len-1]==str[nexta[len-1]]? len-nexta[len-1]-1:len-nexta[len-1];
        if(len/lst==1||len%lst)ans=lst-len%lst;
        printf("%d\n",ans);
    }
    return 0;
}