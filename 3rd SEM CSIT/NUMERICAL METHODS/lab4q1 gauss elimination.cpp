#include <stdio.h>
#include <math.h>
#define MAX 10

int main() {
    int i, j, k, n;
    float a[MAX][MAX], x[MAX], ratio;

    printf("=====Swornim Maharjan=====\n");
    printf("=== Gauss Elimination Method ===\n");
    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    for(i = 0; i < n-1; i++) {
        if(a[i][i] == 0.0) {
            printf("Error!\n");
            return 0;
        }

        for(j = i+1; j < n; j++) {
            ratio = a[j][i] / a[i][i];

            for(k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }


    x[n-1] = a[n-1][n] / a[n-1][n-1];

    for(i = n-2; i >= 0; i--) {
        x[i] = a[i][n];

        for(j = i+1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, x[i]);
    }

    return 0;
}

