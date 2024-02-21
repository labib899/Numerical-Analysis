#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define maxN 200
#define F(x) x*x*x+4*x*x-10
#define dF(x) 3*x*x+8*x

int main()
{
    double x1=1.5,e=10e-6;
    double fx1=F(x1),dfx1=dF(x1);

    for(int i=1;i<maxN;i++)
    {
        double x2=x1-fx1/dfx1;
        double fx2=F(x2);
        if(fabs(fx2)<=e)
        {
            printf("Root=%lf,itr=%d\n", x2,i);
            return 1;
        }
        x1=x2,fx1=fx2,dfx1=dF(x2);
    }
    printf("Itr overflow...\n");
}


