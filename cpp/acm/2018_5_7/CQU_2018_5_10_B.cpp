#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

const int IEN = 5e6 + 5;

using namespace std;

void nxt(char b[], vector <int> &ne)
{
	int len = strlen(b);
	ne.resize(len+1);
	int p = ne[0] = -1, i = 0;
	while (i < len)
	{
		if (p == -1 || b[i] == b[p])
		{
			ne[++i] = ++p;
		}
		else
		{
			p = ne[p];
		}
	}
}

void kmp(char a[], char b[],char c[])
{
	vector <int>nexts;
	int n = strlen(a);
	int m = strlen(b);
	nxt(b, nexts);
	int p = 0;
	int i = 0;
	while (i < n && p < m)
	{
		if (p == -1 || a[i] == b[p])
		{
			++i;
			++p;
		}
		else
		{
			p = nexts[p];
		}
		if (p == m)
		{
			p = nexts[p];
			a[i - m] = '!';
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == '!')
		{
			printf("%s", c);
			i += m - 1;
		}
		else printf("%c",a[i]);
	}
	printf("\n");
	return;
}

char a[IEN], b[IEN], c[IEN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s%s",a,b,c);
		kmp(a, b, c);
	}
	return 0;
}