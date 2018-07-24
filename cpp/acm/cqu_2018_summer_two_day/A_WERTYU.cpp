#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string str;
    map<char,char>book;
    book['W']='Q';book['E']='W';book['R']='E'; 
    book['T']='R';book['Y']='T';book['U']='Y'; 
    book['I']='U';book['O']='I';book['P']='O'; 
    book['[']='P';book[']']='[';book['\\']=']'; 
    book['S']='A';book['D']='S';book['F']='D';
    book['G']='F';book['H']='G';book['J']='H'; 
    book['K']='J';book['L']='K';book[';']='L'; 
    book['\'']=';';book['X']='Z';book['C']='X'; 
    book['V']='C';book['B']='V';book['N']='B'; 
    book['M']='N';book[',']='M';book['.']=',';
    book['/']='.';book['2']='1';book['3']='2'; 
    book['4']='3';book['5']='4';book['6']='5'; 
    book['7']='6';book['8']='7';book['9']='8'; 
    book['0']='9';book['-']='0';book['=']='-'; 
    book['1']='`'; 
    while(getline(cin,str))
    {
        for(int i=0;i<str.size();++i)
        {
            if(book.count(str[i]))printf("%c",book[str[i]]);
            else printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}