#include <bits/stdc++.h>

using namespace std;

struct qi
{
    char ch;
    int x;
    int y;
};

char maps[12][12];
bool wse[12][12];
/*
void print()
{
    cout<<endl;
    for(int i=1;i<=10;++i)
    {
        for(int j=1;j<=9;++j)
        {
            cout<<(maps[i][j]=='\0'? '-':maps[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=10;++i)
    {
        for(int j=1;j<=9;++j)
            cout<<int(wse[i][j]);
        cout<<endl;
    }
    cout<<endl;
}
*/
int main()
{
    int n,x,y;
    while(cin>>n>>x>>y,n+x+y)
    {
        qi que[8];
        bool ans=false;
        memset(maps,0,sizeof(maps));
        memset(wse,0,sizeof(wse));
        for(int i=0;i<n;++i)
        {
            cin>>que[i].ch>>que[i].x>>que[i].y;
            maps[que[i].x][que[i].y]=que[i].ch;
        }
        for(int j=x+1;j<=10;++j)
        {
            if(maps[j][y]!='\0'&&maps[j][y]!='G')break;
            else if(maps[j][y]=='G')
            {
                ans=true;
                break;
            }
        }
        for(int i=0;i<n;++i)
        {
            //print();
            switch(que[i].ch)
            {
                case 'R':
                    for(int j=que[i].y-1;j>=1;j--)
                    {
                        wse[que[i].x][j]=true;
                        if(maps[que[i].x][j]!='\0')break;
                    }
                    for(int j=que[i].y+1;j<=9;j++)
                    {
                        wse[que[i].x][j]=true;
                        if(maps[que[i].x][j]!='\0')break;
                    }
                     for(int j=que[i].x+1;j<=10;j++)
                    {
                        wse[j][que[i].y]=true;
                        if(maps[j][que[i].y]!='\0')break;
                    }
                case 'G':
                    for(int j=que[i].x-1;j>=1;j--)
                    {
                        wse[j][que[i].y]=true;
                        if(maps[j][que[i].y]!='\0')break;
                    }
                    break;
                case 'H':
                    if(que[i].x-1>=1&&maps[que[i].x-1][que[i].y]=='\0')
                    {
                        if(que[i].x-2>=1&&que[i].y-1>=1)
                            wse[que[i].x-2][que[i].y-1]=true;
                        if(que[i].x-2>=1&&que[i].y+1<=9)
                            wse[que[i].x-2][que[i].y+1]=true;
                    }
                    if(que[i].x+1<=10&&maps[que[i].x+1][que[i].y]=='\0')
                    {
                        if(que[i].x+2<=10&&que[i].y-1>=1)
                            wse[que[i].x+2][que[i].y-1]=true;
                        if(que[i].x+2<=10&&que[i].y+1<=9)
                            wse[que[i].x+2][que[i].y+1]=true;
                    }
                    if(que[i].y-1>=1&&maps[que[i].x][que[i].y-1]=='\0')
                    {
                        if(que[i].x-1>=1&&que[i].y-2>=1)
                            wse[que[i].x-1][que[i].y-2]=true;
                        if(que[i].x+1<=10&&que[i].y-2>=1)
                            wse[que[i].x+1][que[i].y-2]=true;
                    }
                    if(que[i].y+1<=9&&maps[que[i].x][que[i].y+1]=='\0')
                    {
                        if(que[i].x-1>=1&&que[i].y+2<=9)
                            wse[que[i].x-1][que[i].y+2]=true;
                        if(que[i].x+1<=10&&que[i].y+2<=9)
                            wse[que[i].x+1][que[i].y+2]=true;
                    }
                    break;
                case 'C':
                    for(int j=que[i].x-1;j>=1;j--)
                        if(maps[j][que[i].y]!='\0')
                            for(j--;j>=1;--j)
                            {
                                wse[j][que[i].y]=true;
                                if(maps[j][que[i].y]!='\0')break;
                            }
                    for(int j=que[i].x+1;j<=10;j++)
                        if(maps[j][que[i].y]!='\0')
                            for(j++;j<=10;++j)
                            {
                                wse[j][que[i].y]=true;
                                if(maps[j][que[i].y]!='\0')break;
                            }
                    for(int j=que[i].y-1;j>=1;j--)
                        if(maps[que[i].x][j]!='\0')
                            for(j--;j>=1;--j)
                            {
                                wse[que[i].x][j]=true;
                                if(maps[que[i].x][j]!='\0')break;
                            }
                    for(int j=que[i].y+1;j<=9;j++)
                        if(maps[que[i].x][j]!='\0')
                            for(j++;j<=9;++j)
                            {
                                wse[que[i].x][j]=true;
                                if(maps[que[i].x][j]!='\0')break;
                            }
                    break;
            }
        }
        //print();
        if(!ans&&x-1>=1&&wse[x-1][y]==false)ans=true;
        if(!ans&&x+1<=3&&wse[x+1][y]==false)ans=true;
        if(!ans&&y-1>=4&&wse[x][y-1]==false)ans=true;
        if(!ans&&y+1<=6&&wse[x][y+1]==false)ans=true;
        if(ans)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}