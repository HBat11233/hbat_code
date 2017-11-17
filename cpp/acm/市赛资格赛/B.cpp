#include <iostream>

using namespace std;

int main()
{
	int w[4];
	int num;
	cin>>w[0]>>w[1]>>w[2]>>w[3]>>num;
	int ans=0;
	for(int i=1;i<=num;++i)
	{
		for(int j=0;j<4;++j)
			if(i%w[j]==0)
			{
				ans++;
				break;
			}
	}
	cout<<ans; 
	return 0;
}
