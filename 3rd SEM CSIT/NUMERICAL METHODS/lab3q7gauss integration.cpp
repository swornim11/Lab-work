#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x)
{
    // Example: f(x) = x^2
    return x * x;
}

int main()
{
    double a, b, x1, x2, result;
    double t;

    printf("===== Swornim Maharjan =====\n");
    printf("===== Gauss Integration (2-Point) =====\n");

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

    // Gauss point ±1/sqrt(3)
    t = 1.0 / sqrt(3.0);

    // Change of interval
    x1 = ((b - a) / 2.0) * (-t) + ((a + b) / 2.0);
    x2 = ((b - a) / 2.0) * (t) + ((a + b) / 2.0);

    // Integration formula
    result = ((b - a) / 2.0) * (f(x1) + f(x2));

    printf("Value of integration = %.6lf\n", result);

    return 0;
}

