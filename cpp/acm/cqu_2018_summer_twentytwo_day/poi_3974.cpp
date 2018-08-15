#include <stdio.h>
#include <string.h>

#define min(a,b) (a<b? a:b)
#define max(a,b) (a>b? a:b)
#define INF 1000005

char str[INF];
char s[INF*2];
int arr[INF*2];

int manachar()
{
    int len=strlen(str);
    int len2=0;
    for(int i=0;i<len;++i)
    {
        s[len2++]='#';
        s[len2++]=str[i];
    }
    s[len2++]='#';
    s[len2]='\0';
    arr[0]=1;
    arr[1]=2;
    int mx=2;
    int id=1;
    for(int i=2;i<len2;++i)
    {
        arr[i] = mx>i? min(arr[id*2-i],mx-i):1;
        while(i-arr[i]>=0&&i+arr[i]<len2&&s[i-arr[i]]==s[i+arr[i]])arr[i]++;
        if(i+arr[i]-1>mx)
        {
            mx = i+arr[i]-1;
            id = i;
        }
    }
    int ans=-1;
    for(int i=0;i<len2;++i)
        ans = max(ans,arr[i]-1);
    return ans;
}

int main()
{
    while(true)
    {
        static int o=0;
        scanf("%s",str);
        if(strcmp(str,"END")==0)break;
        printf("Case %d: %d\n",++o,manachar());
    }
    return 0;
}