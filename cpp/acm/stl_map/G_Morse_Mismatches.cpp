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
	for (cin >> ch; ch != '*'; cin >> ch)//��������
	{
		cin >> str2;
		wordbook[ch] = str2;
	}
	for (cin >> str1,min=str1; str1 != "*"; cin >> str1)//�����ֵ�
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
	sort(word.begin(), word.end(),_temp);//�����ֵ�������
	for (cin >> str1; str1 != "*"; cin >> str1)//����
	{
		if (mybook.count(str1))//������ֵ���
		{
			if (mybook[str1].size() > 1)cout << mybook[str1][0] << '!' << endl;//������
			else cout << mybook[str1][0] << endl;
		}
		else//���û��
		{
			int i,j;//��str1һ�������ǲ���Ҫ�ģ���Ϊ����if�ͼ�����
			for (i = 0; i < word.size(); ++i)//�ҵ���һ����str1����
				if (word[i].size() > str1.size())break;
			for (j = i<word.size()? i:word.size()-1; j >= 0; j--)//�ҵ�������һ����str1�̵�
				if (word[j].size() < str1.size())break;
			while (i<word.size()&&j>=0)//�޶����ֵ���
			{
				if ((word[i].size() - str1.size()) == (str1.size() - word[j].size()))//�����̶�һ��
				{
					int k,m;
					for (k = 0; k < str1.size(); ++k)//����Ƿ�ģ��
						if (word[i][k] != str1[k])break;
					for (m = 0; m < word[j].size(); ++m)//����Ƿ�ģ��
						if (word[j][m] != str1[m])break;
					if (k >= str1.size() && m >= word[j].size())//�Ƿ����
					{
						if (mybook[word[i]][0] < mybook[word[j]][0])//����ֵ���С
							cout << mybook[word[i]][0];
						else
							cout << mybook[word[j]][0];
						cout << '?' << endl;
						goto A1;
					}
					else if (k >= str1.size())//ֻ��һ��ģ��
					{
						cout << mybook[word[i]][0] << '?' << endl;
						goto A1;
					}
					else if (m >= word[j].size())//ֻ��һ��ģ��
					{
						cout << mybook[word[j]][0] << '?' << endl;
						goto A1;
					}
					i++;
					--j;
					continue;//û���ҵ�����������ѭ��

				}
				if ((word[i].size() - str1.size()) < (str1.size() - word[j].size()))//��С�ڼ�
				{
					int k;
					for (k = 0; k < str1.size(); ++k)//����Ƿ�ģ��
						if (word[i][k] != str1[k])break;
					if (k >= str1.size())
					{
						cout << mybook[word[i]][0] << '?' << endl;
						goto A1;
					}
					++i;
					continue;//û���ҵ�����������ѭ��
				}
				if ((word[i].size() - str1.size()) > (str1.size() - word[j].size()))//�����ڼ�
				{
					int k;
					for (k = 0; k < word[j].size(); ++k)//����Ƿ�ģ��
						if (word[j][k] != str1[k])break;
					if (k >= word[j].size())
					{
						cout << mybook[word[j]][0] << '?' << endl;
						goto A1;
					}
					--j;
					continue;//û���ҵ�����������ѭ��
				}
			}
			while (i<word.size())//û�м�
			{
				int k;
				for (k = 0; k < str1.size(); ++k)//����Ƿ�ģ��
					if (word[i][k] != str1[k])break;
				if (k >= str1.size())
				{
					cout << mybook[word[i]][0] << '?' << endl;
					goto A1;
				}
				++i;
			}
			while (j >= 0)//û����
			{
				int k;
				for (k = 0; k < word[j].size(); ++k)//����Ƿ�ģ��
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
