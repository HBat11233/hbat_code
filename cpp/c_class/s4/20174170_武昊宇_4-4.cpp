#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>
#include <cmath>

inline bool mk(int i,int j,int a[][16])
{
    if(a[i][j]>a[i+1][j]&&a[i][j]>a[i-1][j]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i][j-1])return true;
    else return false;
}

int main()
{
    int a[16][16];
    memset(a,0,sizeof(a));
    srand(time(NULL));
    for(int i=0;i<16;++i)
        for(int j=0;j<16;++j)
            a[i][j]=rand()%100;
    for(int i=0;i<16;++i)
    {
        for(int j=0;j<16;++j)
            printf("%2d ",a[i][j]);
        printf("\n");
    }
    for(int i=0;i<16;++i)
    {
        for(int j=0;j<16;++j)
        {
            if(i==0||i==15||j==0||j==15)continue;
            if(mk(i,j,a))printf("(%d,%d)is maximal number!\n",i,j);
        }
    }
    system("pause");    
    return 0;
}