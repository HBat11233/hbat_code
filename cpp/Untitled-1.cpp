#include<stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<math.h>
int main()
{
	freopen("bw1.txt","w",stdout);
	int x;
	int pownum[10];
	scanf("%d", &x);
	int a1=clock();
	int l=pow(10,x-1),r=pow(10,x),i,i0,j,t,a;
	for(int i=0;i<10;++i)
	{
			pownum[i]=pow(i,x);
	}
	    for(i=l; i<r; i++)
	    {
			i0 = i;
			t=i0;//这里
	        for(j=0;j<x;j++)
	        {
	            a = i0%10;
				t -=pownum[a];//这里
				//if(t<0)break;//剪枝，实验了一下感觉没事用
	            i0 /= 10;
	        }
        if(t==0) printf("%lld\n",i);
		}
	std::cout<<clock()-a1;
	fclose(stdout);
	return 0;
}