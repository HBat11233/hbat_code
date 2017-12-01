#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    for(int i=0;i<16;++i)
    {
        for(int j=0;j<16;++j)
        {
            if(i==0||i==15||j==0||j==15)continue;
            printf("(%2d,%2d) ",i,j);
        }
        printf("\n");
    }
    system("pause");    
    return 0;
}