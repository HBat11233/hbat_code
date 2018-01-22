#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct YQ
{
    int v;
    int m;
};

bool nding(int num,vector < YQ > & que)
{
    for(int i=0;i<que.size();++i)
    {
        for(int j=1;j<=que[i].m;++i)
        {
            if(num<(j*que[i].v))break;
            if(num==(j*que[i].v))return true;
            que[i].m-=j;
            if(nding(num-j*que[i].v,que))return true;
            que[i].m+=j;
        }
    }
    return false;
}

int main()
{
    int n;
    while(cin>>n,n>0)
    {
        vector <YQ> que(n);
        int sum=0;
        int avg=0;
        for(int i=0;i<n;++i)
        {
            cin>>que[i].v>>que[i].m;
            sum+=que[i].v*que[i].m;
        }
        avg=(float)sum/2.0+0.5;
        for(int i=avg;;++i)
            if(nding(i,que))
            {
                cout<<i<<' '<<sum-i<<endl;
                break;
            }
    }
    return 0;
}