#include <stdio.h>

int main() {
    int matriz[] = {1, 2, 3, 3, 4,
                    4, 5, 6, 5, 2,
                    7, 8, 9, 6, 5,
                    4, 5, 2, 5, 1,
                    3, 6, 1, 6, 8};
    
    int x = sizeof(matriz) / sizeof(matriz[0]);
    int n = 0;
    while (n * n < x) n++;
    
    if (n * n != x) {
        printf("Error: La matriz debe ser cuadrada \n");
        return 1;
    }
    
    printf("\n MATRIZ INGRESADA %dx%d \n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matriz[i * n + j]);
        }
        printf("\n");
    }

    printf("\n DIAGONALES SECUNDARIAS \n");
    for (int d = 0; d < 2 * n - 1; d++) {
        int suma = 0;
        int y = 1;
        
        for (int i = 0; i < n; i++) {
            int j = d - i;
            if (j >= 0 && j < n) {
                if (!y) printf(" + ");
                printf("%d", matriz[i * n + j]);
                suma += matriz[i * n + j];
                y = 0;
            }
        }
        printf(" = %d\n", suma);
    }
    
    printf("\n DIAGONALES PRINCIPALES \n");
    for (int d = 0; d < 2 * n - 1; d++) {
        int suma = 0;
        int y = 1;
        
        for (int i = 0; i < n; i++) {
            int j = n - 1 - d + i;
            if (j >= 0 && j < n) {
                if (!y) printf(" + ");
                printf("%d", matriz[i * n + j]);
                suma += matriz[i * n + j];
                y = 0;
            }
        }
        printf(" = %d\n", suma);
    }
    
    return 0;
}
