#include <iostream> 

using namespace std;

typedef long long int LONG;

bool sushu(LONG num)//判断是不是素数 
{
    LONG i;
    for(i=2;i*i<num;++i)
        if(num%i==0)break;
    if((i*i)>num)return true;
    else return false;
}

int main()
{
    LONG num;
    LONG temp=0;
    LONG fznum=0;
    LONG sum=0;//计算位数和
    int length=0;//num长度 
    cout<<"请输入数字：";
    cin>>num;
    cout<<"数字位数：";
    temp=num;//暂时存一下 
    while(temp>0)
    {
    	length++; 
    	fznum*=10;
    	fznum+=temp%10;//反序数 
    	sum+=temp%10;//位数求和 
    	temp/=10;
	}
	cout<<length<<endl;
    cout<<"各个位数之和："<<sum<<endl<<"分割数字：";
    while(fznum>0)
    {
    	cout<<fznum%10<<' ';
    	fznum/=10;
	}
    cout<<endl;
    if(sushu(num))cout<<num<<"是素数！"<<endl;//判断是不是素数 
    else cout<<num<<"不是素数！"<<endl;
    system("pause");
    return 0;
}
