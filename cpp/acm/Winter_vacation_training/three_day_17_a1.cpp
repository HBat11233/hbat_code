    #include <iostream>  
    #include <cmath>  
    #include <iomanip>  
    #include <string.h>  
    #include <algorithm>  
    using namespace std;  
    const int maxNode=210;  
    double mp[maxNode][maxNode];  
    int nodeNum;  
      
    struct P  
    {  
        int x,y;  
    }point[maxNode];  
      
    double dis(P a,P b)  
    {  
        return sqrt((b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x));  
    }  
      
    void floyed()  
    {  
        for(int k=1;k<=nodeNum;k++)  
            for(int i=1;i<=nodeNum;i++)  
            for(int j=1;j<=nodeNum;j++)  
                mp[i][j]=min(mp[i][j],max(mp[i][k],mp[k][j]));//许多通路中最长边中的最小边  
    }  
      
    int main()  
    {  
        int c=1;  
        while(cin>>nodeNum&&nodeNum)  
        {  
            for(int i=1;i<=nodeNum;i++)  
                cin>>point[i].x>>point[i].y;  
            for(int i=1;i<=nodeNum;i++)  
                for(int j=i+1;j<=nodeNum;j++)  
            {  
                mp[i][j]=mp[j][i]=dis(point[i],point[j]);  
            }  
            floyed();  
            cout<<"Scenario #"<<c++<<endl;  
            cout<<setiosflags(ios::fixed)<<setprecision(3)<<"Frog Distance = "<<mp[1][2]<<endl;  
            cout<<endl;  
        }  
        return 0;  
    }  