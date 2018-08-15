#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 100005

using namespace std;

char book[26];
char rbook[26];
char str[INF*2];
int nex[INF*2];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",book,str);
        int len=strlen(str);
        nex[0]=-1;
        int i=len%2? len/2:len/2-1,pos=-1;
        for(int i=0;i<26;++i)
            rbook[book[i]-'a']=i+'a';
        while(i<len)
        {
            if(pos==-1||book[str[i]-'a']==str[pos])
                nex[++i]=++pos;
            else
                pos=nex[pos];
        }
        len-=nex[len];
        str[len]='\0';
        printf("%s",str);
        for(int i=0;i<len;++i)
            printf("%c",rbook[str[i]-'a']);
        printf("\n");
    }
    return 0;
}