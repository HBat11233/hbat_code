#include "iostream"
#include "vector"
#include "cstdio"
#include "cstdlib"
#include "algorithm"
#include "cmath"
#include "ctime"
#include "cstring"
#include "string"

#define OPENEXE "*******This is HBat EXE!*******\n"

using namespace std;

int main()
{
    cout << OPENEXE;
    cout << "Plese input your name!\n:";
    string str;
    getline(cin,str);
    cout << "Hello "<< str << '!' << endl;
    system("pause");
    return 0;
}
