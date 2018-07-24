#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string str;
        cin>>str;
        int ans=0;
        bool pk=false;
        int k=0;
        for(int i=1;i<=str.size()-k;)
        {
            if(!pk)k=i;
            if(str.substr(0,k)==str.substr(i,k))
            {
                if(!pk)
                {
                    ans=i;
                    pk=true;
                }
                i+=k;
            }else if(pk)
            {
                pk=false;
                i++;
                ans=0;
            }else i++;
        }
        if(!ans||str.size()%ans!=0)ans=str.size();
        printf("%d\n",ans);
        if(t!=0)printf("\n");
    }
    return 0;
}