#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 500005

using namespace std;

int que[INF];
int quj[INF];

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    int l,n,m;
    while(~scanf("%d%d%d",&l,&n,&m))
    {
        for(int i=0;i<n;++i)
            scanf("%d",que+i);
        sort(que,que+n);
        quj[0]=que[0];
        quj[n]=l-que[n-1];
        for(int i=1;i<n;++i)
            quj[i]=que[i]-que[i-1];
        int high=l,low=0x7fffffff;
        for(int i=0;i<=n;++i)
            low=min(quj[i],low);
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int temp=0;
            int nm=0;
            for(int i=0;i<=n;++i)
            {
                temp+=quj[i];
                nm++;
                if(temp>mid)
                {
                    temp=0;
                    nm--;
                }                           //最少去掉nm个石头，使所有的距离大于mid
            }
            if(nm>m)high=mid-1;             //一直往下逼，直到过界，           如果nm大于m，则去掉m个石头，最小距离小于mid所以 ans<=mid-1 ，********当mid为答案时，因为上面使所有的距离大于mid，必定会使nm>m,此时low为mid，
            else low=mid+1;                 //保证答案大于等于low              如果nm小于m,则去掉m个石头，最小距离大于mid.  如果nm等于m，最小距离大于mid

            /*
            当(low+high)>>1大于ans时nm大于m（充要条件）,high减小
            当(low+high)>>1小于ans时nm小于等于m（充要条件），low增大
            当(low+high)>>1等于ans时nm大于m;high变为ans-1;若low=ans,跳出循环输出low，否则，(low+high)>>1小于ans，low增大，因为high=ans-1，low<high,所以low增大到high+1，跳出循环，结束增加，此时low=high+1=ans-1+1=ans;
            */
        }
        printf("%d\n",low);
    }
    return 0;
}
/*
16 6 6
1 3 6 10 13 15
*/
/*

16 6 6
1 3 6 10 13 15
16
16 6 5
1 3 6 10 13 15
6
16 6 4
1 3 6 10 13 15
4
16 6 3
1 3 6 10 13 15
3
16 6 2
1 3 6 10  13 15
3
16 6 1
1 3 6 10 13 15
1
16 6 0
1 3 6 10 13 15
1
8 3 1
1 2 5
2
8 3 2
1 2 5
3
25 5 2
2
14
11
21
17
4

11 7 0
1 3 4 6 7 9 10
1

*/