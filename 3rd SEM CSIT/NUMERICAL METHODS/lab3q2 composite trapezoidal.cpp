#include <stdio.h>
#include <math.h>

// Define the function to be integrated here
// Example: f(x) = x^2
float f(float x) {
    return exp(x);
}

int main() {
    float a, b, h, sum;
    int n, i;
        printf("---Swornim Maharjan---\n");
    printf("Composite trapezoidal method\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of sub-intervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;

    sum = f(a) + f(b);

    for(i = 1; i < n; i++) {
        sum = sum + 2 * f(a + i * h);
    }

    float integral = (h / 2) * sum;


    printf("\nValue of integral = %.4f\n", integral);

    return 0;
}

