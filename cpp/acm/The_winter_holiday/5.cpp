//aoj0121
#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

string str="99999999";
map<string,int>dp;

int d[4]={-1,1,-4,4};

inline void bfs()
{
    queue<string>que;
    que.push("01234567");
    map<string,bool>ps;
    ps["01234567"]=true;
    while(!que.empty())
    {
        string h=que.front();
        que.pop();
        int pos;
        for(int i=0;i<8;++i)
            if(h[i]=='0'){pos=i;break;}
        for(int i=0;i<4;++i)
        {
            string temp=h;
            int k=pos+d[i];
            if(k<0||k>7||(pos==4&&k==3)||(pos==3&&k==4))continue;
            swap(temp[pos],temp[k]);
            if(!dp.count(temp))
            {
                dp[temp]=dp[h]+1;
                que.push(temp);
            }
        }
    }
    return;
}


int main()
{
    
    int num[8];
    dp["01234567"]=0;
    bfs();
    while(~scanf("%d",num))
    {
        for(int i=1;i<8;++i)
            scanf("%d",num+i);
        for(int i=0;i<8;++i)
            str[i]=(char)(num[i]+'0');
        cout<<dp[str]<<endl;
    }
    return 0;
}