#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        map<int,int>book;
        vector<int>ans;
        ans.push_back(a/b);
        int n1=a%b;
        int n=0;
        book[n1]=n;
        while(true)
        {
            int k=0;
            while(n1<b&&n1)
            {
                if(k)
                {
                    ans.push_back(0);
                    book[n1]=n;                         //2 90,....
                }
                n++;
                k++;
                n1*=10;
                if(book.count(n1))break;                //168 345,
            }
            ans.push_back(n1/b);
            int en=n1%b;
            if(book.count(en))break;
            else
            {
                book[en]=n;
                n1=en;
            }
        }
        int po=book[n1%b];
        n-=po;
        n=n?n:1;
        printf("%d/%d = %d.",a,b,ans[0]);
        for(int i=1;i<ans.size();++i)
        {
            if((i-1)==po)printf("(");
            printf("%d",ans[i]);
            if(i==50)
            {
                printf("...");
                break;
            }
        }
        if(po<=49)printf(")\n");
        else printf("\n");
        printf("   %d = number of digits in repeating cycle\n\n",n);
    }
    return 0;
}