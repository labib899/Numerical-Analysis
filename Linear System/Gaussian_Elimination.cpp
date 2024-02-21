#include<iostream>
using namespace std;

#define N 3

int main()
{
    double A[N][N+1] =
    {
        {2,1,3,8},
        {4,1,9,18},
        {8,1,27,72}
    };
    double x[N];

    for (int k=0;k<N-1;k++)
    {
        for (int i=k+1;i<N;i++)
        {
            double factor = A[i][k] / A[k][k];
            for (int j=0;j<=N;j++) A[i][j]=A[i][j]-factor*A[k][j];
        }
    }

    // substitute backwards
    for (int i=N-1;i>=0;i--)
    {
        double sum=0.0;
        for (int j=i+1;j<N;j++) sum+=A[i][j]*x[j];
        x[i]=(A[i][N]-sum)/A[i][i];
    }

    // Augmented matrix
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N+1;j++) cout<<A[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    // Solution
    for (int i=0;i<N;i++) printf("x%d=%lf\n", i+1,x[i]);

}
