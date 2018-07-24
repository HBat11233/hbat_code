#include <bits/stdc++.h>

using namespace std;

char maps[5][5];
int x,y;
int t=0;
bool read()
{
    memset(maps,0,sizeof(maps));
    if(scanf("%c",&maps[0][0])==-1)return false;
    if(maps[0][0]=='Z')return false;
    if(maps[0][0]==' ')x=0,y=0;
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            if(i+j!=0)maps[i][j]=getchar();
            if(maps[i][j]==' ')x=i,y=j;
        }
        getchar();
    }
    return true;
}

void write()
{
    printf("Puzzle #%d:\n",t);
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            printf("%c",maps[i][j]);
            if(j!=4)printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    while(read())
    {
        if(t)printf("\n");
        t++;
        bool can=false;
        char ch=' ';
        while(ch!='0')
        {
            ch=getchar();
            while(ch==' '||ch=='\n')
                ch=getchar();
            if(can)continue;
            switch(ch)
            {
                case 'A':
                    if(x-1<0)
                        can=true;
                    else
                    {
                        swap(maps[x][y],maps[x-1][y]);
                        x--;
                    }
                    break;
                case 'R':
                    if(y+1>=5)
                        can=true;
                    else
                    {
                        swap(maps[x][y],maps[x][y+1]);
                        y++;
                    }
                    break;
                case 'B':
                    if(x+1>=5)
                        can=true;
                    else
                    {
                        swap(maps[x+1][y],maps[x][y]);
                        x++;
                    }
                    break;
                case 'L':
                    if(y-1<0)
                        can=true;
                    else
                    {
                        swap(maps[x][y],maps[x][y-1]);
                        y--;
                    }
                    break;
            }
        }
        getchar();
        if(can)printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",t);
        else write();
    }
    return 0;
}

/*

TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS 
TUVWX
AAA 
LLLL0
ABCDE
FGHIJ
KLMNO
PQRS 
TUVWX
AAAAABBRRRLL0
Z


*/