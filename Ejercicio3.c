#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 5

int encontrar_diagonal_mas_larga(int matriz[TAMANO][TAMANO]) {
    int max = 0;
    int actual = 0;
    
    for (int d = 0; d < 2 * TAMANO - 1; d++) {
        int i = d < TAMANO ? 0 : d - TAMANO + 1;
        int j = d < TAMANO ? d : TAMANO - 1;
        
        while (i < TAMANO && j >= 0) {
            if (matriz[i][j] == 1) {
                actual++;
                if (actual > max) max = actual;
            } else {
                actual = 0;
            }
            i++;
            j--;
        }
        actual = 0;
    }
    return max;
}

void llenar_matriz_aleatoria(int matriz[TAMANO][TAMANO]) {
    srand(time(NULL));
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
}

void imprimir_matriz(int matriz[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[TAMANO][TAMANO];
    
    llenar_matriz_aleatoria(matriz);
    
    printf("Matriz:\n");
    imprimir_matriz(matriz);
    
    int resultado = encontrar_diagonal_mas_larga(matriz);
    printf("\nLa secuencia de 1s mas larga es: %d\n", resultado);
    
    return 0;
}