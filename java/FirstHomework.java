class FirstHomework
{
    public static int lf(int num,int len)//立方,前len个数，包括len
    {
        int ans=0;
        for(int i=0;i<len;++i)
        {
            ans=ans+(num-i)*(num-i)*(num-i);
        }
        return ans;
    }
    public static void main(String argv[])
    {
        for(int num=2;num<100;num=num+1)
            for(int i=num;i>=2;--i)
                for(int j=num+1,sum3=lf(num,i);j*j*j<=sum3;j++)
                    if(j*j*j==sum3)
                    {
                        for(int k=i-1;k>0;--k)
                            System.out.printf("%d^3 + ",num-k);
                        System.out.printf("%d^3 = %d^3\n",num,j);
                    }
    }
}
