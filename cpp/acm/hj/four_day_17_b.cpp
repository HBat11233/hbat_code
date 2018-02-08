#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct WP
{
    char a;
    char b;
    int leng;
    WP(const char a=0,const char b=0,const int leng=0)
        :a(a),b(b),leng(leng){}
};

int father[100];

void qsort(int b,int e,WP *w)
{
    int bl=w[(b+e)/2].leng;
    int i=b,j=e;
    while(i<=j)
    {
        while(w[i].leng<bl)++i;
        while(w[j].leng>bl)--j;
        if(i<=j)
        {
            swap(w[i],w[j]);
            i++;
            j--;
        }
    }   
    if(i<e)qsort(i,e,w);
    if(b<j)qsort(b,j,w);
}

int findb(int x)
{
    if(father[x]!=x) father[x]=findb(father[x]);
    return father[x];
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int m=0;
        int ans=0;
        WP w[100];
        for(int i=0;i<100;++i)
            father[i]=i;
        for(int i=1;i<n;++i)
        {
            char a;
            int x;
            cin>>a>>x;
            for(int j=0;j<x;++j)
            {
                char b;
                int y;
                cin>>b>>y;
                w[m].a=a;
                w[m].b=b;
                w[m].leng=y;
                m++;
            }
        }
        qsort(0,m-1,w);
        int k=0;
        while(k<m)
        {
            int x=findb(w[k].a);
            int y=findb(w[k].b);
            if(x!=y)
            {
                father[x]=y;
                ans+=w[k].leng;
            }
            k++;
        }
        cout<<ans<<endl;
    }
    return 0;
}