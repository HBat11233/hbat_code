/*
 * text.cpp
 *
 *  Created on: 2018Äê4ÔÂ2ÈÕ
 *      Author: w1123
 */

#include <iostream>
#include <ctime>

using namespace std;

class times
{
public:
	times(int num=0,int nd=0)
		:num(num),nd(nd)
	{
	}
	int getNum()
	{
		return num;
	}
private:
	int num;
	const int nd;
};

int main()
{
	int num=0;
	int &a(num);
	cout<<a<<' '<<num;
	times d;
	cout<<d.getNum();
	return 0;
}
