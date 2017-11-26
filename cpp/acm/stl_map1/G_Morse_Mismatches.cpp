#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool _temp(const string a, const string b)
{
	return a.size() < b.size();
}

int main()
{
	map <char, string> wordbook;
	map <string, vector <string>>mybook;
	vector <string> word;
	char ch;
	string str1, str2;
	string min;
	for (cin >> ch; ch != '*'; cin >> ch)//输入密码
	{
		cin >> str2;
		wordbook[ch] = str2;
	}
	for (cin >> str1,min=str1; str1 != "*"; cin >> str1)//输入字典
	{
		min = min < str1 ? min : str1;
		str2.clear();
		for (int i = 0; i < str1.size(); ++i)
			str2 += wordbook[str1[i]];
		word.push_back(str2);
		int i;
		for (i = 0; i<mybook[str2].size(); ++i)
			if (mybook[str2][i] > str1)break;
		mybook[str2].insert(mybook[str2].begin() + i, str1);
	}
	sort(word.begin(), word.end(),_temp);//现有字典码排序
	for (cin >> str1; str1 != "*"; cin >> str1)//翻译
	{
		if (mybook.count(str1))//如果在字典中
		{
			if (mybook[str1].size() > 1)cout << mybook[str1][0] << '!' << endl;//如果多个
			else cout << mybook[str1][0] << endl;
		}
		else//如果没有
		{
			int i,j;//和str1一样长的是不需要的，因为上面if就检查过了
			for (i = 0; i < word.size(); ++i)//找到第一个比str1长的
				if (word[i].size() > str1.size())break;
			for (j = i<word.size()? i:word.size()-1; j >= 0; j--)//找到倒数第一个比str1短的
				if (word[j].size() < str1.size())break;
			while (i<word.size()&&j>=0)//限定在字典内
			{
				if ((word[i].size() - str1.size()) == (str1.size() - word[j].size()))//增减程度一样
				{
					int k,m;
					for (k = 0; k < str1.size(); ++k)//检查是否模糊
						if (word[i][k] != str1[k])break;
					for (m = 0; m < word[j].size(); ++m)//检查是否模糊
						if (word[j][m] != str1[m])break;
					if (k >= str1.size() && m >= word[j].size())//是否输出
					{
						if (mybook[word[i]][0] < mybook[word[j]][0])//输出字典序小
							cout << mybook[word[i]][0];
						else
							cout << mybook[word[j]][0];
						cout << '?' << endl;
						goto A1;
					}
					else if (k >= str1.size())//只有一个模糊
					{
						cout << mybook[word[i]][0] << '?' << endl;
						goto A1;
					}
					else if (m >= word[j].size())//只有一个模糊
					{
						cout << mybook[word[j]][0] << '?' << endl;
						goto A1;
					}
					i++;
					--j;
					continue;//没有找到，结束本次循环

				}
				if ((word[i].size() - str1.size()) < (str1.size() - word[j].size()))//增小于减
				{
					int k;
					for (k = 0; k < str1.size(); ++k)//检查是否模糊
						if (word[i][k] != str1[k])break;
					if (k >= str1.size())
					{
						cout << mybook[word[i]][0] << '?' << endl;
						goto A1;
					}
					++i;
					continue;//没有找到，结束本次循环
				}
				if ((word[i].size() - str1.size()) > (str1.size() - word[j].size()))//增大于减
				{
					int k;
					for (k = 0; k < word[j].size(); ++k)//检查是否模糊
						if (word[j][k] != str1[k])break;
					if (k >= word[j].size())
					{
						cout << mybook[word[j]][0] << '?' << endl;
						goto A1;
					}
					--j;
					continue;//没有找到，结束本次循环
				}
			}
			while (i<word.size())//没有减
			{
				int k;
				for (k = 0; k < str1.size(); ++k)//检查是否模糊
					if (word[i][k] != str1[k])break;
				if (k >= str1.size())
				{
					cout << mybook[word[i]][0] << '?' << endl;
					goto A1;
				}
				++i;
			}
			while (j >= 0)//没有增
			{
				int k;
				for (k = 0; k < word[j].size(); ++k)//检查是否模糊
					if (word[j][k] != str1[k])break;
				if (k >= word[j].size())
				{
					cout << mybook[word[j]][0] << '?' << endl;
					goto A1;
				}
				--j;
			}
			cout << min << '?' << endl;
			A1:;
		}
	}
	return 0;
}
