    //aizu 2224
    #include<iostream>  
    #include<algorithm>  
    #include<cstring>  
    #include<cmath>  
    #include<cstdio>  
    #include<queue>  
    #define INF 0x3f3f3f3f  
    typedef long long ll;  
    using namespace std;  
      
    #define  N 11000  
      
    struct Emw  
    {  
        int u,v;  
        double d;  
    }emw[N*N/2+10];  
      
    struct node  
    {  
        double x,y;  
    }p[N];  
      
    int n,m;  
    int fr[N];  
      
    int cmp(struct Emw h,struct Emw f)  
    {  
        return h.d>f.d;  
    }  
      
    double Dist(node a,node b)  
    {  
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
    }  
      
    int Find(int x)  
    {  
        while(x!=fr[x])  
            x=fr[x];  
        return x;  
    }  
      
    int main()  
    {  
        int i,a,b;  
        while(scanf("%d%d",&n,&m)!=EOF)  
        {  
            for(i=1;i<=n;i++)  
                fr[i]=i;  
      
            for(i=1;i<=n;i++)  
            {  
                scanf("%lf%lf",&p[i].x,&p[i].y);  
            }  
      
            double sum=0.0; 
            for(i=0;i<m;i++)  
            {  
                scanf("%d%d",&a,&b);  
                emw[i].u=a;  
                emw[i].v=b;  
                emw[i].d=Dist(p[a],p[b]);  
                sum=sum+emw[i].d;  
            }  
      
            sort(emw,emw+m,cmp);  
      
            double s=0.0;
            for(i=0;i<m;i++)  
            {  
                int x,y;  
                x=Find(emw[i].u);  
                y=Find(emw[i].v);  
                if(x!=y)  
                {  
                    if(x>y)  
                        fr[x]=y;  
                    else  
                        fr[y]=x;  
      
                    s=s+emw[i].d;  
                }  
                else  
                    continue;  
            }  
            double ans=0.0;  
            ans=sum-s;    
            printf("%.3f\n",ans);  
        }  
        return 0;  
    }  