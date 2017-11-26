#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int runf()
{
    int n,m;
    int pri[10]={0};//记录优先级在队列中的数量
    int time=1;
    int temp;
    int tail;//队列的尾部
    map <int,queue<int>>fp;//每个优先级在队列中的位置
    queue<int>que;
    cin>>n>>m;
    for(tail=0;tail<n;++tail)//储存队列
    {
        cin>>temp;
        que.push(temp);//队列
        pri[temp]++;//记录temp优先级的数量
        fp[temp].push(tail);//添加到对应优先级的队尾， 队列tail的优先级
    }
    int head=9;
    while(true)
    {
        while(pri[head]==0)
        {
            head--;
            continue;
        }
        while(que.front()<head)//head是最高优先级，head在队列位置之前的一点小于head,,,队列后移
        {
            if(m==fp[que.front()].front())m=tail;
            fp[que.front()].push(tail);
            fp[que.front()].pop();
            tail++;
            que.push(que.front());
            que.pop();
        }
        if(fp[head].front()==m)
        {
            cout<<time<<endl;
            return 0;
        }
        else
        {
            fp[head].pop();
            que.pop();
            time++;
            pri[head]--;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
        runf();
    system("pause");
    return 0;
}
