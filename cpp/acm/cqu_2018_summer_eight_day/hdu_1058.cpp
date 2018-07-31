#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

#define INF 2000000000

using namespace std;

long long ans[6000];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG 

    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    ans[4]=5;
    ans[5]=7;
    int pos=6;
    map<int,bool>book;
    for(int i=2;i<=5;++i)
    {
        for(int j=i;j<pos;++j)
        {
            long long temp=ans[i]*ans[j];
            if(temp>INF)continue;
            if(!book[temp])
            {
                ans[pos++]=ans[i]*ans[j];
                book[temp]=true;
            }
        }
    }
    sort(ans+1,ans+pos);
    int n;
    while(scanf("%d",&n),n)
    {
        int a=n%10;
        if(n%100==11||n%100==12||n%100==13)a=0;//英语没学好
        if(a==1)
                printf("The %dst humble number is %lld.\n",n,ans[n]);
        else if(a==2)
                printf("The %dnd humble number is %lld.\n",n,ans[n]);
        else if(a==3)
                printf("The %drd humble number is %lld.\n",n,ans[n]);
        else
                printf("The %dth humble number is %lld.\n",n,ans[n]);
                
    }
    return 0;
}
