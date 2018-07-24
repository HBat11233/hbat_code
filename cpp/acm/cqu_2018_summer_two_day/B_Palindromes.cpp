#include <bits/stdc++.h>

using namespace std;

map<char,char>book;

bool rw(const string &str)
{
    for(int i=0,j=str.size()-1;i<j;i++,j--)
        if(str[i]!=str[j])return false;
    return true;
}

bool rj(const string &str)
{
    for(int i=0,j=str.size()-1;i<=j;i++,j--)
        if(!book.count(str[i])||(book.count(str[i])&&book[str[i]]!=str[j]))return false;
    return true;
}

int main()
{
    string ansstr[4]=
    {
        " -- is not a palindrome.",
        " -- is a regular palindrome.",
        " -- is a mirrored string.",
        " -- is a mirrored palindrome."
    };
    book['A']='A';
    book['E']='3';
    book['3']='E';
    book['H']='H';
    book['I']='I';
    book['J']='L';
    book['L']='J';
    book['M']='M';
    book['O']='O';
    book['S']='2';
    book['2']='S';
    book['T']='T';
    book['U']='U';
    book['V']='V';
    book['W']='W';
    book['X']='X';
    book['Y']='Y';
    book['Z']='5';
    book['5']='Z';
    book['1']='1';
    book['8']='8';
    string str;
    while(cin>>str)
    {
        cout<<str;
        if(rw(str))
        {
            if(rj(str))
                cout<<ansstr[3]<<'\n';
            else
                cout<<ansstr[1]<<'\n';
        }else if(rj(str))
            cout<<ansstr[2]<<'\n';
        else
            cout<<ansstr[0]<<'\n';
        printf("\n");
    }
    return 0;
}