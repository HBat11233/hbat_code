#include <cstdio>
#include <iostream>


#pragma (disable :4996)

using namespace std;

struct SQ
{
    int fnum[4]; 
};

SQ mps[6][6];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int t;
int n;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int temp=n*n;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int z=0;z<4;++z)
                    scanf("%d",mps[i][j].fnum+z);
        
    }
    return 0;
}