#include <bits/stdc++.h>

using namespace std;
const int N = 105;
const double esp = 1e-8;
int tp[N];
double mat[N][N];
double x[N];
int free_x[N];

int Gauss(int equ, int var)
{
    int k;
    int max_r, col;
    int free_index, free_num;
    memset(free_x, 1, sizeof(free_x));
    memset(x, 0, sizeof(x));
    for(k = col = 0; k < equ && col < var; ++k, ++col)
    {
        max_r = k;
        for(int i = k+1; i < equ; ++i)
            if(fabs(mat[i][col]) - mat[max_r][col] > esp) max_r = i;
        if(max_r != k )
            for(int j = k; j < var+1; ++j)
                swap(mat[max_r][j], mat[k][j]);
        if(fabs(mat[k][col] < esp)){ --k; continue; }
        for(int i = k+1; i < equ; ++i)
        {
            if(fabs(mat[i][col]) <= esp) continue;
            double tmp = mat[i][col] / mat[k][col];
            for(int j = col; j < var+1; ++j)
                mat[i][j] -= mat[k][j]*tmp;
        }

    }
    for(int i = k; i < equ; ++i)
        if(fabs(mat[i][var] > esp)) return 0;
    if(k < var)
    {
        for(int i = k-1; i >= 0; --i)
        {
            free_num = 0;
            for(int j = 0; j < var; ++j)
                if(fabs(mat[i][j]) > esp && free_x[j])
                {
                    free_num += 1;
                    free_index = j;
                }
            if(free_num > 1) continue;
            double tmp = mat[i][var];
            for(int j = 0; j < var; ++j)
                if(j != free_index && fabs(mat[i][j]) > esp)
                    tmp -= mat[i][j]*x[j];
            free_x[free_index] = 0;
            x[free_index] = tmp/mat[i][free_index];
        }
        return var-k;
    }
    for(int i = var-1; i >= 0; --i)
    {
        double tmp = mat[i][var];
        for(int j = i+1; j < var; ++j)
        {
            if(fabs(mat[i][j]) > esp)
                tmp -= x[j]*mat[i][j];
        }
        x[i] = tmp / mat[i][i];
    }
    return 1;
}
int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--)
    {
        int a, b, n;
        scanf("%d", &n);
        memset(tp, 0, sizeof(tp));
        for(int i = 0; i < n; ++i) 
        {
            scanf("%d%d", &a, &b);
            tp[a] = b;
        }
        memset(mat, 0, sizeof(mat));
        mat[100][100] = 1;
        mat[100][101] = 0;
        for(int i = 1; i < 100; ++i)
        {
            if(tp[i])
            {
                mat[i][i] = 1;
                mat[i][tp[i]] = -1;
                mat[i][101] = 0;
            }
            else
            {
                int k = 0;
                for(int j = 1; j <= 6; ++j)
                    if(j+i <= 100)
                    {
                        k += 1;
                        mat[i][i+j] = -1;
                    }
                mat[i][i] = k;
                mat[i][101] = 6;
            }
        }
        Gauss(105, 101);
        printf("Case %d: %.8f\n", ca++, x[1]);
    }
}