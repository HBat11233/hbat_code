#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define LENG 50

using namespace std;

int funarraymin(int a[],int begin,int length)//��Сֵ,a[]Ϊ�������飬lengthΪ���ҵĳ��ȣ�begin������㣬 
{
	if(length==1)return a[begin];
	else return min(funarraymin(a,begin,length/2),funarraymin(a,begin+length/2,length-length/2));//���� 
}

void qsort(int b,int e,int length,int a[])//a[]����,i=range(b,e,length),a[i]���� 
{
	int bt=a[b];
	int i=b,j=i;
	while(j<e)j+=length;//�Ż�����������ʱ��֤(e-b)%length==0�������ɾ���˴� 
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

void print(int a[],int begin,int length,int endll)//������� ,beginΪ��㣬��length,ÿ���endll�������� 
{
	for(int i=begin;i<length;i++)
	{
		printf("%3d ",a[i]);
		if((i+1)%endll==0)cout<<endl;
	}
	return;
}

bool sushu(int n)//�ж�n�ǲ������� 
{
	if(n==2)return true;
	for(int i=2;i<sqrt(n);++i)
		if(n%i==0)return false;
	return true;
}

int sumsushu(int a[],int begin,int end)//�������� 
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
	system("color F0");//�׵׺��� 
	int num[LENG];
	srand(time(NULL));
	for(int i=0;i<LENG;++i)
		num[i]=rand()%501;
	cout<<"������飺\n";
	print(num,0,LENG,10);
	int minnum=funarraymin(num,0,LENG);
	cout<<"��С����"<<minnum<<endl;
	qsort(0,LENG-1,2,num);
	cout<<"�±�Ϊ0,2,4...���������\n"; 
	print(num,0,LENG,10);
	cout<<"�����ͣ�\n";
	int sumnum=sumsushu(num,0,LENG);
	cout<<"�����ͣ�"<<sumnum<<endl;
	system("pause");//��ͣ 
	return 0;
} 
