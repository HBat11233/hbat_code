#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector < vector <char> > words(1);
    vector <char> word;
    char temp;
    bool ok=true;
    while(scanf("%c",&temp)!=EOF)
    {
        if(temp=='\n')
        {
            words.push_back(word);
            for(int i=words.size()-1;i>=0;--i)
            {
                for(int j=0;j<words[i].size();++j)
                {
                    cout<<words[i][j];
                }
            }
            cout<<endl;
            word.clear();
            words.clear();
            words.push_back(word);
            ok=true;
            continue;
        }
        if(temp=='[')
        {
            ok=false;
            words.push_back(word);
            word.clear();
            continue;
        }
        else if(temp==']') 
        {
            ok=true;
            words.push_back(word);
            word.clear();
            continue;
        }
        if(ok)
            words[0].push_back(temp);
        else
            word.push_back(temp);
    }
    return 0;
}