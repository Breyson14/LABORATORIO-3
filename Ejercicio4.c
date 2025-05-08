#include <stdio.h>

void imprimirBinario(int n) {
    if (n > 1) {
        imprimirBinario(n / 2);  
    }
    printf("%d", n % 2); 
}

int main() {
    int n;
    
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Error: El número debe ser positivo.\n");
        return 1;
    }
    
    printf("La representación binaria de %d es: ", n);
    imprimirBinario(n);
    printf("\n");
    
    return 0;
}