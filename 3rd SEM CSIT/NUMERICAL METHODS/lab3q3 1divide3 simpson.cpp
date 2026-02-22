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
    printf("1/3 simpson method\n");

    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    h = (b - a)/2;

    result = (h/3) * (f(a) + 4*f(a+h) + f(b));

    printf("Integration = %f", result);

    return 0;
}

