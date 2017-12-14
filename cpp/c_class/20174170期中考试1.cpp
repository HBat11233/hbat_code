#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define LENG 50

using namespace std;

int funarraymin(int a[],int begin,int length)//最小值,a[]为操作数组，length为查找的长度，begin操作起点， 
{
	if(length==1)return a[begin];
	else return min(funarraymin(a,begin,length/2),funarraymin(a,begin+length/2,length-length/2));//二分 
}

void qsort(int b,int e,int length,int a[])//a[]数组,i=range(b,e,length),a[i]快排 
{
	int bt=a[b];
	int i=b,j=i;
	while(j<e)j+=length;//优化方法：传递时保证(e-b)%length==0，则可以删除此处 
	while(i<=j)
	{
		while(a[i]<bt)i+=length;
		while(bt<a[j])j-=length;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i+=length;
			j-=length;
		}
	}
	if(b<j)qsort(b,j,length,a);
	if(i<e)qsort(i,e,length,a);
	return;
}

void print(int a[],int begin,int length,int endll)//输出数组 ,begin为起点，长length,每输出endll个数换行 
{
	for(int i=begin;i<length;i++)
	{
		printf("%3d ",a[i]);
		if((i+1)%endll==0)cout<<endl;
	}
	return;
}

bool sushu(int n)//判断n是不是素数 
{
	if(n==2)return true;
	for(int i=2;i<sqrt(n);++i)
		if(n%i==0)return false;
	return true;
}

int sumsushu(int a[],int begin,int end)//求素数和 
{
	int ans=0;
	vector <int> list;
	for(int i=begin;i<end;++i)
		if(sushu(a[i])) 
		{
			list.push_back(a[i]);
			ans+=a[i];
		}
	printf("%d =",ans);
	int endnum=*list.rbegin();
	list.pop_back();
	for(int i=0;i<list.size();++i)
		printf(" %d +",list[i]);
	printf(" %d\n",endnum);
	return ans;
}

int main()
{
	system("color F0");//白底黑字 
	int num[LENG];
	srand(time(NULL));
	for(int i=0;i<LENG;++i)
		num[i]=rand()%501;
	cout<<"随机数组：\n";
	print(num,0,LENG,10);
	int minnum=funarraymin(num,0,LENG);
	cout<<"最小数："<<minnum<<endl;
	qsort(0,LENG-1,2,num);
	cout<<"下标为0,2,4...数组的排序\n"; 
	print(num,0,LENG,10);
	cout<<"素数和：\n";
	int sumnum=sumsushu(num,0,LENG);
	cout<<"素数和："<<sumnum<<endl;
	system("pause");//暂停 
	return 0;
} 
