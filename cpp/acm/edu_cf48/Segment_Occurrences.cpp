#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    string s,t;
    cin>>s>>t;
    int arr[1005]={0};
    memset(arr,0,sizeof(arr));/*
    for(int i=0;i<=(n-m);++i)
        if(s.substr(i,m)==t)arr[i]=1;
    for(int i=0;i<q;++i)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=l-1;i<=r-m;++i)
            if(arr[i])ans++;
        printf("%d\n",ans);
    }
    */
    for(int i=0;i<=(n-m);++i)
        if(s.substr(i,t.size())==t)arr[i+1]=arr[i]+1;
        else arr[i+1]=arr[i];
    for(int i=0;i<q;++i)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",(r-m+1>=0&&l-1>=0&&r-m+1>=l-1)? arr[r-m+1]-arr[l-1]:0);
    }
    return 0;
}