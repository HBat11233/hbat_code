#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len;
        int n;
        char str[10004];
        scanf("%d%d\n",&len,&n);
        for(int i=0;i<len;++i)
            scanf("%c",&str[i]);
        str[len]='\0';
        int nt[30][10004];
        memset(nt,-1,sizeof(nt));
        for(int i=0;i<n;++i)
        {
            int l,r;
            char ch;
            scanf("%d%d\n",&l,&r);
            scanf("%c",&ch);
            l--;
            int x=l/len;
            int y=r/len;
            int c=l%len;
            int d=r%len;
            if(nt[ch-'a'][len]==-1)
            {
                nt[ch-'a'][0]=0;
                if(str[0]==ch)nt[ch-'a'][1]=1;
                else nt[ch-'a'][1]=0;
                for(int i=1;i<len;++i)
                    if(str[i]==ch)
                        nt[ch-'a'][i+1]=nt[ch-'a'][i]+1;
                    else
                        nt[ch-'a'][i+1]=nt[ch-'a'][i];
            }
            printf("%d\n",nt[ch-'a'][len]*(y-x)+nt[ch-'a'][d]-nt[ch-'a'][c]);
        }
    }
    return 0;
}