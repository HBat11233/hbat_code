#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int stu[51][7];
double p[51];
double c[51];

int main()
{
    int ans;
    while(cin>>n>>m)
    {
        ans=0;
        memset(stu,0,sizeof(stu));
        memset(p,0,sizeof(stu));
        memset(c,0,sizeof(stu));

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>stu[i][j];
            }
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                p[i]+=stu[i][j];
            p[i]/=m;
        }

        for(int j=0;j<m;++j)
        {
            for(int i=0;i<n;++i)
                c[j]+=stu[i][j];
            c[j]/=n;
        }
        for(int j,i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(stu[i][j]<c[j])break;
            }
            if(j>=m)ans++;
        }

        for(int i=0;i<n;++i)
        {
            printf("%.2lf",p[i]);
            if(i!=n-1)cout<<' ';
        }
        cout<<endl;
        for(int i=0;i<m;++i)
        {
            printf("%.2lf",c[i]);
            if(i!=m-1)cout<<' ';
        }
        cout<<endl;
        cout<<ans<<endl<<endl;
    }
    return 0;
}
