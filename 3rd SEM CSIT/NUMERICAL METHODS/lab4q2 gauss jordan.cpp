
#include <stdio.h>
#include <math.h>
#define MAX 10

int main() {
    int i, j, k, n;
    float a[MAX][MAX];

    printf("=====Swornim Maharjan=====\n");
    printf("=== Gauss-Jordan Method ===\n");
    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        if(a[i][i] == 0.0) {
            printf("Error!\n");
            return 0;
        }

        float pivot = a[i][i];
        for(j = 0; j <= n; j++) {
            a[i][j] = a[i][j] / pivot;
        }
        
        for(k=0;k<n;k++){
        	if(k!=i){
        		float ratio =a[k][i];
        		for(j=0;j<=n;j++){
        			a[k][j] = a[k][j] - ratio * a[i][j];
				}
			}
		}
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i+1, a[i][n]);
    }

    return 0;
}


