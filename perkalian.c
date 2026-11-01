#include <stdio.h>
#include <stdlib.h>

void matrix_vector(int *a, int *b, int *c, int n) {
    for(int i=0; i<n; i++) {
        c[i] = 0;
        for(int j=0; j<n; j++) {
            c[i] += a[i*n+j] * b[j];
        }
    }
}

int main() {
    int n = 4;
    int a[4][4], b[4], c[4];

    printf("Masukkan Matriks A (4x4):\n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMasukkan Vektor B (4x1):\n");

    for(int i=0; i<n; i++) {
        printf("B[%d] = ", i+1);
        scanf("%d", &b[i]);
    }

    matrix_vector(&a[0][0], b, c, n);

    printf("\nMatriks A:\n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nVektor B:\n");

    for(int i=0; i<n; i++) {
        printf("%4d\n", b[i]);
    }

    printf("\nHasil Perkalian (4x1):\n");

    for(int i=0; i<n; i++) {
        printf("%4d\n", c[i]);
    }

    return 0;
}