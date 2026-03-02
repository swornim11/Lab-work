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
    float k1, k2, y_predict;
    printf("---Swornim Maharjan---\n");

    printf("Heun's Method (Improved Euler Method)\n");
    printf("Enter step size (h): ");
    scanf("%f", &h);

    steps = (xn - x0) / h;

    for(i = 1; i <= steps; i++)
    {
        k1 = f(x0, y0);

        // Predictor step
        y_predict = y0 + h * k1;

        k2 = f(x0 + h, y_predict);

        // Corrector step
        y0 = y0 + (h / 2) * (k1 + k2);

        x0 = x0 + h;

        printf("x = %.2f, y = %.6f\n", x0, y0);
    }

    printf("\nApproximate value at x = 0.4 is y = %.6f\n", y0);

    return 0;
}
