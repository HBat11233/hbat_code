#include <bits/stdc++.h>

using namespace std;

map<int,map<int,int> >book;

long long fun(int k,int x)
{
    if(x==0)return 0;
    if(book.count(k)&&book[k].count(x))return book[k][x];
    int mid=1<<(k-1);
    if(x<=mid)book[k][x]=(fun(k-1,x)<<1);
    else book[k][x]=(fun(k-1,mid)<<1)+fun(k-1,x-mid);
    return book[k][x];
}

int main()
{
    int t;
    book[0][1]=1;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        long long ans=0;
            ans+=fun(k,b)-fun(k,a-1);
        printf("Case %d: %lld\n",o,ans);
    }
    return 0;
}

