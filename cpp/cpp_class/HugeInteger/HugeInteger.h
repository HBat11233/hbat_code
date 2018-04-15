/*
 * HugeInteger.h
 *
 *  Created on: 2018年4月10日
 *      Author: hbat
 */

#ifndef HUGEINTEGER_H_
#define HUGEINTEGER_H_

#include <iostream>
#include <vector>
#include <string>

class HugeInteger
{
public:
	HugeInteger();
	HugeInteger(const std::string &);
	HugeInteger(const int &);
	HugeInteger(const long long &);
	size_t input();										//std::cin>>string;
	HugeInteger output();								//输出，正数无符号
	static HugeInteger abs(HugeInteger);				//返回新的非负HugeInteger，
	HugeInteger add(const HugeInteger &);				//加一个数到自己，自己的值改变
	HugeInteger add(const std::string &);
	HugeInteger add(const int &);
	HugeInteger add(const long long &);
	HugeInteger substract(const HugeInteger &);			//减一个数到自己，自己的值改变
	HugeInteger substract(const std::string &);
	HugeInteger substract(const int &);
	HugeInteger substract(const long long &);
	HugeInteger multiply(const HugeInteger &);			//乘一个数到自己，自己的值改变
	HugeInteger multiply(const std::string &);
	HugeInteger multiply(const int &);
	HugeInteger multiply(const long long &);
	HugeInteger divide(const HugeInteger &);            //除一个数到自己，自己的值改变
	HugeInteger divide(const std::string &);
	HugeInteger divide(const int &);
	HugeInteger divide(const long long &);
	HugeInteger modulus(const HugeInteger &);           //取余一个数到自己，自己的值改变
	HugeInteger modulus(const std::string &);
	HugeInteger modulus(const int &);
	HugeInteger modulus(const long long &);
	bool isEqualTo(const HugeInteger &);				//==
	bool isEqualTo(const int &);
	bool isEqualTo(const long long &);
	bool isEqualTo(const std::string &);
	bool isNotEqualTo(const HugeInteger &);				//!=
	bool isNotEqualTo(const int &);
	bool isNotEqualTo(const long long &);
	bool isNotEqualTo(const std::string &);
	bool isGreaterThan(const HugeInteger &);			//>
	bool isGreaterThan(const int &);
	bool isGreaterThan(const long long &);
	bool isGreaterThan(const std::string &);
	bool isLessThan(const HugeInteger &);				//<
	bool isLessThan(const int &);
	bool isLessThan(const long long &);
	bool isLessThan(const std::string &);
	bool isGreaterThanOrEqualTo(const HugeInteger &);   //>=
	bool isGreaterThanOrEqualTo(const int &);
	bool isGreaterThanOrEqualTo(const long long &);
	bool isGreaterThanOrEqualTo(const std::string &);
	bool isLessThanOrEqualTo(const HugeInteger &);		//<=
	bool isLessThanOrEqualTo(const int &);
	bool isLessThanOrEqualTo(const long long &);
	bool isLessThanOrEqualTo(const std::string &);
	bool isZero();										//==0
	int size();											//HugeInteger的位数
	std::string getStrnum();
	std::vector<int> getNumber();
	int getLength();
	char getNumch();
private:
	char numch;											//数的符号+，-
	std::string strnum;									//字符串储存，用于输入输出
	std::vector<int>number;								//用于计算
	int length;											//位数
};




#endif /* HUGEINTEGER_H_ */
