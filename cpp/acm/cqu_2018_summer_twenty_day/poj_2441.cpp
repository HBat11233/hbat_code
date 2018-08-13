#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int a[1<<20];
int b[1<<20];
int len[22];
int main()
{
    int n,m;
    int *f0,*f1;
    vector< vector <int> >data;
    scanf("%d%d",&n,&m);
    data.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",len+i);
        data[i].resize(len[i]);
        for(int j=0;j<len[i];++j)
        {
            int aa;
            scanf("%d",&aa);
            data[i][j]=1<<(aa-1);
        }
    }
    f0=a;
    f1=b;
    int temp=(1<<m)-1;
    for(int k=temp;k>0;--k)
        for(int j=0;j<data[1].size();++j)
            if(k&data[1][j])
                f0[k]+=1;
    for(int i=2;i<=n;++i)
    {
        for(int k=temp;k>0;--k)
        {
            if(!f0[k])continue;
            for(int j=0;j<len[i];++j)
                if((k&data[i][j]))
                    f1[k]+=f0[k^data[i][j]];
        }
        swap(f0,f1);
        memset(f1,0,sizeof(a));
    }    
    printf("%d\n",f0[(1<<m)-1]);
    return 0;
}
