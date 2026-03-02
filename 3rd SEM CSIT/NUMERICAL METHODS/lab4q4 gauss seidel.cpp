#include <stdio.h>
#include <math.h>
#define MAX 10
#define MAX_ITER 100  

int main() {
    int n, i, j, iter;
    float a[MAX][MAX], x[MAX], sum, error;
    
    printf("=====Swornim Maharjan=====\n");
    printf("=== Gauss-Seidel Method ===\n");
    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("\nEnter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nEnter initial guesses:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = ", i+1);
        scanf("%f", &x[i]);
    }

    for(iter = 1; iter <= MAX_ITER; iter++) {
        error = 0;

        for(i = 0; i < n; i++) {
            sum = a[i][n];

            for(j = 0; j < n; j++) {
                if(j != i) {
                    sum = sum - a[i][j] * x[j];
                }
            }

            float x_old = x[i];
            x[i] = sum / a[i][i];

            if(fabs(x[i] - x_old) > error)
                error = fabs(x[i] - x_old);
        }

        if(error < 0.0001) {
            printf("\nConverged after %d iterations.\n", iter);
            break;
        }
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, x[i]);
    }

    return 0;
}

