//hdu1051
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#define INF 5001
#define MST(a,b) memset(a,b,sizeof(a)) 

using namespace std;

struct LS
{
    int l;
    int w;
}arr[INF];

vector <int> ansarr;

bool _comp(const LS & a,const LS & b)
{
    if(a.l==b.l)return a.w<=b.w;
    else return a.l<=b.l;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        MST(arr,0);
        ansarr.clear();
        for(int i=0;i<n;++i)
            scanf("%d%d",&arr[i].l,&arr[i].w);
        sort(arr,arr+n,_comp);
        for(int i=0,j=0;i<n;++i)
        {
            int tmp=-1;
            for(j=0;j<ansarr.size();++j)
                tmp = arr[ansarr[j]].w<=arr[i].w? (tmp==-1?j:(arr[ansarr[j]].w>arr[ansarr[tmp]].w? j:tmp)):tmp;
            if(!~tmp)ansarr.push_back(i);
            else ansarr[tmp]=i;
        }
        printf("%d\n",ansarr.size());
    }
    //system("pause");
    return 0;
}