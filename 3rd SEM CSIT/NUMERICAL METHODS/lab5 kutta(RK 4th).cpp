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
    float k1, k2, k3, k4;
    printf("---Swornim Maharjan---\n");

    printf("Runge-Kutta 4th Order Method\n");
    printf("Enter step size (h): ");
    scanf("%f", &h);

    steps = (xn - x0) / h;

    for(i = 1; i <= steps; i++)
    {
        k1 = f(x0, y0);
        k2 = f(x0 + h/2, y0 + h*k1/2);
        k3 = f(x0 + h/2, y0 + h*k2/2);
        k4 = f(x0 + h, y0 + h*k3);

        y0 = y0 + (h/6)*(k1 + 2*k2 + 2*k3 + k4);

        x0 = x0 + h;

        printf("x = %.2f, y = %.6f\n", x0, y0);
    }

    printf("\nApproximate value at x = 0.4 is y = %.6f\n", y0);

    return 0;
}
