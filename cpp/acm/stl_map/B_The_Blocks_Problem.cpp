#include <iostream>
#include <vector> 
#include <string> 

using namespace std;

vector < vector <int> > que;
vector <int> x, y;
int n;
string str1, str2;
int min1, min2;

inline int cls(int min)//清除min之上的队列
{
	for (int i = y[min] + 1; i < que[x[min]].size(); ++i)
	{
		x[que[x[min]][i]] = que[x[min]][i];
		y[que[x[min]][i]] = 0;
		que[x[que[x[min]][i]]].push_back(x[que[x[min]][i]]);
	}
	que[x[min]].erase(que[x[min]].begin() + y[min] + 1, que[x[min]].end());
	return 0;
}

int main()
{
	cin >> n;
	que.resize(n);
	for (int i = 0; i<n; ++i)
	{
		que[i].push_back(i);
		x.push_back(i);
		y.push_back(0);
	}
	for (cin >> str1; str1 != "quit"; cin >> str1)
	{
		cin >> min1 >> str2 >> min2;
		if (x[min1] == x[min2])continue;
		if (str1 == "move")
		{
			cls(min1);//清除min1上的数字
			que[x[min1]].erase(que[x[min1]].begin() + y[min1]);
			if (str2 == "onto")
				cls(min2);//清除min2的数字
			que[x[min2]].push_back(min1);
			x[min1] = x[min2];
			y[min1] = que[x[min2]].size() - 1;

		}
		else
		{
			if (str2 == "onto")
				cls(min2);//清除min2的数字
			que[x[min2]].insert(que[x[min2]].end(), que[x[min1]].begin() + y[min1], que[x[min1]].end());//插入min1列
			que[x[min1]].erase(que[x[min1]].begin() + y[min1], que[x[min1]].end());//清除min1列
			for (int i = y[min2] + 1; i<que[x[min2]].size(); ++i)//格式化min1
			{
				x[que[x[min2]][i]] = x[min2];
				y[que[x[min2]][i]] = i;
			}
		}
	}
	for (int i = 0; i<n; ++i)
	{
		cout << i << ":";
		for (int j = 0; j<que[i].size(); ++j)
			cout << ' ' << que[i][j] ;
		cout << endl;
	}
	return 0;
}
