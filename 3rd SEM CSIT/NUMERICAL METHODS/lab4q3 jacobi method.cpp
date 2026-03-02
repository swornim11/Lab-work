#include <stdio.h>
#include <math.h>
#define MAX 10
#define MAX_ITER 100

int main() {
    int i, j, n, iter = 0;
    float a[MAX][MAX], x[MAX], x_new[MAX], error;

    printf("=====Swornim Maharjan=====\n");
    printf("=== Jacobi Iterative Method ===\n");

    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    // Check diagonal elements
    for(i = 0; i < n; i++) {
        if(a[i][i] == 0) {
            printf("Error: Zero on diagonal. Cannot apply Jacobi.\n");
            return 0;
        }
    }

    printf("\nEnter initial guesses:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = ", i+1);
        scanf("%f", &x[i]);
    }

    printf("\nIterations:\n");

    do {
        error = 0;

        for(i = 0; i < n; i++) {
            float sum = 0;

            for(j = 0; j < n; j++) {
                if(i != j) {
                    sum += a[i][j] * x[j];
                }
            }

            x_new[i] = (a[i][n] - sum) / a[i][i];

            if(fabs(x_new[i] - x[i]) > error) {
                error = fabs(x_new[i] - x[i]);
            }
        }

        for(i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        iter++;

        printf("Iteration %d : ", iter);
        for(i = 0; i < n; i++) {
            printf("x%d = %.6f  ", i+1, x[i]);
        }
        printf("\n");

        if(iter >= MAX_ITER) {
            printf("\nMethod is diverging or not converging.\n");
            return 0;
        }

    } while(error > 0.0001);

    printf("\nFinal Solution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i+1, x[i]);
    }

    return 0;
}
