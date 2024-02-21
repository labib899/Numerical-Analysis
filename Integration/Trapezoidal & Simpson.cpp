#include<iostream>
using namespace std;

#define maxN 10
#define pi   3.14159

int main()
{
    double sumX=0,sumO=0.0,sumE=0,h;
    double x[maxN+1]={0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
    double y[maxN+1]={1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};

    double T,S;
    h=x[1]-x[0];
    sumX=y[0]+y[maxN];
    for(int i=1;i<maxN;i+=2) sumO+=y[i];
    for(int i=2;i<maxN;i+=2) sumE+=y[i];
    T=h*(sumX+2*(sumO+sumE))/2.0;
    S=h*(sumX+4*sumO+2*sumE)/3.0;

    printf("Integration(Trapezoidal)= %lf\n",T);
    printf("Integration(Simpson's 1/3)= %lf\n",S);
}

