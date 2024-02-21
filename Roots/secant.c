#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define maxN 200
#define F(x) x*x*x+4*x*x-10

int main()
{
    double x1=1.5,x2=2.0,e=10e-6;
    double fx1=F(x1),fx2=F(x2);

    for(int i=1;i<maxN;i++)
    {
        double x3=x2-fx2*(x2-x1)/(fx2-fx1);
        double fx3=F(x3);
        if(fabs(fx3)<=e)
        {
            printf("Root=%lf,itr=%d\n", x2,i);
            return 1;
        }
        x1=x2,x2=x3;
        fx1=fx2,fx2=fx3;
    }
    printf("Itr overflow...\n");
}



