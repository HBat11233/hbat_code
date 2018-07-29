#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("out.txt","w",stdout);
#endif // DEBUG
    map<char,bool>book;
    for(char ch='A';ch<='Z';ch++)
        book[ch]=false;
    book['A']=true;
    book['H']=true;
    book['I']=true;
    book['M']=book['O']=book['T']=book['U']=book['V']=book['W']=book['X']=book['Y']=true;
    string str;
    while(cin>>str)
    {
        bool ans=false;
        for(int i=0;i<str.size()/2;i++)
        {
            if(str[i]!=str[str.size()-i-1]||!book[str[i]])
            {
                ans=true;
                break;
            }
        }
        if(!ans&&
            str.size()%2==1&&
            !book[str[str.size()/2]])ans=true;
        if(ans)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}