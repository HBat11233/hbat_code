#include <iostream> 

using namespace std;

typedef long long int LONG;

bool sushu(LONG num)//�ж��ǲ������� 
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
    LONG sum=0;//����λ����
    int length=0;//num���� 
    cout<<"���������֣�";
    cin>>num;
    cout<<"����λ����";
    temp=num;//��ʱ��һ�� 
    while(temp>0)
    {
    	length++; 
    	fznum*=10;
    	fznum+=temp%10;//������ 
    	sum+=temp%10;//λ����� 
    	temp/=10;
	}
	cout<<length<<endl;
    cout<<"����λ��֮�ͣ�"<<sum<<endl<<"�ָ����֣�";
    while(fznum>0)
    {
    	cout<<fznum%10<<' ';
    	fznum/=10;
	}
    cout<<endl;
    if(sushu(num))cout<<num<<"��������"<<endl;//�ж��ǲ������� 
    else cout<<num<<"����������"<<endl;
    system("pause");
    return 0;
}
