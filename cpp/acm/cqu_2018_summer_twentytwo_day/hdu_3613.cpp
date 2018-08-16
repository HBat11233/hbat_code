#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 500005
#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

char str[INF];
char s[INF*2];
int arr[INF*2];
int sum[INF];
int daarr[26];
int len;

void init()
{
    mst(s,0);
    mst(str,0);
    mst(arr,0);
    mst(sum,0);
    mst(daarr,0);
    for(int i=0;i<26;++i)
        scanf("%d",daarr+i);
    scanf("%s",str);
    len=strlen(str);
    sum[0]=daarr[str[0]-'a'];
    for(int i=1;i<len;++i)
        sum[i]=sum[i-1]+daarr[str[i]-'a'];
}

void manachar()
{
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
        arr[i] = mx > i? min(arr[id*2-i],mx-i):1;
        while(i-arr[i]>=0&&i+arr[i]<len2&&s[i-arr[i]]==s[i+arr[i]])arr[i]++;
        if(i+arr[i]-1>mx)
        {
            mx=i+arr[i]-1;
            id=i;
        }
    }
}

int sub(int l,int r)
{
    if(r<l)return 0;
    int mid=l+r+1;
    if(arr[mid]-1>=r-l+1)return l-1>=0? sum[r]-sum[l-1]:sum[r];
    else return 0;
}

void sol()
{
    int ans=0x80000000;
    for(int i=1;i<len-1;++i)//必须分成两个
    {
        int te=sub(0,i-1)+sub(i,len-1);
        ans=max(ans,te);
    }
    printf("%d\n",ans);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        manachar();
        sol();
    }
    return 0;
}

/*

#0#1#2#3#4#5#6
012345678

*/