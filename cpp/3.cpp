#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> ansd,ans;
    freopen("ans.txt","r",stdin);
    int a;
    while(~scanf("%d",&a))
    {
        ans.push_back(a);
    }
    fclose(stdin);
    freopen("ansd.txt","r",stdin);
    while(~scanf("%d",&a))
    {
        ansd.push_back(a);
    }
    for(int i=0;i<ans.size();++i)
    {
        if(ansd[i]!=ans[i])
        {
            printf("%d",i);
            system("pause");
        }
    }
    return 0;
}