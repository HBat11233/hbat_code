#include <bits/stdc++.h>

using namespace std;

typedef size_t LL;

LL a,b,c;
struct matx
{
    int n;
    int m;
    int arr[4][4];
    void init()
    {
        n=0;
        m=0;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                arr[i][j]=0;
    }
    matx operator *(const matx & b)const
    {
        matx ans;
        ans.init();
        ans.n=n;
        ans.m=b.m;
        for(int i=0;i<ans.n;++i)
            for(int k=0;k<ans.m;++k)
                for(int l=0;l<m;++l)//m==b.n
                    ans.arr[i][k]+=(arr[i][l]*b.arr[l][k])%c,ans.arr[i][k]%=c;
        return ans;
    }
    matx operator %(const LL &b)const
    {
        return *this;
    }
};

template<typename T>
T spow(const T& a,const LL& b,const LL &n=0x7fffffffffffffff)
{
    T ans=a%n;
    T temp=a%n;
    LL mi=b;
    mi--;
    while(mi)
    {
        if(mi&1)ans=(ans*temp)%n;
        temp=(temp*temp)%n;
        mi>>=1;
    }
    return ans%n;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu%llu",&a,&b,&c);
        if(c==1||a==0)
        {
            printf("0\n");
            continue;
        }
        if(b==0)
        {
            printf("1\n");
            continue;
        }
        matx ne;
        matx fn;
        fn.n=2;fn.m=1;
        fn.arr[0][0]=0;fn.arr[1][0]=1;
        ne.n=2;ne.m=2;
        ne.arr[0][0]=0;ne.arr[1][1]=1;ne.arr[0][1]=1;ne.arr[1][0]=1;
        int fo[10005];
        fo[0]=0;fo[1]=1;
        for(int i=2;i<=6000;++i)
            fo[i]=(fo[i-1]+fo[i-2])%c;
        LL len=0;
        for(int i=1;i<=3000;++i)
        {
            int j;
            for(j=0;j<i;++j)
                if(fo[j]!=fo[j+i])break;
            if(j==i)
            {
                len=i;
                break;
            }
        }
        LL temp=spow(a,b,len);
        matx ans;
        if(temp!=0)
        {
            ans=spow(ne,temp);
            ans=ans*fn;
        }else ans=fn;
        printf("%d\n",ans.arr[0][0]);
    }
    return 0;
}
