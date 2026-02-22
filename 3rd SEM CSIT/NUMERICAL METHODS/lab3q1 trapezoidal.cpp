#include <stdio.h>
#include <math.h>

// Define the function here
// Example: f(x) = x^2
float f(float x) {
    return x*x*x+2;
}

int main() {
    float a, b, h, integral;
    printf("---Swornim Maharjan---\n");
    printf("trapezoidal method\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    h = b - a;

    integral = (h / 2) * (f(a) + f(b));

    printf("\nValue of integral = %.4f\n", integral);

    return 0;
}

