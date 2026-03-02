#include <stdio.h>
#include <math.h>

#define MAX 10
#define MAX_ITER 100  // Maximum iterations

int main() {
    int n, i, j, k;
    float A[MAX][MAX], x[MAX], y[MAX];
    float lambda_old = 0, lambda_new = 0, error;

    printf("=====Swornim Maharjan=====\n");
    printf("=== Power Method for Eigenvalue ===\n");
    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter initial guess vector:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("\nIteration\tEigenvalue\n");

    for(k = 0; k < MAX_ITER; k++) {

        for(i = 0; i < n; i++) {
            y[i] = 0;
            for(j = 0; j < n; j++) {
                y[i] += A[i][j] * x[j];
            }
        }

        lambda_new = fabs(y[0]);
        for(i = 1; i < n; i++) {
            if(fabs(y[i]) > lambda_new)
                lambda_new = fabs(y[i]);
        }

        for(i = 0; i < n; i++) {
            x[i] = y[i] / lambda_new;
        }

        printf("%d\t\t%f\n", k+1, lambda_new);

        error = fabs(lambda_new - lambda_old);
        if(error < 0.0001)
            break;

        lambda_old = lambda_new;
    }

    printf("\nDominant Eigenvalue = %f\n", lambda_new);
    printf("Corresponding Eigenvector:\n");
    for(i = 0; i < n; i++) {
        printf("%f\n", x[i]);
    }

    return 0;
}

