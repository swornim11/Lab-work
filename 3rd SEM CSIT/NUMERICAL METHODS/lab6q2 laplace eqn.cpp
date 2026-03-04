#include <stdio.h>
#include <math.h>

#define N 4
#define MAX_ITER 100

int main()
{
    float u[N][N] = {0};
    float error;
    int i, j, iter;
    
    printf("===== Swornim Maharjan =====\n");
    printf("===== Laplace Equation Solver =====\n");

    // Set boundary conditions carefully

    // Bottom (y=0)
    for(i = 0; i < N; i++)
        u[i][0] = 100;

    // Top (y=3)
    for(i = 0; i < N; i++)
        u[i][N-1] = 200;

    // Left (x=0)
    for(j = 0; j < N; j++)
        u[0][j] = 200;

    // Right (x=3)
    for(j = 0; j < N; j++)
        u[N-1][j] = 100;

    // Gauss-Seidel iteration
    for(iter = 1; iter <= MAX_ITER; iter++)
    {
        error = 0;

        for(i = 1; i < N-1; i++)
        {
            for(j = 1; j < N-1; j++)
            {
                float old = u[i][j];

                u[i][j] = 0.25 * (
                    u[i+1][j] + u[i-1][j] +
                    u[i][j+1] + u[i][j-1]
                );

                error = fmax(error, fabs(u[i][j] - old));
            }
        }

        if(error < 0.0001)
            break;
    }

    printf("\nInterior values:\n\n");

    for(i = 1; i < N-1; i++)
        for(j = 1; j < N-1; j++)
            printf("u(%d,%d) = %.4f\n", i, j, u[i][j]);

    return 0;
}
