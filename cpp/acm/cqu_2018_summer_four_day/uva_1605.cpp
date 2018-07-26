#include <bits/stdc++.h>

using namespace std;

char anch[55];

void fun(int &n)
{
    printf("%d %d %d\n",2,n,n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            printf("%c",anch[j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            printf("%c",anch[i]);
        printf("\n");
    }
}

int main()
{
    int n;
    for(int i=0;i<26;++i)
        anch[i]='A'+i,anch[i+26]='a'+i;
    while(~scanf("%d",&n))
    {
        fun(n);
        printf("\n");
    }
    return 0;
}