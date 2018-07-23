#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,pos=-1;
        scanf("%d%d",&n,&m);
        int arr[1005];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;++i)
        {
            scanf("%d",arr+i);
            if(pos==-1&&~arr[i])pos=i;
        }
        for(int j=pos;j<n;++j)
        {
            if(~arr[j])continue;
            arr[j]=(arr[j-1]+1)%m;
        }
        for(int j=pos;j>=0;--j)
        {
            if(~arr[j])continue;
            if(!arr[j+1])arr[j]=m-1;
            else arr[j]=arr[j+1]-1;
        }
        for(int i=0;i<n;++i)
            printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}