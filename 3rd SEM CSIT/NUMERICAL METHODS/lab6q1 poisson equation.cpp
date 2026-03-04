#include <stdio.h>
#include <math.h>

#define N 4
#define H 0.5
#define MAX_ITER 100

int main()
{
    float f[N][N] = {0};
    float x, y;
    float error;
    int i, j, iter;

    printf("===== Swornim Maharjan =====\n");
    printf("===== Poisson Equation Solver =====\n");

    for(iter = 1; iter <= MAX_ITER; iter++)
    {
        error = 0;

        for(i = 1; i < N-1; i++)
        {
            for(j = 1; j < N-1; j++)
            {
                x = i * H;
                y = j * H;

                float old = f[i][j];

                f[i][j] = 0.25 * (
                    f[i+1][j] + f[i-1][j] +
                    f[i][j+1] + f[i][j-1]
                    - H*H * (3 * x * x * y)
                );

                error = fmax(error, fabs(f[i][j] - old));
            }
        }

        if(error < 0.0001)
            break;
    }

    printf("\nSolution after %d iterations:\n\n", iter);

    for(i = 1; i < N-1; i++)
    {
        for(j = 1; j < N-1; j++)
        {
            printf("f(%.1f , %.1f) = %.4f\n", 
                   i*H, j*H, f[i][j]);
        }
    }

    return 0;
}
