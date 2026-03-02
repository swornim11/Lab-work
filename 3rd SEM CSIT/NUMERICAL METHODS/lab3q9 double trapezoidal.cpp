#include <stdio.h>
#include <math.h>

// Function to be integrated
float f(float x, float y)
{
    // Example function: f(x,y) = x * y
    return x * y;
}

int main()
{
    int nx, ny, i, j;
    float a, b, c, d, hx, hy, sum = 0, x, y, result;
    printf("=====Swornim Maharjan=====\n");
    printf("===== Double Integration using Trapezoidal Rule =====\n");

    printf("Enter lower and upper limit for x (a b): ");
    scanf("%f %f", &a, &b);

    printf("Enter lower and upper limit for y (c d): ");
    scanf("%f %f", &c, &d);

    printf("Enter number of subintervals in x direction: ");
    scanf("%d", &nx);

    printf("Enter number of subintervals in y direction: ");
    scanf("%d", &ny);

    hx = (b - a) / nx;
    hy = (d - c) / ny;

    for (i = 0; i <= nx; i++)
    {
        x = a + i * hx;

        for (j = 0; j <= ny; j++)
        {
            y = c + j * hy;

            // Weight factor
            if ((i == 0 || i == nx) && (j == 0 || j == ny))
                sum += f(x, y);
            else if (i == 0 || i == nx || j == 0 || j == ny)
                sum += 2 * f(x, y);
            else
                sum += 4 * f(x, y);
        }
    }

    result = (hx * hy / 4) * sum;

    printf("Value of Double Integration = %f\n", result);

    return 0;
}

