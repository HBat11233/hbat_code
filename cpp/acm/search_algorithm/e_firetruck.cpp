#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

vector < vector <int> > ans;
vector <int> temp;
vector <int> map[22];
int ko[22];
int k=0;

int dfs(int n,int &e)
{
    if(n==e)
    {
        ans.push_back(temp);
        ans[ans.size()-1].push_back(n);
        return 0;
    }
    else
    {
        if(map[n].size()==0)
        {
            ko[n]++;
            return 1;
        }
        for(int i=0;i<map[n].size();++i)
        {
            if(!ko[map[n][i]])
            {
                ko[map[n][i]]++;
                temp.push_back(n);
                if(dfs(map[n][i],e)==1)
                {
                    ko[map[n][i]]--;
                    map[n].erase(map[n].begin()+i);
                    i--;
                }
                else ko[map[n][i]]--;
                temp.pop_back();
            }
        }
    }
    return 0;
}

inline int func(int &n)
{

    k++;
    int i=22,j;
    ans.clear();
    memset(ko,0,sizeof(ko));
    while(i--)map[i].clear();
    temp.clear();
    while(scanf("%d%d",&i,&j),i)
    {
        map[i].push_back(j);
        map[j].push_back(i);
    }
    ko[1]++;
    dfs(1,n);
    sort(ans.begin(),ans.end());
    cout<<"CASE "<<k<<":\n";
    for(i=0;i<ans.size();++i)
    {
        for(j=0;j<ans[i].size();++j)
            cout<<' '<<ans[i][j];
        cout<<endl;
    }
    printf("There are %d routes from the firestation to streetcorner %d.",ans.size(),n);
    
    return 0;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
        func(n);
    return 0;
}