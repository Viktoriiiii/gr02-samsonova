#include <stdio.h>
#include <math.h>

double ff(double x)
{
    return -3.0 * cos(x);
}

int main()
{
    double a, b;
    printf("a, b: ");
    scanf("%lf %lf", &a, &b);
    
    double eps;
    printf("eps: ");
    scanf("%lf", &eps);
    
    double c, fa, fc;
    do
    {
        c = (a + b) * 0.5;
        fa = ff(a);
        fc = ff(c);
        if (fa * fc < 0.0) b = c;
        else a = c;
    }
    while (fabs(b-a) > eps);
    printf("x: %.6lf\n", c);
    printf("y: %.6lf\n", fc);
    
    return 0;
}
