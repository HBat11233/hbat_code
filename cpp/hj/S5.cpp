#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;++k)
    {
        int n;
        scanf("%d",&n);
        vector <int> que(n);
        for(int i=0;i<n;++i)
            scanf("%d",&que[i]);
        for(int i=1;i<n;++i)
        {
            for(int j=i;j>0;--j)
            {
                if(que[j-1]<que[j])
                {
                    que[j-1]++;
                    que[j]--;
                    swap(que[j-1],que[j]);
                    if(j==1&&que[j-1]<que[j])
                        goto fin;
                    else if(que[j-2]>=que[j-1]&&que[j-1]<que[j])
                        goto fin;
                }
            }
        }
        cout<<"Case "<<k<<": "<<"Yes"<<endl;
        continue;
        fin:
        cout<<"Case "<<k<<": "<<"No"<<endl;
    }
    return 0;
}