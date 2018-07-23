#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 100005

using namespace std;

int ar[INF];
int ans[INF];

struct mat
{
    int num;
    int pos;
    bool operator <(const mat &b)
    {
        if(num==b.num)return pos<b.pos;
        else return num<b.num;
    }
}arr[INF];

int findma(const int &b,const int &e,const int &num)
{
    if(e-b==1)
    {
        if(arr[e].num<num)return e;
        else return b;
    }
    int d=(b+e)/2;
    if(arr[d].num==num)return d-1;
    else if(arr[d].num>num)return findma(b,d,num);
    else return findma(d,e,num);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,-1,sizeof(ans));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i].num),arr[i].pos=i;
        sort(arr,arr+n);
        for(int i=0;i<n;++i)
        {
            int rnum=MOD-arr[i].num;
            int pos=findma(0,n-1,rnum);
                if(pos<n&&i!=pos)
                {
                    ans[i]=max(ans[i],(arr[i].num+arr[pos].num)%MOD);
                    ans[pos]=max(ans[pos],(arr[i].num+arr[pos].num)%MOD);
                }
                if(pos-1>=0&&i!=pos-1)
                {
                    ans[i]=max(ans[i],(arr[i].num+arr[pos-1].num)%MOD);
                    ans[pos-1]=max(ans[pos-1],(arr[i].num+arr[pos-1].num)%MOD);
                }
            pos=n-1;
            if(pos<n&&i!=pos)
            {
                ans[i]=max(ans[i],(arr[i].num+arr[pos].num)%MOD);
                ans[pos]=max(ans[pos],(arr[i].num+arr[pos].num)%MOD);
            }
            if(pos-1>=0&&i!=pos-1)
            {
                ans[i]=max(ans[i],(arr[i].num+arr[pos-1].num)%MOD);
                ans[pos-1]=max(ans[pos-1],(arr[i].num+arr[pos-1].num)%MOD);
            }
        }
        for(int i=0;i<n;++i)
        {
            ar[arr[i].pos]=ans[i];
        }
        for(int i=0;i<n;++i)
            printf("%d ",ar[i]);
        printf("\n");
    }
    return 0;
}