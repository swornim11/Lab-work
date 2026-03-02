#include <stdio.h>

float f(float x, float y)
{
    return x + y;
}

int main()
{
    float x0 = 0, y0 = 1;
    float h, xn = 0.4;
    int steps, i;
    printf("---Swornim Maharjan---\n");
    printf("Euler's Method\n");
    printf("Enter step size (h): ");
    scanf("%f", &h);

    steps = (xn - x0) / h;

    printf("\nSteps:\n");
    for(i = 1; i <= steps; i++)
    {
        y0 = y0 + h * f(x0, y0);
        x0 = x0 + h;

        printf("x = %.2f, y = %.6f\n", x0, y0);
    }

    printf("\nApproximate value at x = 0.4 is y = %.6f\n", y0);

    return 0;
}
