#include <stdio.h>
#include <math.h>

#define MAX 10   // Maximum Romberg table size

// Function to be integrated
float f(float x)
{
    // Example: f(x) = x^2
    return x * x;
}

// Trapezoidal Rule Function
float trapezoidal(float a, float b, int n)
{
    float h, sum = 0;
    int i;

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
        sum += 2 * f(a + i * h);

    return (h / 2) * sum;
}

int main()
{
    float a, b;
    float R[MAX][MAX];
    int i, j, n, level;
    printf("=====Swornim Maharjan=====\n");
    printf("===== Romberg Integration =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of levels: ");
    scanf("%d", &level);

    // First column (Trapezoidal values)
    for (i = 0; i < level; i++)
    {
        n = pow(2, i);
        R[i][0] = trapezoidal(a, b, n);
    }

    // Romberg extrapolation
    for (i = 1; i < level; i++)
    {
        for (j = 1; j <= i; j++)
        {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) /
                      (pow(4, j) - 1);
        }
    }

    printf("\nRomberg Table:\n");
    for (i = 0; i < level; i++)
    {
        for (j = 0; j <= i; j++)
            printf("%10.6f ", R[i][j]);
        printf("\n");
    }

    printf("\nFinal Value of Integration = %f\n", R[level - 1][level - 1]);

    return 0;
}

