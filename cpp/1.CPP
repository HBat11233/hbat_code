#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
=======
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
        {
            if(fabs(mat[i][col]) - mat[max_r][col] > esp) max_r = i;
        }
        if(max_r != k )
        {
            for(int j = k; j < var+1; ++j) swap(mat[max_r][j], mat[k][j]);
        }
        if(fabs(mat[k][col] < esp)){ --k; continue; }
        for(int i = k+1; i < equ; ++i)
        {
            if(fabs(mat[i][col]) <= esp) continue;
            double tmp = mat[i][col] / mat[k][col];
            for(int j = col; j < var+1; ++j)
            {
                mat[i][j] -= mat[k][j]*tmp;
        }

    }
    for(int i = k; i < equ; ++i)
    {
        if(fabs(mat[i][var] > esp)) return 0;
    }
    if(k < var)
    {
        for(int i = k-1; i >= 0; --i)
        {
            free_num = 0;
            for(int j = 0; j < var; ++j)
            {
                if(fabs(mat[i][j]) > esp && free_x[j])
                {
                    free_num += 1;
                    free_index = j;
                }
            if(free_num > 1) continue;
            double tmp = mat[i][var];
            for(int j = 0; j < var; ++j)
            {
                if(j != free_index && fabs(mat[i][j]) > esp)
                {
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
            {
                tmp -= x[j]*mat[i][j];
        }
        x[i] = tmp / mat[i][i];
    }
    return 1;
}
>>>>>>> a919a4b8831f4f5a84015eb83fc1fb758233d394
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    string str="in";
    int num=0;
    int temp=-1;
    int ip=1;
    int i=0;
    int j=0;
    do
    {  
        temp=num;
        stringstream co;
        co<<ip;
        freopen((str+co.str()+".txt").c_str(),"w",stdout);
        for(;i<=10000;++i)
        {
            for(;j<=100000;++j)
            {
<<<<<<< HEAD
                cout<< i<<" "<<j<<endl;
                num++;
                if(num%1000==0)goto A1;
=======
                int k = 0;
                for(int j = 1; j <= 6; ++j)
                {
                    if(j+i <= 100)
                    {
                        k += 1;
                        mat[i][i+j] = -1;
                    }
                mat[i][i] = k;
                mat[i][101] = 6;
>>>>>>> a919a4b8831f4f5a84015eb83fc1fb758233d394
            }
            j=0;
        }
        A1:
        cout<<-1<<' '<<-1<<endl;
        ip++;
    }while(temp!=num);
    return 0;
}