#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define maxN 200
#define F(x) x*x*x+4*x*x-10

int main()
{
    double a=1.25,b=1.5,e=10e-6,c;
    double fa=F(a),fb=F(b),fc;

    if(fa*fb>=0)
    {
        printf("No root...\n");
        return 0;
    }

    for(int i=1;i<maxN;i++)
    {
        c=(a*fb-b*fa)/(fb-fa);
        fc=F(c);
        if(fabs(fc)<=e)
        {
            printf("Root=%lf,itr=%d\n", c,i);
            return 1;
        }
        if(fa*fc<0) b=c,fb=F(c);
        else a=c,fa=F(c);
    }
    printf("Itr overflow...\n");
}

