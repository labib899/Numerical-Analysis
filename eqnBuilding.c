#include<stdio.h>

const int N=11;
double x[11],y[11];
double A[11][4],transA[4][11],fx[11][1];
double left[4][4],right[4][1];
double ans[4];

// printing 2D array
void print(int r,int c,double arr[r][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) printf("%.3lf\t", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

//printing augmented matrix
void printAug()
{  
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++) printf("%.3lf\t", left[i][j]);
        printf("\t| %.3lf\n", right[i][0]);
    }
    printf("\n");
}

// initialize x and y matrix
void xy()
{
    x[0]=0.0, y[0]=1.0;
    x[1]=0.2; y[1]=1.04;
    x[2]=0.4; y[2]=1.16;
    x[3]=0.6; y[3]=1.36;
    x[4]=0.8; y[4]=1.64;
    x[5]=1.0; y[5]=2.0;
    x[6]=1.2; y[6]=2.44;
    x[7]=1.4; y[7]=2.96;
    x[8]=1.6; y[8]=3.56;
    x[9]=1.8; y[9]=4.24;
    x[10]=2.0; y[10]=5.0;
}

// building matrix A (11x4)
void matrixA()
{
    for(int i=0;i<11;i++)
    {
        A[i][0]=1;
        A[i][1]=x[i];
        A[i][2]=x[i]*x[i];
        A[i][3]=x[i]*x[i]*x[i];
    }
}

// building transpose of matrix A (4x11)
void transpose_of_matrix_A()
{
    for(int i=0;i<11;i++)
        for(int j=0;j<4;j++) 
            transA[j][i]=A[i][j];
}

// building fx matrix (11x1)
void matrixFx()
{
    for(int i=0;i<11;i++) fx[i][0]=y[i];
}

// transA * A (4x4)
void multiply_left()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<11;k++) left[i][j]+=(transA[i][k]*A[k][j]);
}

// transA * fx (4x1)
void multiply_right()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<1;j++)
            for(int k=0;k<11;k++) right[i][j]+=(transA[i][k]*fx[k][j]);
}

void modify(int a,int b)
{
    double coeff1=left[a][a];
    double coeff2=left[b][a];
    for(int i=0;i<4;i++)    
        left[b][i]=left[b][i]-(coeff2/coeff1)*left[a][i];
    right[b][0]=right[b][0]-(coeff2/coeff1)*right[a][0];
}

void diag()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(i!=j) modify(i,j);
}

void solve()
{   
    for(int i=0;i<4;i++)
    {
        ans[i]=right[i][0]/left[i][i];
        printf("c%d=%.3lf\n", i+1,ans[i]);
    }   
    printf("\nThe polynomial equation is:\n");
    printf("y=%.3lf + %.3lfx + %.3lfx^2 + %.3lfx^3\n", ans[0],ans[1],ans[2],ans[3]);
}


int main()
{
    xy();
    matrixA();
    printf("matrix A:\n");
    print(11,4,A);
    transpose_of_matrix_A();
    printf("transpose of matrix A:\n");
    print(4,11,transA);
    matrixFx();
    printf("matrix fx:\n");
    print(11,1,fx);
    multiply_left();
    printf("left matrix(A' x A):\n");
    print(4,4,left);
    multiply_right();
    printf("right matrix(A' x fx):\n");
    print(4,1,right);
    printf("Augmented matrix:\n");
    printAug();
    diag();
    printf("Augmented matrix(after modifying):\n");
    printAug();
    printf("Solution of the system:\n");
    solve();
    printf("\n");
}