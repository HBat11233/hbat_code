#include <iostream>
#include <map> 
#include <vector>
#include <string>

using namespace std;

map <int, int> teamque;//×éÃû
vector <int> guard;//
vector <int> que;
int n;
string str;
int num;

int main()
{
	int tip = 0;
	while (cin >> n && n != 0)
	{
		tip++;
		cout << "Scenario #" << tip << endl;
		teamque.clear();
		que.clear();
		guard.clear();
		for (int i = 0; i < n; ++i)
			guard.push_back(-1);
		for (int i = 0, j; i < n; ++i)
		{
			cin >> j;
			for (int k; j > 0; --j)
			{
				cin >> k;
				teamque[k] = i;
			}
		}
		while (cin >> str)
		{
			switch (str[0])
			{
			case 'E':
				cin >> num;
				if (guard[teamque[num]] < 0 )
				{
					que.push_back(num);
					guard[teamque[num]] = que.size() - 1;
				}
				else
				{
					que.insert(que.begin() + guard[teamque[num]] + 1, num);
					int temp = guard[teamque[num]];
					for (int i = 0; i < n; ++i)
						if (guard[i] >= temp)guard[i]++;
				}
				break;
			case 'D':
				cout << que[0] << endl;
				for(int i=0;i<n;++i)guard[i]--;
				que.erase(que.begin());
				break;
			default:
				cout << endl;
				goto A1;
			}
		}
	A1:;
	}
	return 0;
}
