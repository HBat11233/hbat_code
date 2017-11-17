#include <iostream>
#include <cstdio>

using namespace std;

int t;
int n;
int a[10];
int b[10];

inline int yf(int &x,int &y)
{
    int p=min(x,y);
    for(int i=p;i>0;--i)
    {
        if(x%i==0&&y%i==0)
        {
            x/=i;
            y/=i;
            return 0;
        }
    }
    return 0;
}

int main()
{
    cin>>t;
    for(int i=0;i<t;++i)
    {
        scanf("%d",&n);
        for(int j=0;j<n;++j)
            scanf("%d",a+j);
        for(int j=0;j<n;++j)
            scanf("%d",b+j);
        for(int i=n-1;i>0;--i)
        {
        	yf(b[i],a[i]);
       		a[i-1]=a[i-1]*a[i]+b[i];
        	b[i-1]*=a[i];
		}
			yf(b[0],a[0]);
            cout<<"Case #"<<i+1<<": "<<b[0]<<' '<<a[0]<<endl;
    }
//    system("pause");
    return 0;
}
