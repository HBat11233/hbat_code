#include <stdio.h>
#include <string.h>
#include <math.h>
const int N = 50005;
int res[N], n;
 
int main() 
{
	res[1] = 1;
	for (int i = 2; i < N; i++)
		if (!res[i])
			for (int j = i; j < N; j += i) 
            {
				if (!res[j])
					res[j] = j;
				res[j] = res[j] / i * (i - 1);  //很强。。流弊
			}//以上为欧拉函数，即求<=n的数中与n互质的个数
	for (int i = 3; i < N; i++)
		res[i] += res[i - 1];
	while (scanf("%d", &n) && n) 
    {
		if (n == 1) 
        {
			printf("1\n");
			continue;
		}
		printf("%d\n", res[n] * 2 + 1);
	}
	return 0;
}
