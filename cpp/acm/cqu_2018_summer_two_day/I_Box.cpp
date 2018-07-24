#include <bits/stdc++.h>

using namespace std;

struct mb
{
    int w;
    int h;
    mb():w(0),h(0){}
    bool operator <(const mb &b)
    {
        if(w==b.w)return h<b.h;
        else return w<b.w;
    }
    bool operator ==(const mb &b)
    {
        return w==b.w&&h==b.h;
    }
}arr[6];

int main()
{
    while(~scanf("%d%d",&arr[0].w,&arr[0].h))
    {
        for(int i=1;i<6;++i)
            scanf("%d%d",&arr[i].w,&arr[i].h);
        for(int i=0;i<6;++i)
            if(arr[i].w>arr[i].h)swap(arr[i].w,arr[i].h);
        sort(arr,arr+6);
        if(arr[0]==arr[1]&&arr[2]==arr[3]&&arr[4]==arr[5]&&
           arr[0].w==arr[2].w&&arr[0].h==arr[4].w&&arr[2].h==arr[4].h)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}