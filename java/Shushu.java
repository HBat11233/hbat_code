class Shushu
{
    public static void main(String argv[])
    {
        boolean [] arraynum = new boolean[101];      //    2:false       ，       4:true
        arraynum[0]=true;
        arraynum[1]=true;
        for(int i=0;i<=100;i++)
        {
            if(arraynum[i])continue;
            for(int j=2;i*j<=100;++j)
                arraynum[i*j]=true;
        }
        for(int i=0;i<=100;++i)
            if(!arraynum[i])System.out.print(i+" ");
        System.out.print("\n");
    }
}