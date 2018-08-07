#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 10005

using namespace std;

int arr1[INF*100];
int arr2[INF];
int nexta[INF];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d",&arr1[i]);
        for(int i=0;i<m;++i)
            scanf("%d",&arr2[i]);
        memset(nexta,0,sizeof(nexta));
        for(int i=1,pos=0;i<m;++i)
        {
            
            if(arr2[i]==arr2[pos])
            {
                nexta[i]=nexta[pos];
                pos++;
            } 
            else 
            {
                nexta[i]=pos;
                pos=0;
            }
        }
        nexta[0]=-1;
        int ans=-1;
        for(int i=0,j=0;i<n;)
        {
            if(arr1[i]==arr2[j])
                i++,j++;
            else
            {
                j=nexta[j];
                if(j==-1)
                    j++,i++;
            }
            if(j==m){ans=i-m+1;break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}