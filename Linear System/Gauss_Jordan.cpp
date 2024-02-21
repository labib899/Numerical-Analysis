#include<iostream>
using namespace std;

#define N 3

int main()
{
    double A[N][N+1]=
    {
        {2,1,3,8},
        {4,1,9,18},
        {8,1,27,72}
    };
    double x[N];

    for (int k=0;k<N;k++)
    {
        for (int i=0;i<N;i++)
        {
            if(i==k) continue;
            double factor=A[i][k]/A[k][k];
            for (int j=0;j<N;j++) A[i][j]=A[i][j]-factor*A[k][j];
            A[i][N]=A[i][N]-factor*A[k][N];
            x[i]=A[i][N]/A[i][i];
        }
    }

    for (int i=0;i<N;i++) printf("x%d=%f\n", i+1,x[i]);
}
