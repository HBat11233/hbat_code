#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

map<int,long long>pos;
map<long long,int>ans;

int g(const long long & m)
{
    if(ans.count(m))return ans[m];
    if(m==1)return ans[m]=1;
    if(m==2)return ans[m]=2;
    return ans[m]=(g(m-1)+g(m-2)+(((m-1)%MOD)*((m-1)%MOD))%MOD)%MOD;
}

int main()
{
    int t;
    freopen("10.txt","w",stdout);
    long long m=0;
    scanf("%d",&t);
    while(t--)
    {
        m++;
        //scanf("%d",&m);
        if(pos.count(g(m)))
        {
            cout<<endl;
            cout<<pos[g(m)]<<endl<<m<<endl<<g(m)<<endl;
            //system("pause");
        }
        pos[g(m)]=m;
        //printf("%d\n",g(m));

    }
    return 0;
}