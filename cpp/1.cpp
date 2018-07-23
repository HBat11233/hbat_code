#include <bits/stdc++.h>

using namespace std;

int main()
{
	srand(time(NULL));
	freopen("1.txt","w",stdout);
	cout<<1000<<endl;
	for(int i=0;i<100;++i)
	{
		int n=rand()%10000;
		cout<<n<<endl;
		for(int j=0;j<n;j++)
			cout<<rand()%(n+10)<<" ";
		cout<<endl;
	}
	return 0;
}