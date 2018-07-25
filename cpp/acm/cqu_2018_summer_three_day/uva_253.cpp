#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int posans[25][6]=
    {
        {0,1,2,3,4,5},
        {0,2,4,1,3,5},
        {0,4,3,2,1,5},
        {0,3,1,4,2,5},

        {1,5,2,3,0,4},
        {1,2,0,5,3,4},
        {1,0,3,2,5,4},
        {1,3,5,0,2,4},

        {5,4,2,3,1,0},
    };
    for(int i=8;i<16;i+=4)
        for(int j=0;j<6;++j)
            posans[i][j]=posans[i-4][posans[4][j]];
    for(int j=0;j<6;++j)
            posans[16][j]=posans[1][posans[4][j]];
    for(int j=0;j<6;++j)
            posans[20][j]=posans[3][posans[4][j]];
    for(int k=5;k<24;k+=4)
        for(int i=0;i<3;++i)
            for(int j=0;j<6;++j)
                posans[k+i][j]=posans[k+i-1][posans[1][j]];
    while(cin>>str)
    {
        int i=0;
        for(i=0;i<24;++i)
        {
            string temp="";
            for(int j=0;j<6;++j)
                temp+=str[posans[i][j]];
            if(temp==str.substr(6,6))break;
        }
        if(i==24)printf("FALSE\n");
        else printf("TRUE\n");
    }
    return 0;
}