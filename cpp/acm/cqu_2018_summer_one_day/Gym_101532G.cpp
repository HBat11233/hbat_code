#include <bits/stdc++.h>
#define INF 1000005

using namespace std;

struct sat
{
    int num;
    int pos;
    bool operator <(const sat &b)
    {
        if(this->num==b.num)
        return this->pos<b.pos;
        return this->num<b.num;
    }
}arr[INF];
int snm[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        memset(snm,0,sizeof(snm));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i].num);
            arr[i].pos=i;
        }
        sort(arr,arr+n);
        snm[0]=arr[0].pos;
        n--;
        for(int i=1;i<n;++i)
        {
            int temp=arr[i].pos-i;
            if(temp==0&&snm[i-1]==0)ans++;
            snm[i]=snm[i-1]+temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}