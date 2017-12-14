#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int nj(int n)//计算n的每一位上数字之和
{
    if(n/10==0)return n;//如果n是一位数，就直接返回n
    else return nj(n/10)+n%10;//如果不是，就返回n的个位上的数字与（（n去掉个位上的数字的那个数字）  的每一位上的数字之和）
    /*
    n%10    //就是n的个位数的数字    例如：n=1234;n%10==4;(n/10=123...4(1234除以10等于123余4))
    n/10    //就是n除去个位数后的数字(n除以10相当于将小数点左移一位1234.0--->123.4,因为int只保留整数所以1234/10==123)

    //所以   1234的每一位上数字之和就等于     4+(123的每一位上数字之和就等于)
    //       123的每一位上数字之和就等于     3+(12的每一位上数字之和)
    //       12的每一位上数字之和就等于      2+(1的每一位上数字之和)
    //       1的每一位上数字之和就等于       1==1
    //      12的每一位上数字之和就等于      2+(1)==3
    //      123的每一位上数字之和就等于    3+(3)==6
    //      1234的每一位上数字之和就等于    4+(6)==10
    */
}

int main()
{
    int a[55]={0};//a[i]为i的出现次数
    for(int i=1;i<=999999;++i)
    {
        int n=nj(i);
        a[n]++;//n出现的次数
    }
    int maxn=-1;//maxn这个变量用来记录最大出现次数，先初始化maxn的值小于所有a[i],这样的话只要比较,maxn的值就会被a[i]中的值替换掉，才能保证最后比较出的值是a[i]中的一个，而不是初始化的值；
                //如果是找最小的数，就初始化(记录变量)的值大于所有a[i]
    int ip;//ip这个变量用来记录出现maxn次的数字
    for(int i=1;i<=54;++i)
    {
        if(a[i]>maxn)//如果a[i] (i的出现次数) 比当前记录出现的最大次数还大，就更新maxn为a[i],更新ip为i;
        {
            maxn=a[i];
            ip=i;
        }
    }
    printf("%d\n",ip);
    //system("pause");
    return 0;
}
