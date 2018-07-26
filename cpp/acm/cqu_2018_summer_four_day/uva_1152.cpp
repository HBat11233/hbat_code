#include <bits/stdc++.h>

//#define DEBUG

using namespace std;
int que[16000005];
int que2[16000005];

int findAnser(const int &num,long long l,long long r)//二分查找
{
    if(l==r)
    {
        if(num!=que2[l])return 0;
        else return 1;
    }
    long long mid=(l+r)>>1;
    if(num==que2[mid])
    {
        int ans=0;
        for(int i=mid;que2[i]==num&&i>=l;i--)ans++;
        for(int i=mid+1;que2[i]==num&&i<=r;++i)ans++;
        return ans;
    }
    if(num<que2[mid]&&l<=mid)return findAnser(num,l,mid);               //l<=mid,,,,....注意不符合l<mid且符合num<que2[mid],会导致异常
    if(num>que2[mid]&&mid<r)return findAnser(num,mid+1,r);
}

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        int q1[4005],q2[4005],q3[4005],q4[4005];
        for(int i=0;i<n;++i)
            scanf("%d%d%d%d",q1+i,q2+i,q3+i,q4+i);
        int len=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                que[len]=q1[i]+q2[j];
                que2[len++]=q3[i]+q4[j];
            }
        sort(que,que+len);
        sort(que2,que2+len);
        for(int i=0;i<len;++i)
            ans+=findAnser(-que[i],0,len-1);
        printf("%d\n",ans);
        if(t)printf("\n");
    }
    return 0;
}