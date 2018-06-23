#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT
{
	static const int N = 1e5 + 5;
	int a[N];
	int n;
	void init(int _n)
	{
		n = _n;
		memset(a, 0, sizeof a);
	}
	void add(int i, int x)
	{
		for (; i <= n; i += i & -i) a[i] += x;
	}
	int getSum(int i)
	{
		int ret = 0;
		for (; i > 0; i -= i & -i) 
            ret += a[i];
		return ret;
	}
}bit;

int main()
{
	int T; 
    scanf("%d", &T);
	while (T--)
	{
		int n; 
        scanf("%d", &n);
		char s[10];
		int q;
		scanf("%s%s%d", s, s, &q);
		bit.init(n);
		while (q--)
		{
			int op, a, b;
			scanf("%d%d%d", &op, &a, &b);
			if (op == 0) bit.add(a, b);
			else printf("%d\n", bit.getSum(b) - bit.getSum(a - 1));
		}
		scanf("%s%s%d", s, s, &q);
		bit.init(n);
		while (q--)
		{
			int op; scanf("%d", &op);
			if (op == 0)
			{
				int a, b, c;
				scanf("%d%d%d", &a, &b, &c);
				bit.add(a, c);
				bit.add(b + 1, -c);
			}
			else
			{
				int a; scanf("%d", &a);
				printf("%d\n", bit.getSum(a));
			}
		}
	}
	return 0;
}
