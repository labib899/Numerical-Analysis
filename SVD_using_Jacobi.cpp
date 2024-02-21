#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m, i, j, p, q, flag;
    double mat[10][10], a[10][10], d[10][10], s[10][10], s1[10][10], s1t[10][10];
    double temp[10][10], theta, zero=1e-5, max, pi=3.141592654;

    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n >> m;

    double matrix[n][m];
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i <n; i++)
        for(int j = 0; j <m; j++) cin >> matrix[i][j];

    double transpose[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j <n; j++) transpose[i][j] = matrix[j][i];


    cout << "\nThe transpose of the matrix:" << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <n; j++) cout << transpose[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = 0;
            for(int k = 0; k <m; k++)
            {
                a[i][j] += matrix[i][k] * transpose[k][j];
            }
        }
    }


    cout << "\nThe product of the matrix and its transpose matrix:" << endl;
    for(int i = 0; i <n; i++)
    {
        for(int j = 0; j <n; j++) cout <<  a[i][j] << " ";
        cout << endl;
    }

    cout<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            d[i][j]= a[i][j];
            if(i==j) s[i][j]= 1;
            else s[i][j]= 0;
        }
    }

    do
    {
        flag= 0;
        p=0;
        q=1;
        max= fabs(d[p][q]);

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j && max<fabs(d[i][j]))
                {
                    max= fabs(d[i][j]);
                    p= i;
                    q= j;
                }
            }
        }

        if(d[p][p]==d[q][q])
        {
            if (d[p][q] > 0) theta= pi/4;
            else theta= -pi/4;
        }
        else theta=0.5*atan(2*d[p][q]/(d[p][p]-d[q][q]));

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                {
                    s1[i][j]= 1;
                    s1t[i][j]= 1;
                }
                else
                {
                    s1[i][j]= 0;
                    s1t[i][j]= 0;
                }
            }
        }

        s1[p][p]= cos(theta);
        s1t[p][p]= s1[p][p];

        s1[q][q]= cos(theta);
        s1t[q][q]= s1[q][q];

        s1[p][q]= -sin(theta);
        s1[q][p]= sin(theta);

        s1t[p][q]= s1[q][p];
        s1t[q][p]= s1[p][q];

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp[i][j]= 0;
                for(p=0; p<n; p++)  temp[i][j]+= s1t[i][p]*d[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                d[i][j]= 0;
                for(p=0; p<n; p++)  d[i][j]+= temp[i][p]*s1[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp[i][j]= 0;
                for(p=0; p<n; p++)  temp[i][j]+= s[i][p]*s1[p][j];
            }
        }

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)  s[i][j]= temp[i][j];

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j && fabs(d[i][j]>zero)) flag=1;
            }
        }
    } while(flag==1);
    int eigen[n];
    double w[n][n];
    printf("\nThe eigenvalues are:\n");
    for(i=0; i<n; i++)
    {
        cout<<d[i][i]<<" ";
        eigen[i]=d[i][i];
    }
    cout<<endl;
    sort(eigen, eigen + n, greater<int>());
   // for(int i=0;i<n;i++)cout<<eigen[i]<<" ";cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) w[i][j]=sqrt(eigen[i]);
            else w[i][j]=0;
        }
    }
    cout<<"\nThe corresponding eigenvectors:"<<endl;
    double V[n][n];
    for(j=0; j<n; j++)
    {
        cout<<"(";
        for(i=0; i<n-1; i++)
        {
            printf("% 8.4lf",s[i][j]);
            V[i][j]=s[i][j];
        }
        printf("%8.4lf )^T\n",s[n-1][j]);V[i][j]=s[n-1][j];
    }
    cout<<"\nMatrix V:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<V[i][j]<<"  ";
        cout<<endl;
    }

    //Transpose of V
    double Vt[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j <n; j++) Vt[i][j] = V[j][i];

    cout<<"\nW matrix:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout<<w[i][j]<<" ";
        cout<<endl;
    }
    double w1[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) w1[i][j] = (1.0 / w[i][j]);
            else w1[i][j] = 0;
        }
    }

    cout << "\nThe inverse of the diagonal matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout <<w1[i][j] << "   ";
        cout << endl;
    }
    double U1[n][n],U[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++) U1[i][j] += a[i][k] * Vt[k][j];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) U[i][j] += U1[i][k] * w1[k][j];

    cout<<"\nMatrix U:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout<<U[i][j]<<" ";
        cout<<endl;
    }


}