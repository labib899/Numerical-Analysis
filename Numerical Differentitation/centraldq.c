#include<stdio.h>
#include<math.h>

#define maxN 10

int main()
{
    double a=0.0,b=2.0,h=(b-a)/maxN;
    double x[maxN+1],f[maxN+1],df[maxN+1];

    x[0]=a;
    for(int i=1;i<maxN;i++) x[i]=x[i-1]+h;
    x[maxN]=b;

    for(int i=0;i<=maxN;i++) f[i]=x[i]*x[i]+1;

    df[0]=(f[1]-f[0])/(x[1]-x[0]); // forward dq
    for(int i=1;i<maxN;i++) df[i]=(f[i+1]-f[i-1])/(x[i+1]-x[i-1]); // central dq
    df[maxN]=(f[maxN]-f[maxN-1])/(x[maxN]-x[maxN-1]); // backward dq

    printf("i\tx[i]\t\tf[i]\t\tdf[i]\n");
    for(int i=0;i<=maxN;i++) printf("%d\t%lf\t%lf\t%lf\n", i,x[i],f[i],df[i]);
}

