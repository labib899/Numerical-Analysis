#include <stdio.h>
#include <math.h>

#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

int main()
{
    double x0=0.0,y0=0.0,z0=0.0;
    double x1,y1,z1,e1,e2,e3,e=1e-6;

    printf("\ni\tx\ty\tz\n");
    int count=1;
    do
    {
    x1 = f1(x0,y0,z0);
    y1 = f2(x1,y0,z0);
    z1 = f3(x1,y1,z0);
    printf("%d\t%0.4lf\t%0.4lf\t%0.4lf\n",count, x1,y1,z1);

    e1 = fabs(x0-x1);
    e2 = fabs(y0-y1);
    e3 = fabs(z0-z1);

    x0 = x1;
    y0 = y1;
    z0 = z1;

    count++;

    } while(e1>e || e2>e || e3>e);

    printf("\nSolution: x=%0.3lf, y=%0.3lf and z = %0.3lf\n",x1,y1,z1);
}


/* In this example we are solving
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
