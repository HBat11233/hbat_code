#include <bits/stdc++.h>

#define INF 100005

using namespace std;

int que[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;++o)
    {
        int n,s;
        scanf("%d%d",&n,&s);
        que[0]=0;
        for(int i=1;i<=n;++i)
        {
            int temp;
            scanf("%d",&temp);
            que[i]=que[i-1]+temp;
        }
        if(que[n]<s)
        {
            printf("0\n");
            continue;
        }
        int low=1,high=n;
        while(low<=high)
        {
            bool pk=false;
            int mid=((low+high)>>1);
            for(int i=mid;i<=n;++i)
                if(que[i]-que[i-mid]>=s)pk=true;
            if(pk)high=mid-1;
            else low=mid+1;
        }
        printf("%d\n",low);
    }
    return 0;
}

//ci que fa??
/*
#include <iostream>
    #include <algorithm>
    #include <cstring>
    #include<cstdio>
    using namespace std;
    int n,ss;
    int a[100005],s[100005];
    int main(){
        int t;
        cin>>t;
        while(t--){
            memset(a,0,sizeof(a));
            memset(s,0,sizeof(s));
            int kk=100005;
            cin>>n>>ss;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                s[i]=s[i-1]+a[i];
            }
            if(s[n]<ss)
                cout<<"0"<<endl;
            else
            {
                for(int i=1;s[i]+ss<=s[n];i++)
                {
                    int k=lower_bound(s+i,s+n+1,s[i]+ss)-s;
                    kk=min(kk,k-i);
                }
                cout<<kk<<endl;
            }
        }
        return 0;
    }
    */