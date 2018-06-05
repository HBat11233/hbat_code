#include <bits/stdc++.h>

using namespace std;

double be1=0,be2=0;																//初始加权，见“动态规划求解.docx”
int maxip=-1;																	//地点最大编号
int waynum=0;																	//边的数量
vector <int> frist(1,-1);
vector <int> nexta(1,-1);
vector <int> xip(1,0);															//单边起点
vector <int> yip(1,0);															//单边终点
vector <double> w(1,0);															//边长
vector <int> way;																//路径

vector <double> SPFA(int a)														//a为起点
{
	queue<double>que;
	vector <double> ans(maxip+1,0x7f);
	map<int,bool>ko;
	way.resize(maxip+1,0);
	ans[a]=0;
	ko[a]=true;
	que.push(a);
	do
	{
		int h=que.front();
		int k = frist[h];
		while(k!=-1)
		{
			if(ans[yip[k]]>ans[xip[k]]+w[k])
			{
				ans[yip[k]]=ans[xip[k]]+w[k];
				way[yip[k]]=xip[k];
				if(!ko.count(yip[k])||ko[yip[k]]==false)
				{
					ko[yip[k]]=true;
					que.push(yip[k]);
				}
			}
			k=nexta[k];
		}
		que.pop();
		ko[h]=false;
	}while(!que.empty());
	return ans;
}

void f_way(int end)																//输出路径
{
	if(!end)return;
	f_way(way[end]);
	cout<<"->"<<end;
	return;
}

int main()
{
	scanf("%lf%lf",&be1,&be2);
	int a,b;
	double c;
	while(~scanf("%d%d%lf",&a,&b,&c))
	{
		waynum++;
		xip.push_back(a);
		yip.push_back(b);
		w.push_back(c);
		maxip=max(maxip,max(a,b));
		if(maxip>=frist.size())
			frist.resize(maxip+1,-1);
		nexta.push_back(frist[xip[waynum]]);
        frist[xip[waynum]]=waynum;
	}
	vector <double> ans;
	ans = SPFA(1);
	cout<<ans[16]<<endl;
	f_way(16);
	return 0;
}
/*
//**该数据只能求A到G的最短路**
0 0 
1 2 5
1 3 3
2 4 1
2 5 3
2 6 6
3 5 8
3 6 7
3 7 6
4 8 6
4 9 8
5 8 3
5 9 5
6 9 3
6 10 3
7 10 8
7 11 4
8 11 2
8 12 2
9 12 1
9 13 2
10 12 3
10 13 3
11 14 3
11 15 5
12 14 5
12 15 2
13 14 6
13 15 6
14 16 4
15 16 3
*/