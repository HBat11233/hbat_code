#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char msp[12][12]; 
int kl[2][8];
bool sp[12][12];

int main()
{
    while(~scanf("%s",*(msp+1)+1))
    {
        memset(sp,0,sizeof(0));
        kl[0][0]=0x7f;
        kl[1][0]=0x7f;
        kl[0][1]=0x7f;
        kl[1][1]=-1;
        kl[0][2]=-1;
        kl[1][2]=0x7f;
        kl[0][3]=-1;
        kl[1][3]=-1;
        kl[0][4]=0x7f;
        kl[1][4]=-2;
        kl[0][5]=-1;
        kl[1][5]=-2;
        kl[0][6]=-2;
        kl[1][6]=0x7f;
        kl[0][7]=-2;
        kl[1][7]=-1;
        for(int i=2;i<=10;++i)
            for(int j=1;j<=10;++j)
                cin>>msp[i][j];
        for(int i=1;i<=10;++i)
            for(int j=1;j<=10;++j)
                if(msp[i][j]=='#')
                {
                    if(i<=kl[0][0]&&j<=kl[1][0])
                    kl[0][0]=i,
                    kl[1][0]=j;
                    if(i<=kl[0][1]&&j>=kl[1][1])
                    kl[0][1]=i,
                    kl[1][1]=j;
                    if(i>=kl[0][2]&&j<=kl[1][2])
                    kl[0][2]=i,
                    kl[1][2]=j;
                    if(i>=kl[0][3]&&j>=kl[1][3])
                    kl[0][3]=i,
                    kl[1][3]=j;
                    if(i<kl[0][4])
                    kl[0][4]=i,
                    kl[1][4]=j;
                    if(i>kl[0][5])
                    kl[0][5]=i,
                    kl[1][5]=j;
                    if(j<kl[1][6])
                    kl[0][6]=i,
                    kl[1][6]=j;
                    if(j>kl[1][7])
                    kl[0][7]=i,
                    kl[1][7]=j;
                }
        int num=0; 
        for(int i=0;i<8;++i)
        {
            if(!sp[kl[0][i]][kl[1][i]])
            {
                sp[kl[0][i]][kl[1][i]]=true;
                num++;
            }
        }
        if(num>3)cout<<"4 bian *\n";
            else cout<<"3 jiao *\n";
    }
    return 0;
}/*
..........
..........
..........
....#.....
...#.#....
..#...#...
...#.#....
....#.....
..........
..........
error
*/