#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define size 1008
#define MAX 99999999
double tree[size][size],x[size],y[size]; 
double low[size];
bool flag[size]={1};
double prim(int n)
{
    double sum = 0;
	int i,k,time=1;
    for(i = 1; i < n; i++)
        low[i] = tree[0][i];
    while(time<=n-1)
	{
        double min = MAX;
        int j = 0;
        for(k = 1; k < n; k++)
            if( low[k] < min && flag[k]==false )
            {
                min = low[k];
                j = k;
            }
        sum += min;
        flag[j] = true;
        for(k = 1; k < n; k++)
            if(tree[j][k] < low[k]&&flag[k]==false)
                low[k] = tree[j][k];
			time++;
    }
    return sum;
}
int main()
{       

	int n,m,i=0,j,num,c,d;
	double xx,yy,a,b;
	cin>>n>>m;
	num=n;
	while(n--)
	{
		cin>>a>>b;
		x[i]=a;
		y[i]=b;
		i++;
	}
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
		{
			if(i==j)//刚开始的时候这条语句我写成了赋值语句，寒！！！！！！
				tree[i][i]=MAX;//自己与自己不能联通，距离把他设为+∞
			else
			{
				xx=fabs(x[i]-x[j]);
				yy=fabs(y[i]-y[j]);
				tree[i][j]=sqrt( xx*xx+yy*yy );//各个村庄的距离
			}
		}
	
	
	while(m--)
	{
		cin>>c>>d;
		tree[c-1][d-1]=0;
		tree[d-1][c-1]=0;//标记已经建好的路，我就是这条语句没有加上去，所以WA了几次
	}
	n=num;
	cout<<setprecision(2)<<fixed<<prim(n)<<endl;
    system("pause");0
    return 0;
}