#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=10;
vector<int>G[MAXN];
int map[10][10];
int a[5][5];
int indegree[10];
int loca[4][4]={
{0,0,0,0,},
{0,1,2,3,},
{0,4,5,6,},
{0,7,8,9,},
};
void build(){
    for(int i=1;i<=4;++i)
    for(int j=1;j<=4;++j)
        scanf("%d",&a[i][j]);
/*看图说话系列，就是一个模拟*/
    for(int row=1;row<=3;++row)
        for(int col=1;col<=3;++col){
            int temp=loca[row][col];
//            printf("row=%d,col=%d,temp=%d\n",row,col,temp);
            for(int i=col;i<=col+1;++i)
            for(int j=row;j<=row+1;++j){
                int num=a[j][i];
            if(num!=temp&&!map[temp][num]){
                map[temp][num]=1;
                G[temp].push_back(num);
                indegree[num]++;
            }
        }
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        for(int i=1;i<=9;++i)G[i].clear();
        queue<int>q;while(!q.empty())q.pop();
        build();


        for(int i=1;i<=9;++i)
            if(indegree[i]==0)q.push(i);
        while(!q.empty())
        {
            int no=q.front();q.pop();
            for(int i=0;i<G[no].size();++i)
            {
                int v=G[no][i];
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
            G[no].clear();
        }
        bool noAns=false;
        for(int i=1;i<=9;++i)
            if(G[i].size()!=0)noAns=true;
        printf(noAns?"BOOM!":"Lucky dog!");
        printf("\n");
    }
    return 0;
}