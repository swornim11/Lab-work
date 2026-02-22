#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1/(1 + x*x);
}

int main()
{
    float a, b, h, result;
    printf("---Swornim Maharjan---\n");
    printf("3/8 simpson method\n");

    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    h = (b - a)/3;

    result = (3*h/8) * (f(a) + 3*f(a+h) + 3*f(a+2*h) + f(b));

    printf("Integration = %f", result);

    return 0;
}

