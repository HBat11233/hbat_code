#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run(int n)
{
	int i;
	int temps = 0;
	vector <vector <int>> ip;
	vector <int> dns(4, 0), minip(4, 0);
	ip.resize(4);
	ip[0].resize(n);
	ip[1].resize(n);
	ip[2].resize(n);
	ip[3].resize(n);
	for (i = 0; i < n; ++i)
		scanf("%d.%d.%d.%d", &ip[0][i], &ip[1][i], &ip[2][i], &ip[3][i]);
	if (n == 1)
	{
		printf("%d.%d.%d.%d\n255.255.255.255\n", ip[0][0], ip[1][0], ip[2][0], ip[3][0]);
		return;
	}
	else if (n == 0)
	{
		printf("0.0.0.0\n255.255.255.255\n");
		return;
	}
	sort(ip[0].begin(), ip[0].end());
	sort(ip[1].begin(), ip[1].end());
	sort(ip[2].begin(), ip[2].end());
	sort(ip[3].begin(), ip[3].end());
	for (i = 0;i < 4; ++i)
	{
		if (*ip[i].begin() != *ip[i].rbegin())break;
	}
	if(i<4)
		temps = *ip[i].rbegin() ^ *ip[i].begin();
	int k = 0;
	while (temps != 0)
	{
		++k;
		temps = temps >> 1;
	}
	if(k==0)
	{
		printf("%d.%d.%d.%d\n255.255.255.255\n", ip[0][0], ip[1][0], ip[2][0], ip[3][0]);
		return;
	}
	for (int j = 0; j < i; ++j)
		dns[j] = 255;
	dns[i] = 255;
	dns[i] = dns[i] << k;
	if (dns[i] < 0)dns[i] = 0;
	else dns[i] %= 256;
	for (int i = 0; i < 4; ++i)
	{
		cout << (dns[i] & *ip[i].begin());
		if (i != 3)cout << '.';
		else cout << endl;
	}
	for (int i = 0; i < 4; ++i)
	{
		cout << dns[i];
		if (i != 3)cout << '.';
		else cout << endl;
	}
	ip.clear();
	dns.clear();
	minip.clear();
	return;
}

int main()
{
	int n;
	while (cin >> n)
	{
		run(n);
	}
	return 0;
}