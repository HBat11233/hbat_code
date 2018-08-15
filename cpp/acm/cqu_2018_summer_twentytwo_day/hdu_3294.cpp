#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define INF 200005

using namespace std;

char str[INF];
char ch;
char s[INF*2];
int arr[INF*2];
int b,e;
char book[26];

void manachar()
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
        arr[i]= mx>i? min(arr[id*2-i],mx-i):1;
        while(i-arr[i]>=0&&i+arr[i]<len2&&s[i-arr[i]]==s[i+arr[i]])arr[i]++;
        if(i+arr[i]-1>mx)
        {
            mx=i+arr[i]-1;
            id=i;
        }
    }
    int pos=0;
    for(int i=0;i<len2;++i)
        pos = arr[pos]>=arr[i]? pos:i;
    b=pos-arr[pos]+1;
    b/=2;
    e=b+arr[pos]-2;
}

int main()
{
    while(ch=getchar(),ch!=-1)
    {
        scanf("%s",str);
        for(int i=0;i<26;++i)
            book[(i+ch-'a')%26]=i+'a';
        getchar();
        manachar();
        if(e-b>=1)
        {
            printf("%d %d\n",b,e);
            for(int i=b;i<=e;++i)
                printf("%c",book[str[i]-'a']);
        }else printf("No solution!");
        printf("\n");
    }
    return 0;
}