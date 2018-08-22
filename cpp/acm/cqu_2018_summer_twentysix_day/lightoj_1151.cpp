//https://blog.csdn.net/kg20006/article/details/51065559
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <math.h>

#define INF 105
#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

<<<<<<< HEAD
int book[105];
=======
double matix[INF][INF];
int book[105];

void gauss()
{
    for(int i=1;i<=100;++i)
    {
        int mx=1;
        for(int j=i;j<=100;++j)
            mx = fabs(matix[j][i])>(matix[mx][i])? j:mx;
        if(mx!=i)
            for(int j=1;j<=101;++j)
                swap(matix[i][j],matix[mx][j]);
        for(int j=101;j>=i;--j)
            matix[i][j]/=matix[i][i];
        for(int j=i+1;j<=100;++j)
            for(int k=101;matix[j][i]&&k>=i;--k)
                matix[j][k]-=matix[i][k]*matix[j][i];
    }
    for(int i=100;i>1;--i)
        for(int j=i-1;j>0;--j)
            matix[j][101]-=matix[i][101]*matix[j][i];
}
>>>>>>> 073f2c53519f0bea5d58b889693ed30baa89aab1

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        mst(book,-1);
        mst(matix,0);
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            book[a]=b;
        }
<<<<<<< HEAD

=======
        matix[100][100]=1;
        matix[100][101]=0;
        for(int i=1;i<100;++i)
        {
            if(book[i]!=-1)
            {
                matix[i][i]=1;
                matix[i][book[i]]=-1;
                matix[i][101]=0;
            }
            else
            {
                int k=0;
                for(int j=1;j<=6;++j)
                {
                    if(i+j>100)break;
                    matix[i][i+j]=-1;
                    k++;
                }
                matix[i][i]=k;
                matix[i][101]=6;
            }
        }
        gauss();
        cout<<"Case "<<o<<": "<<setprecision(8)<<fixed<<matix[1][101]<<endl;
>>>>>>> 073f2c53519f0bea5d58b889693ed30baa89aab1
    }
    return 0;
}