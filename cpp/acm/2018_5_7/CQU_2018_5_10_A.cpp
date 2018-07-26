#include <iostream>
#include <cstdio>

#define max(a,b) (a>b? a:b)

using namespace std;

const int N = (1<<21);                      //(1e6+(1<<20)-1)

struct map01
{
    int node[N][2];                         //二叉树
    int len;
    const int root = 0;

    int newnode()                          //新建节点
    {
        node[len][0]=node[len][1]=-1;
        return len++;                       //返回使用节点下标
    }

    void init()
    {
        len=0;
        newnode();
    }

    void insert(const int &x)
    {
        int now = root;
        for(int j=30;j>=0;--j)              //剑长30位，从31位开始，最高位作为树的根，开始建树；
        {
            int bit = x&(1<<j)? 1:0;        //判断j+1位的符号
            if(node[now][bit]==-1)node[now][bit]=newnode();    //对应节点不存在建立，否则过
            now=node[now][bit];             //下一层
        }
    }

    int search(const int &x)
    {
        int now = root;
        int ans=0;
        for(int j=30;j>=0;--j)
        {
            int bit = x&(1<<j)? 1:0;
            if(node[now][!bit]!=-1)ans|=(1<<j),now = node[now][!bit];
            else now = node[now][bit];
        }
        return ans;
    }
}trie;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        trie.init();
        int temp;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&temp);
            trie.insert(temp);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d",&temp);
            ans=max(ans,trie.search(temp));
        }
        cout<<ans<<endl;
    }
    return 0;
}













//https://blog.csdn.net/just_sort/article/details/51488288
/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = (1<<21);                      //(1e6+(1<<20))
struct node
{
    int ch[N][2];
    int root,L;
    int newnode()                           //建立一个新的节点
    {
        ch[L][0]=ch[L][1]=-1;               //二叉树！！！！！
        return L++;
    }
    void Init()
    {
        L=0,root=newnode();                 //重新开始
    }
    void Insert(int x)
    {
        int now=root;                       //从头开始
        for(int j=30; j>=0; j--)            //1e9有30为，1<<30有30位
        {
            int go=(x&(1<<j))?1:0;          //1<<j,从最高位前一位开始判断,判断j+1位的符号，？？？
            if(ch[now][go]==-1)             //如果没有记录则记录，如果记录过则跳过
            {
                ch[now][go]=newnode();      //记录并移动到下一位
                now=ch[now][go];
            }else
                now=ch[now][go];
        }
    }
    int Query(int x)
    {
        int now=root;                       //从头开始
        int ans=0;                          //存储结果
        for(int j=30;j>=0;j--)
        {
            int go=(x&(1<<j))?1:0;          //1<<j,从最高为开始判断,判断j+1位的符号，
            if(ch[now][!go]!=-1) ans|=(1<<j),now=ch[now][!go];  //如果第j+1的非存在，则在j+1位 xor 为1
            else now=ch[now][go];           //如果第j+1的非不存在，判断他的下一位
        }
        return ans;                         //返回结果
    }
    void print() const
    {
        cout<<setw(4)<<-1;
        for(int i=0;i<L;++i)
            cout<<setw(4)<<i;
        cout<<endl;
        cout<<setw(4)<<0;
        for(int i=0;i<L;++i)
            cout<<setw(4)<<ch[i][0];
        cout<<endl;
        cout<<setw(4)<<1;
        for(int i=0;i<L;++i)
            cout<<setw(4)<<ch[i][1];
        cout<<endl<<endl;
        return;
    }
}Trie;
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        Trie.Init();
        int maxans=-1;
        int val;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&val);
            Trie.Insert(val);
            Trie.print();
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&val);
            maxans=max(maxans,Trie.Query(val));
        }
        printf("%d\n",maxans);
    }
    return 0;
}
*/