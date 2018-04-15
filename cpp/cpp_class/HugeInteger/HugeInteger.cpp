/*
 * HugeInteger.cpp
 *
 *  Created on: 2018年4月10日
 *      Author: hbat
 */

#include "HugeInteger.h"
#include <algorithm>
#include <cmath>
//构造函数
HugeInteger::HugeInteger()
:strnum(""),number(NULL),length(0),numch('+'){}
HugeInteger::HugeInteger(const int &num)
:strnum(""),number(NULL),length(0)
{
	int temp=std::abs(num);
	numch = num>=0? '+':'-';
	while(temp)
	{
		number.push_back(temp%10);
		length++;
		temp/=10;
	}
	strnum.resize(length);
	for(int i=0;i<length;++i)
		strnum[i]=number[i]+'0';
}
HugeInteger::HugeInteger(const long long &num)
:strnum(""),number(NULL),length(0)
{
	long long temp=std::abs(num);
		numch = num>=0? '+':'-';
	while(temp)
	{
		number.push_back(temp%10);
		length++;
		temp/=10;
	}
	strnum.resize(length);
	for(int i=0;i<length;++i)
		strnum[i]=number[i]+'0';
}
HugeInteger::HugeInteger(const std::string &num)
:number(NULL),length(0)
{
	if((num[0]<48||num[0]>57)&&(num[0]!='+'&&num[0]!='-'))
	{
		std::cerr<<"\n***Contains non-numeric characters.***\n";
		return;
	}
	for(char ch:num.substr(1,num.size()-1))
		if(ch<48||ch>57)
		{
			std::cerr<<"\n***Contains non-numeric characters.***\n";
			return;
		}
	strnum=num;
	int len=strnum.size()/2;
	for(int i = 0;i<len;++i)
		std::swap(strnum[i],strnum[strnum.size()-i-1]);
	if(*strnum.rbegin()=='+')numch='+',strnum.pop_back();
	else if(*strnum.rbegin()=='-')numch='-',strnum.pop_back();
	else numch='+';
	for(int i=0;i<num.size();++i)
		if(num[i]!='0')break;
		else strnum.pop_back();
	number.resize(strnum.size());
	for(int i=0;i<number.size();++i)
		number[i]=strnum[i]-'0';
	length=strnum.size();
	numch=length? numch:'+';
}

HugeInteger HugeInteger::abs(HugeInteger b)//number is new HugeInteger
{
	b.numch='+';
	return b;
}
//查看成员变量
int HugeInteger::size(){return length;}
std::string HugeInteger::getStrnum(){return strnum;}
std::vector<int> HugeInteger::getNumber(){return number;}
int HugeInteger::getLength(){return length;}
//io
size_t HugeInteger::input()
{
	std::cin>>strnum;
	if((strnum[0]<48||strnum[0]>57)&&(strnum[0]!='+'&&strnum[0]!='-'))
		{
			std::cerr<<"\n***Contains non-numeric characters.***\n";
			strnum.clear();
			return length;
		}
	for(char ch:strnum.substr(1,strnum.size()-1))
		if(ch<48||ch>57)
		{
			std::cerr<<"\n***Contains non-numeric characters.***\n";
			strnum.clear();
			return length;
		}
	int len=strnum.size()/2;
	for(int i=0;i<len;++i)
		std::swap(strnum[i],strnum[strnum.size()-i-1]);
	if(*strnum.rbegin()=='+')numch='+',strnum.pop_back();
	else if(*strnum.rbegin()=='-')numch='-',strnum.pop_back();
	else numch='+';
	for(int i=strnum.size()-1;i>=0;--i)
		if(strnum[i]=='0')strnum.pop_back();
		else break;
	length=strnum.size();
	numch=length? numch:'+';
	number.resize(length);
	for(int i=0;i<length;++i)
		number[i]=strnum[i]-'0';
	return length;
}
HugeInteger HugeInteger::output()
{
	if(length==0)std::cout<<0;
	if(numch=='-')std::cout<<numch;
	for(int i=strnum.size()-1;i>=0;--i)
		std::cout<<strnum[i];
	return *this;
}
//add(self will change)
HugeInteger HugeInteger::add(const HugeInteger & b)
{
	if(numch=='+'&&b.numch=='-')return this->substract(HugeInteger::abs(b));
	else if(numch=='-'&&b.numch=='+')
	{
		numch='+';
		this->substract(b);
		numch=numch=='+'? '-':'+';
		return *this;
	}else
	{
//一下代码针对符号相同
		std::vector<int>ans;
		int lengmax=std::max(this->number.size(),b.number.size());
		ans.resize(lengmax,0);
		for(int i = 0;i<lengmax;++i)
		{
			int temp=(i<this->number.size()? this->number[i]:0)+(i<b.number.size()? b.number[i]:0);
			ans[i]+=temp%10;
			if(temp/10>0)
			{
				if(i==lengmax-1)
					ans.push_back(0);
				ans[i+1]+=temp/10;
			}
			if(ans[i]/10>0)
			{
				if(i==lengmax-1)
					ans.push_back(0);
				ans[i+1]+=ans[i]/10;
				ans[i]%=10;
			}
		}
		for(int i=ans.size()-1;i>=0;--i)
			if(ans[i]==0)ans.pop_back();
			else break;
		length=ans.size();
		numch=length? numch:'+';
		strnum.resize(length);
		number.resize(length);
		for(int i=0;i<length;++i)
		{
			strnum[i]=ans[i]+'0';
			number[i]=ans[i];
		}
		return *this;
	}
}
HugeInteger HugeInteger::add(const std::string & b){return add(HugeInteger(b));}
HugeInteger HugeInteger::add(const int &b){return add(HugeInteger(b));}
HugeInteger HugeInteger::add(const long long &b){return add(HugeInteger(b));}
//substract(self will change)
HugeInteger HugeInteger::substract(const HugeInteger & b)
{
	if(numch=='+'&&b.numch=='-')return this->add(HugeInteger::abs(b));
	else if(numch=='-'&&b.numch=='+')
	{
		numch='+';
		this->add(b);
		numch='-';
		return *this;
	}else
	{
	//一下代码针对符号相同
		std::vector<int>ans;
		bool thisGb=isGreaterThanOrEqualTo(b);
		if(thisGb)ans=b.number;
		else
		{
			ans=number;
			number=b.number;
			numch=numch=='+'?'-':'+';
		}
		for(int i=0;i<ans.size();++i)
		{
			number[i]-=ans[i];
			for(int j=1;number[i+j-1]<0;++j)
			{
				number[i+j-1]+=10;
				number[i+j]--;
			}
		}
		for(int i=number.size()-1;i>=0;--i)
			if(number[i]==0)number.pop_back();
			else break;
		length=number.size();
		numch=length? numch:'+';
		strnum.resize(length);
		for(int i=0;i<length;++i)
			strnum[i]=number[i]+'0';
		return *this;
	}
}
HugeInteger HugeInteger::substract(const std::string & b){return substract(HugeInteger(b));}
HugeInteger HugeInteger::substract(const int &b){return substract(HugeInteger(b));}
HugeInteger HugeInteger::substract(const long long &b){return substract(HugeInteger(b));}

HugeInteger HugeInteger::multiply(const HugeInteger & b)
{
	numch = numch==b.numch? '+':'-';
	std::vector<int>ans;
	ans.resize(length+b.length,0);
	for(int i=0;i<length;++i)
	{
		for(int j=0;j<b.length;++j)
			ans[j+i]+=number[i]*b.number[j];
		for(int j=0;j<i+b.length;++j)
		{
			ans[j+1]+=ans[j]/10;
			ans[j]%=10;
		}
	}
	for(int i=ans.size()-1;i>=0;--i)
		if(ans[i]==0)ans.pop_back();
		else break;
	length=ans.size();
	number=ans;
	numch=length? numch:'+';
	strnum.resize(length);
	for(int i=0;i<length;++i)
		strnum[i]=number[i]+'0';
	return *this;
}
HugeInteger HugeInteger::multiply(const std::string & b){return multiply(HugeInteger(b));}
HugeInteger HugeInteger::multiply(const int &b){return multiply(HugeInteger(b));}
HugeInteger HugeInteger::multiply(const long long &b){return multiply(HugeInteger(b));}

HugeInteger HugeInteger::divide(const HugeInteger & b)
{
	HugeInteger temp(b);
	if(temp.isZero())
	{
		std::cerr<<"\n***The divisor cannot be zero.***\n";
		return *this;
	}
	HugeInteger Icon(0);
	char endch = numch==b.numch? '+':'-';
	temp.numch='+';
	numch='+';
	if(isEqualTo(temp))Icon=1;
	else if(isGreaterThan(temp))
	{
		int len=length-temp.length+1;
		HugeInteger ans=1;
		while(ans.size()!=len)ans.multiply(10);
		ans.number[ans.length-1]--;
		ans.strnum[ans.length-1]--;
		for(int i=0;i<ans.size();++i)
		{
			do
			{
				temp=abs(b);
				if(isEqualTo(temp.multiply(ans)))break;
				temp=abs(b);
				ans.number[ans.length-1-i]++;
				ans.strnum[ans.length-1-i]++;
				if(isLessThan(temp.multiply(ans)))
				{
					ans.number[ans.length-1-i]--;
					ans.strnum[ans.length-1-i]--;
					break;
				}
			}while(ans.number[ans.length-1-i]<10);
		}
		if(ans.number[ans.length-1]==0)
		{
			ans.number.pop_back();
			ans.strnum.pop_back();
			ans.length--;
		}
		Icon=ans;
	}
	*this=Icon;
	numch=endch;
	return *this;
}
HugeInteger HugeInteger::divide(const std::string & b){return divide(HugeInteger(b));}
HugeInteger HugeInteger::divide(const int &b){return divide(HugeInteger(b));}
HugeInteger HugeInteger::divide(const long long &b){return divide(HugeInteger(b));}

HugeInteger HugeInteger::modulus(const HugeInteger & b)
{
	HugeInteger H=*this;
	HugeInteger D=b;
	if(D.isZero())
	{
		std::cerr<<"\n***The divisor cannot be zero.***\n";
		return *this;
	}
	H.numch='+';
	D.numch='+';
	HugeInteger p=H;
	p.divide(D);
	p.multiply(D);
	H.substract(p);
	if(numch==b.numch)
		*this=H,numch=b.numch;
	else if(numch=='-'&&b.numch=='+')
		*this=D.substract(H);
	else if(numch=='+'&&b.numch=='-')
		*this=H.add(b);
	return *this;
}
HugeInteger HugeInteger::modulus(const std::string & b){return modulus(HugeInteger(b));}
HugeInteger HugeInteger::modulus(const int &b){return modulus(HugeInteger(b));}
HugeInteger HugeInteger::modulus(const long long &b){return modulus(HugeInteger(b));}

bool HugeInteger::isEqualTo(const HugeInteger & b)
{
	if(length!=b.length)return false;
	else
	{
		for(int i=0;i<length;++i)
			if(strnum[i]!=b.strnum[i])return false;
		return true;
	}
}
bool HugeInteger::isEqualTo(const int & b){return isEqualTo(HugeInteger(b));}
bool HugeInteger::isEqualTo(const long long & b){return isEqualTo(HugeInteger(b));}
bool HugeInteger::isEqualTo(const std::string & b){return isEqualTo(HugeInteger(b));}
bool HugeInteger::isNotEqualTo(const HugeInteger & b){return !isEqualTo(b);}
bool HugeInteger::isNotEqualTo(const int & b){return !isEqualTo(b);}
bool HugeInteger::isNotEqualTo(const long long & b){return !isEqualTo(b);}
bool HugeInteger::isNotEqualTo(const std::string & b){return !isEqualTo(b);}
bool HugeInteger::isGreaterThan(const HugeInteger & b)
{
	if(length>b.length)return true;
	else if(length<b.length)return false;
	else
		for(int i=length-1;i>=0;--i)
			if(number[i]>b.number[i])
			{
				return true;
				break;
			}else if(number[i]<b.number[i])
			{
				return false;
				break;
			}
	return false;
}
bool HugeInteger::isGreaterThan(const int & b){return isGreaterThan(HugeInteger(b));}
bool HugeInteger::isGreaterThan(const long long & b){return isGreaterThan(HugeInteger(b));}
bool HugeInteger::isGreaterThan(const std::string & b){return isGreaterThan(HugeInteger(b));}
bool HugeInteger::isLessThan(const HugeInteger & b){return !isGreaterThanOrEqualTo(b);}
bool HugeInteger::isLessThan(const int & b){return !isGreaterThanOrEqualTo(b);}
bool HugeInteger::isLessThan(const long long & b){return !isGreaterThanOrEqualTo(b);}
bool HugeInteger::isLessThan(const std::string & b){return !isGreaterThanOrEqualTo(b);}
bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger & b){return isEqualTo(b)||isGreaterThan(b);}
bool HugeInteger::isGreaterThanOrEqualTo(const int & b){return isEqualTo(b)||isGreaterThan(b);}
bool HugeInteger::isGreaterThanOrEqualTo(const long long & b){return isEqualTo(b)||isGreaterThan(b);}
bool HugeInteger::isGreaterThanOrEqualTo(const std::string & b){return isEqualTo(b)||isGreaterThan(b);}
bool HugeInteger::isLessThanOrEqualTo(const HugeInteger & b){return isEqualTo(b)||isLessThan(b);}
bool HugeInteger::isLessThanOrEqualTo(const int &b){return isEqualTo(b)||isLessThan(b);}
bool HugeInteger::isLessThanOrEqualTo(const long long &b){return isEqualTo(b)||isLessThan(b);}
bool HugeInteger::isLessThanOrEqualTo(const std::string &b){return isEqualTo(b)||isLessThan(b);}
bool HugeInteger::isZero(){return length==0;}
